

#include <LabyrinthOfLore/Gameplay/Gameplay.hpp>



using AllegroFlare::radians_to_degrees;
using AllegroFlare::Random;



#include <iostream>
using namespace std;

static void capitalize (string &s)
{
   if (s.empty()) return;

    bool cap = true;

    for(unsigned int i = 0; i <= 1; i++)
    {
        if (isalpha(s[i]) && cap == true)
        {
            s[i] = toupper(s[i]);
            cap = false;
        }
        else if (isspace(s[i]))
        {
            cap = true;
        }
    }
}


//const int DISPLAY_WIDTH = 1920;
//const int DISPLAY_HEIGHT = 1080;
//float resolution_scale = 3.0f;
//AllegroFlare::PickingBuffer picking_buffer(DISPLAY_WIDTH/resolution_scale, DISPLAY_HEIGHT/resolution_scale, 32);


class System
{
public:
   const int DISPLAY_WIDTH = 1920;
   const int DISPLAY_HEIGHT = 1080;
   AllegroFlare::FontBin font_bin;
   AllegroFlare::BitmapBin bitmap_bin;
   ALLEGRO_EVENT_QUEUE *event_queue;
   ALLEGRO_DISPLAY *display;
   bool shutdown_program;

   System()
      : font_bin()
      , bitmap_bin()
      , display(nullptr)
      , shutdown_program(false)
   {
   }
   ~System()
   {
   }

   void initialize()
   {
      al_init();
      al_init_font_addon();
      al_init_ttf_addon();
      al_init_image_addon();
      al_init_primitives_addon();

      ALLEGRO_PATH *resource_path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
      al_change_directory(al_path_cstr(resource_path, ALLEGRO_NATIVE_PATH_SEP));
      al_destroy_path(resource_path);




      // set a few options and flags
      al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 2, ALLEGRO_SUGGEST);
      al_set_new_display_option(ALLEGRO_DEPTH_SIZE, 32, ALLEGRO_SUGGEST);
      //al_set_new_display_option(ALLEGRO_SAMPLES, 16, ALLEGRO_SUGGEST);
      //al_set_new_display_flags(ALLEGRO_RESIZABLE | ALLEGRO_OPENGL | ALLEGRO_PROGRAMMABLE_PIPELINE);
      al_set_new_display_flags(ALLEGRO_OPENGL | ALLEGRO_PROGRAMMABLE_PIPELINE);
      //al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW | ALLEGRO_OPENGL | ALLEGRO_PROGRAMMABLE_PIPELINE);


      display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);


      event_queue = al_create_event_queue();

      al_install_keyboard();
      al_register_event_source(event_queue, al_get_keyboard_event_source());

      al_install_mouse();
      al_register_event_source(event_queue, al_get_mouse_event_source());

      ALLEGRO_TIMER *primary_timer = al_create_timer(1.0/60.0);
      al_register_event_source(event_queue, al_get_timer_event_source(primary_timer));
      al_start_timer(primary_timer);


      font_bin.set_path("data/fonts");
      bitmap_bin.set_path("data/bitmaps");

      //picking_buffer.initialize();

      // preload the logo

      //bitmap_bin.get("logo-fo-sho.png");
   }
};




bool development_mode = true;
#define THING_ID_ATTRIBUTE ("thing_id")
#define CAN_BE_PICKED_UP_ATTRIBUTE ("can_be_picked_up")
#define MUST_BE_PICKED_UP_TO_BE_USED ("must_be_picked_up_to_be_used")
#define DESTROY_THIS_ITEM_AT_CLEANUP ("destroy_this_item_at_cleanup")
std::string current_level_identifier = LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER;





void move_player_to_level(
      LabyrinthOfLore::Entity::Base* player_entity,
      std::map<std::string, LabyrinthOfLore::WorldMap::Level> &levels,
      std::map<std::string, LabyrinthOfLore::Rendering::TileMapMesh> &meshes,
      std::map<std::string, LabyrinthOfLore::Rendering::TileMapWaterMesh> &water_meshes,
      std::string level_identifier,
      AllegroFlare::vec3d spawn_point,
      LabyrinthOfLore::WorldMap::TileMap &current_tile_map,
      LabyrinthOfLore::Rendering::TileMapMesh &current_tile_map_mesh,
      LabyrinthOfLore::Rendering::TileMapWaterMesh &current_tile_map_water_mesh
   )
{
   current_tile_map = levels[level_identifier].get_tile_map();
   current_tile_map_mesh = meshes[level_identifier];
   current_tile_map_water_mesh = water_meshes[level_identifier];

   // set the player's position
   player_entity->set_identifier_for_level_within(level_identifier);
   player_entity->get_placement_ref().position = spawn_point;

   // reset the players's velocity - so no funny stuff, ok buddy? ;)
   player_entity->get_velocity_ref().position = AllegroFlare::vec3d(0.0, 0.0, 0.0);

   current_level_identifier = level_identifier;
}



void set_title_text(LabyrinthOfLore::Hud::TitleText &title_text, std::string top_text, std::string headline_text)
{
   title_text.set(top_text, headline_text, al_get_time());
};


void go_into_door(
      LabyrinthOfLore::WorldMap::Door door,
      LabyrinthOfLore::Entity::Base* player_entity,
      std::map<std::string, LabyrinthOfLore::WorldMap::Level> &levels,
      std::map<std::string, LabyrinthOfLore::Rendering::TileMapMesh> &meshes,
      std::map<std::string, LabyrinthOfLore::Rendering::TileMapWaterMesh> &water_meshes,
      float &player_yaw,
      LabyrinthOfLore::WorldMap::TileMap &current_tile_map,
      LabyrinthOfLore::Rendering::TileMapMesh &current_tile_map_mesh,
      LabyrinthOfLore::Rendering::TileMapWaterMesh &current_tile_map_water_mesh,
      LabyrinthOfLore::Hud::TitleText &title_text
   )
{
   move_player_to_level(
      player_entity,
      levels,
      meshes,
      water_meshes,
      door.get_level_identifier(),
      AllegroFlare::vec3d(door.get_spawn_x(), door.get_spawn_y(), door.get_spawn_z()),
      current_tile_map,
      current_tile_map_mesh,
      current_tile_map_water_mesh
   );

   set_title_text(
      title_text,
      levels[door.get_level_identifier()].get_heading(),
      levels[door.get_level_identifier()].get_name()
   );

   player_yaw = door.get_spawn_facing_yaw();
}



void process_cheat_keyboard_keydown_event(
      ALLEGRO_EVENT &this_event,
      AllegroFlare::Inventory &player_inventory
      //LabyInventory &player_inventory
   )
{
   bool shift = this_event.keyboard.modifiers & ALLEGRO_KEYMOD_SHIFT;

   if (!shift) return;

   if (this_event.keyboard.keycode == ALLEGRO_KEY_R) player_inventory.add_item(ITEM_RING_OF_LOFT_ID);
}



//void equip_item(int item_id, LabyrinthOfLore::Entity::Base *player_entity)
//{
   //if (item_id == ITEM_RING_OF_LOFT_ID) player->set("loft");
//}



//void unequip_item(int item_id, LabyrinthOfLore::Entity::Base *player_entity)
//{
   //if (item_id == ITEM_RING_OF_LOFT_ID) player->remove("loft");
//}


void flag_for_destruction(LabyrinthOfLore::Entity::Base *entity)
{
   entity->set(LabyrinthOfLore::Entity::Cleanup::get_CLEANUP_FLAG());
}



void cleanup_all_entities_flagged_for_destruction(std::vector<LabyrinthOfLore::Entity::Base *> &all_entities)
{
   LabyrinthOfLore::Entity::Cleanup cleanup(&all_entities);
   cleanup.cleanup();
}



std::string you_see_a(LabyrinthOfLore::Entity::ThingDefinition &thing_definition)
{
    std::stringstream message;
    message << "You see " << thing_definition.infer_decorated_name() << ".";
    return message.str();
}



std::string you_cannot_pick_up(LabyrinthOfLore::Entity::ThingDefinition &thing_definition)
{
    std::stringstream message;
    message << "You cannot pick up the " << thing_definition.get_name() << ".";
    return message.str();
}



std::string you_cannot_pick_up__because_you_cannot_carray_this_more_weight(LabyrinthOfLore::Entity::ThingDefinition &thing_definition)
{
    std::stringstream message;
    message << "You cannot pick up the " << thing_definition.get_name() << " because you cannot carry this much more weight.";
    return message.str();
}



std::string you_cannot_pick_up__because_you_cannot_carray_any_more_weight(LabyrinthOfLore::Entity::ThingDefinition &thing_definition)
{
    std::stringstream message;
    message << "You cannot pick up the " << thing_definition.get_name() << " because you cannot carry any more weight.";
    return message.str();
}



std::string you_picked_up(LabyrinthOfLore::Entity::ThingDefinition &thing_definition)
{
    std::stringstream message;
    message << "You picked up " << thing_definition.infer_decorated_name() << ".";
    return message.str();
}



std::string you_must_pickup_this_item_to_use_it(LabyrinthOfLore::Entity::ThingDefinition &thing_definition)
{
    std::stringstream message;
    message << "You must pick up " << thing_definition.infer_decorated_name() << " to use it.";
    return message.str();
}



std::string this_cannot_be_used(LabyrinthOfLore::Entity::ThingDefinition &thing_definition)
{
    std::stringstream message;
    message << thing_definition.infer_decorated_name() << " cannot be used.";

    std::string str_needs_capitalization = message.str();
    capitalize(str_needs_capitalization);
    return str_needs_capitalization;
}


std::string _does_not_want_to_talk(LabyrinthOfLore::Entity::ThingDefinition &thing_definition)
{
    std::stringstream message;
    message << thing_definition.infer_decorated_name() << " does not want to talk.";

    std::string str_needs_capitalization = message.str();
    capitalize(str_needs_capitalization);
    return str_needs_capitalization;
}


std::string you_killed_(LabyrinthOfLore::Entity::ThingDefinition &thing_definition)
{
    std::stringstream message;
    message << "You killed " << thing_definition.get_name() << ".";

    std::string str_needs_capitalization = message.str();
    capitalize(str_needs_capitalization);
    return str_needs_capitalization;
}



void process_thing_look_click(
      int thing_id,
      LabyrinthOfLore::Entity::ThingDictionary &thing_dictionary,
      LabyrinthOfLore::Hud::MessageScroll &message_scroll
      )
{
   LabyrinthOfLore::Entity::ThingDefinition &thing_definition = thing_dictionary.find_definition_ref(thing_id);

   // for custom messages:
   //if (thing_id == MAN_AT_THE_ENTRANCE_TO_THE_CAVE)
   if (thing_id == -1) // do this pattern for custom messages
   {
   }
   else // else will use the default messaging
   {
      message_scroll.append_message(al_get_time(), you_see_a(thing_definition));
   }
}



void process_thing_pickup_click(
      std::vector<LabyrinthOfLore::Entity::Base *> &all_entities,
      LabyrinthOfLore::Entity::Base *entity,
      //int thing_id,
      LabyrinthOfLore::Entity::ThingDictionary &thing_dictionary,
      LabyrinthOfLore::Hud::MessageScroll &message_scroll,
      LabyrinthOfLore::Hud::CharacterPanel &character_panel,
      AllegroFlare::Inventory &player_inventory
      )
{
   if (!entity) throw std::runtime_error("Cannot process_thing_pickup_click with a nullptr entity");
   if (!entity->exists(THING_ID_ATTRIBUTE)) throw std::runtime_error("Cannot process_thing_pickup_click expecting the entity to have a \"thing_id\" but it does not.");

   int thing_id = entity->get_as_int(THING_ID_ATTRIBUTE);

   LabyrinthOfLore::Entity::ThingDefinition &this_thing_definition = thing_dictionary.find_definition_ref(thing_id);


   if (entity->exists(CAN_BE_PICKED_UP_ATTRIBUTE))
   {
      int item_weight = this_thing_definition.get_weight();
      if (character_panel.calculate_available_remaining_carry_weight() == 0) message_scroll.append_message(al_get_time(), you_cannot_pick_up__because_you_cannot_carray_any_more_weight(this_thing_definition));
      else if (item_weight > character_panel.calculate_available_remaining_carry_weight()) message_scroll.append_message(al_get_time(), you_cannot_pick_up__because_you_cannot_carray_this_more_weight(this_thing_definition));
      else
      {
         player_inventory.add_item(thing_id);
         flag_for_destruction(entity); // important! entity is being flagged for destruction here, it will be garbage collected later, in a pass at the end of this immediate event loop event
         message_scroll.append_message(al_get_time(), you_picked_up(this_thing_definition));
      }

      // add the item to the player's inventory!!!!!!!!!UFUFUFUSDKUUKKYEAAA!!! :D :D
      //message_scroll.append_message(al_get_time(), you_picked_up(this_thing_definition));
   }
   else if (!entity->exists(CAN_BE_PICKED_UP_ATTRIBUTE))
   {
      message_scroll.append_message(al_get_time(), you_cannot_pick_up(this_thing_definition));
   }

   //LabyrinthOfLore::Entity::ThingDefinition &thing_definition = thing_dictionary.find_definition_ref(entith->exists);

   // for custom messages:
   //if (thing_id == MAN_AT_THE_ENTRANCE_TO_THE_CAVE)
   //if (thing_id == -1) // do this pattern for custom messages
   //{
   //}
   //else // else will use the default messaging
   //{
      ////if () { message_scroll.append_message(al_get_time(), you_see_a(thing_definition)) };
//
      ////message_scroll.append_message(al_get_time(), you_see_a(thing_definition));
   //}
}



void process_thing_use_click(
      std::vector<LabyrinthOfLore::Entity::Base *> &all_entities,
      LabyrinthOfLore::Entity::Base *entity,
      //int thing_id,
      LabyrinthOfLore::Entity::ThingDictionary &thing_dictionary,
      LabyrinthOfLore::Hud::MessageScroll &message_scroll,
      LabyrinthOfLore::Hud::CharacterPanel &character_panel,
      AllegroFlare::Inventory &player_inventory
      )
{
   if (!entity) throw std::runtime_error("Cannot process_thing_use_click with a nullptr entity");
   if (!entity->exists(THING_ID_ATTRIBUTE)) throw std::runtime_error("Cannot process_thing_use_click expecting the entity to have a \"thing_id\" but it does not.");

   int thing_id = entity->get_as_int(THING_ID_ATTRIBUTE);

   LabyrinthOfLore::Entity::ThingDefinition &this_thing_definition = thing_dictionary.find_definition_ref(thing_id);


   if (entity->exists(MUST_BE_PICKED_UP_TO_BE_USED))
   {
      message_scroll.append_message(al_get_time(), you_must_pickup_this_item_to_use_it(this_thing_definition));
   }
   else
   {
      message_scroll.append_message(al_get_time(), this_cannot_be_used(this_thing_definition));
   }
}



void process_thing_attack_click(
      std::vector<LabyrinthOfLore::Entity::Base *> &all_entities,
      LabyrinthOfLore::Entity::Base *entity,
      //int thing_id,
      LabyrinthOfLore::Entity::ThingDictionary &thing_dictionary,
      LabyrinthOfLore::Hud::MessageScroll &message_scroll,
      LabyrinthOfLore::Hud::CharacterPanel &character_panel,
      AllegroFlare::Inventory &player_inventory
      )
{
   if (!entity) throw std::runtime_error("Cannot process_thing_attack_click with a nullptr entity");
   if (!entity->exists(THING_ID_ATTRIBUTE)) throw std::runtime_error("Cannot process_thing_attack_click expecting the entity to have a \"thing_id\" but it does not.");

   int thing_id = entity->get_as_int(THING_ID_ATTRIBUTE);

   LabyrinthOfLore::Entity::ThingDefinition &this_thing_definition = thing_dictionary.find_definition_ref(thing_id);


   bool thing_can_be_attacked = true;


   if (thing_can_be_attacked)
   {
      int result_strength_of_item_being_attacked = this_thing_definition.get_health() - character_panel.calculate_attack_strength();
      this_thing_definition.set_health(result_strength_of_item_being_attacked);

      if (this_thing_definition.infer_is_dead())
      {
         this_thing_definition.set_health(result_strength_of_item_being_attacked);
         flag_for_destruction(entity);
         message_scroll.append_message(al_get_time(), you_killed_(this_thing_definition));
      }
   }


   //if (entity->exists(MUST_BE_PICKED_UP_TO_BE_USED))
   //{
      ////message_scroll.append_message(al_get_time(), you_must_pickup_this_item_to_use_it(this_thing_definition));
   //}
   //else
   //{
      //message_scroll.append_message(al_get_time(), this_cannot_be_used(this_thing_definition));
   //}
}



void process_click_event(
      float player_mouse_x,
      float player_mouse_y,
      AllegroFlare::PickingBuffer &picking_buffer,
      float resolution_scale,
      std::vector<LabyrinthOfLore::Entity::Base *> &all_entities,
      LabyrinthOfLore::Entity::ThingDictionary &thing_dictionary,
      LabyrinthOfLoreGame::ThingDefinitionFactory &thing_definition_factory,
      LabyrinthOfLore::Hud::MessageScroll &message_scroll,
      LabyrinthOfLore::Hud::CommandPanel &command_panel,
      LabyrinthOfLore::Hud::CharacterPanel &character_panel,
      AllegroFlare::Inventory &player_inventory
   )
{
   int picked_id = picking_buffer.get_id(player_mouse_x/resolution_scale, player_mouse_y/resolution_scale);
   //std::cout << "Picked ID: " << picked_id << std::endl;
         // observe clicked item, emit game events if needed 

   // HERE
   //all_entities

   //if (
   if (picked_id == 0)
   {
      if (command_panel.get_current_mode() == LabyrinthOfLore::Hud::COMMAND_MODE_LOOK) message_scroll.append_message(al_get_time(), "You see nothing of interest.");
      if (command_panel.get_current_mode() == LabyrinthOfLore::Hud::COMMAND_MODE_PICKUP) message_scroll.append_message(al_get_time(), "There is nothing for you to pick up.");
      if (command_panel.get_current_mode() == LabyrinthOfLore::Hud::COMMAND_MODE_USE) message_scroll.append_message(al_get_time(), "You must have an item if you want to use one.");
      if (command_panel.get_current_mode() == LabyrinthOfLore::Hud::COMMAND_MODE_TALK) message_scroll.append_message(al_get_time(), "There is no one to talk to.");
   }
   else
   {
      int thing_id = -1;
      LabyrinthOfLore::Entity::Base *this_entity = nullptr;
      for (auto &entity : all_entities)
      {
         if (entity->get_id() == picked_id)
         {
            this_entity = entity;
            thing_id = entity->get_as_int(THING_ID_ATTRIBUTE);
            break;
         }
      }

      if (this_entity == nullptr || thing_id == -1)
      {
         throw std::runtime_error("attempted to extract thing_id from a picked entity_id, but the picked entity either did not exist, or did not have a \"thing_id\" attribute, which should never happen.");
      }
      else
      {
         if (command_panel.get_current_mode() == LabyrinthOfLore::Hud::COMMAND_MODE_LOOK)
         {
            process_thing_look_click(
                  thing_id,
                  thing_dictionary,
                  message_scroll
               );
         }
         else if (command_panel.get_current_mode() == LabyrinthOfLore::Hud::COMMAND_MODE_PICKUP)
         {
            process_thing_pickup_click(
                  all_entities,
                  this_entity,
                  thing_dictionary,
                  message_scroll,
                  character_panel,
                  player_inventory
               );
         }
         else if (command_panel.get_current_mode() == LabyrinthOfLore::Hud::COMMAND_MODE_USE)
         {
            process_thing_use_click(
                  all_entities,
                  this_entity,
                  thing_dictionary,
                  message_scroll,
                  character_panel,
                  player_inventory
               );
         }
         else if (command_panel.get_current_mode() == LabyrinthOfLore::Hud::COMMAND_MODE_ATTACK)
         {
            process_thing_attack_click(
                  all_entities,
                  this_entity,
                  thing_dictionary,
                  message_scroll,
                  character_panel,
                  player_inventory
               );
         }
         else if (command_panel.get_current_mode() == LabyrinthOfLore::Hud::COMMAND_MODE_TALK)
         {
            if (!this_entity) throw std::runtime_error("Cannot process_thing_talk_click with a nullptr entity");
            if (!this_entity->exists(THING_ID_ATTRIBUTE)) throw std::runtime_error("Cannot process_thing_talk_click expecting the this_entity to have a \"thing_id\" but it does not.");
            int thing_id = this_entity->get_as_int(THING_ID_ATTRIBUTE);

            LabyrinthOfLoreGame::Interactions interactions(
                  &thing_definition_factory,
                  &all_entities,
                  &thing_dictionary,
                  &message_scroll,
                  &character_panel,
                  &player_inventory,
                  al_get_time()
                  );

            interactions.validate_arguments();

            interactions.process_talk(thing_id);
         }
      }
   }
}



void set_command_mode(LabyrinthOfLore::Hud::CommandPanel &command_panel, LabyrinthOfLore::Hud::command_mode_t new_command_mode)
{
    command_panel.set_current_mode(new_command_mode);
}



void process_keyboard_keydown_event(
      ALLEGRO_EVENT &this_event,
      std::map<char, LabyrinthOfLore::WorldMap::Door> doors,
      LabyrinthOfLore::Entity::Base* player_entity,
      std::map<std::string, LabyrinthOfLore::WorldMap::Level> &levels,
      std::map<std::string, LabyrinthOfLore::Rendering::TileMapMesh> &meshes,
      std::map<std::string, LabyrinthOfLore::Rendering::TileMapWaterMesh> &water_meshes,
      float &player_yaw,
      LabyrinthOfLore::WorldMap::TileMap &current_tile_map,
      LabyrinthOfLore::Rendering::TileMapMesh &current_tile_map_mesh,
      LabyrinthOfLore::Rendering::TileMapWaterMesh &current_tile_map_water_mesh,
      LabyrinthOfLore::Hud::TitleText &title_text,
      LabyrinthOfLore::Hud::CommandPanel &command_panel
   )
{
   if (development_mode)
   {
      if (this_event.keyboard.keycode == ALLEGRO_KEY_0)
         go_into_door(doors.at(10), player_entity, levels, meshes, water_meshes, player_yaw, current_tile_map, current_tile_map_mesh, current_tile_map_water_mesh, title_text);
      else if (this_event.keyboard.keycode == ALLEGRO_KEY_1)
         go_into_door(doors.at(1), player_entity, levels, meshes, water_meshes, player_yaw, current_tile_map, current_tile_map_mesh, current_tile_map_water_mesh, title_text);
      else if (this_event.keyboard.keycode == ALLEGRO_KEY_2)
         go_into_door(doors.at(3), player_entity, levels, meshes, water_meshes, player_yaw, current_tile_map, current_tile_map_mesh, current_tile_map_water_mesh, title_text);
      else if (this_event.keyboard.keycode == ALLEGRO_KEY_3)
         go_into_door(doors.at(2), player_entity, levels, meshes, water_meshes, player_yaw, current_tile_map, current_tile_map_mesh, current_tile_map_water_mesh, title_text);
      else if (this_event.keyboard.keycode == ALLEGRO_KEY_4)
         go_into_door(doors.at(4), player_entity, levels, meshes, water_meshes, player_yaw, current_tile_map, current_tile_map_mesh, current_tile_map_water_mesh, title_text);
      else if (this_event.keyboard.keycode == ALLEGRO_KEY_5)
         go_into_door(doors.at(5), player_entity, levels, meshes, water_meshes, player_yaw, current_tile_map, current_tile_map_mesh, current_tile_map_water_mesh, title_text);
      else if (this_event.keyboard.keycode == ALLEGRO_KEY_6)
         go_into_door(doors.at(6), player_entity, levels, meshes, water_meshes, player_yaw, current_tile_map, current_tile_map_mesh, current_tile_map_water_mesh, title_text);
      else if (this_event.keyboard.keycode == ALLEGRO_KEY_7)
         go_into_door(doors.at(7), player_entity, levels, meshes, water_meshes, player_yaw, current_tile_map, current_tile_map_mesh, current_tile_map_water_mesh, title_text);
   }


   if (this_event.keyboard.keycode == ALLEGRO_KEY_T) set_command_mode(command_panel, LabyrinthOfLore::Hud::COMMAND_MODE_TALK);
   if (this_event.keyboard.keycode == ALLEGRO_KEY_P) set_command_mode(command_panel, LabyrinthOfLore::Hud::COMMAND_MODE_PICKUP);
   if (this_event.keyboard.keycode == ALLEGRO_KEY_L) set_command_mode(command_panel, LabyrinthOfLore::Hud::COMMAND_MODE_LOOK);
   if (this_event.keyboard.keycode == ALLEGRO_KEY_K || this_event.keyboard.keycode == ALLEGRO_KEY_Z) set_command_mode(command_panel, LabyrinthOfLore::Hud::COMMAND_MODE_ATTACK);
   if (this_event.keyboard.keycode == ALLEGRO_KEY_U) set_command_mode(command_panel, LabyrinthOfLore::Hud::COMMAND_MODE_USE);
}


void process_post_gravity_effects(
      std::vector<LabyrinthOfLore::Entity::Base*> &entities_in_the_current_level
   )
{
   for (auto &entity : entities_in_the_current_level)
   {
      //if (entity->exists("loft")) entity->get_velocity_ref().position.z = -0.25 / 60.0f;
      // THIS IS LOFT:
      entity->get_velocity_ref().position.z = std::max(entity->get_velocity_ref().position.z, -0.25f / 60.0f);

      // THIS IS levitation:
      entity->get_velocity_ref().position.z = 0;
   }
}


void process_collision_stepper_events(
      std::vector<LabyrinthOfLore::Physics::EntityTileMapCollisionEvent> &collision_stepper_events,
      LabyrinthOfLore::Entity::Base* player_entity,
      std::map<std::string, LabyrinthOfLore::WorldMap::Level> &levels,

      // dependencies for go_into_door
      std::map<char, LabyrinthOfLore::WorldMap::Door> doors,
      //LabyrinthOfLore::Entity::Base* player_entity,
      //std::map<std::string, LabyrinthOfLore::WorldMap::Level> &levels,
      std::map<std::string, LabyrinthOfLore::Rendering::TileMapMesh> &meshes,
      std::map<std::string, LabyrinthOfLore::Rendering::TileMapWaterMesh> &water_meshes,
      float &player_yaw,
      LabyrinthOfLore::WorldMap::TileMap &current_tile_map,
      LabyrinthOfLore::Rendering::TileMapMesh &current_tile_map_mesh,
      LabyrinthOfLore::Rendering::TileMapWaterMesh &current_tile_map_water_mesh,
      LabyrinthOfLore::Hud::TitleText &title_text

   )
{
   for (auto &collision_stepper_event : collision_stepper_events)
   {
      if (collision_stepper_event.get_entity() == player_entity)
      {
         int tile_x = collision_stepper_event.get_tile_x();
         int tile_y = collision_stepper_event.get_tile_y();

                               //level_identifier_str, tile_x, tile_y, door_number_to_enter
         std::vector<std::tuple<std::string, int, int, int>> door_datas = {
            { LabyrinthOfLoreGame::LevelIdentifiers::THE_CAVE_IDENTIFIER, 32, 14, 11 },
            { LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER, 56, 24, 1 },

            { LabyrinthOfLoreGame::LevelIdentifiers::AN_ABANDONED_TEMPLE_IDENTIFIER, 19, 43, 12 },
            { LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER, 42, 44, 2 },

            { LabyrinthOfLoreGame::LevelIdentifiers::DUNGEON_OF_THE_CURSED_IDENTIFIER, 1, 24, 13 },
            { LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER, 72, 92, 3 },

            { LabyrinthOfLoreGame::LevelIdentifiers::TEMPLE_OF_WATER_IDENTIFIER, 55, 58, 14 },
            { LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER, 25, 20, 4 },

            { LabyrinthOfLoreGame::LevelIdentifiers::WORLD_OF_FIRE_IDENTIFIER, 19, 58, 15 },
            { LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER, 103, 1, 5 },

            { LabyrinthOfLoreGame::LevelIdentifiers::FINAL_TEMPLE_IDENTIFIER, 39, 57, 16 },
            { LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER, 40, 30, 6 },

            { LabyrinthOfLoreGame::LevelIdentifiers::VILLAGE_OF_THE_FORGOTTEN_IDENTIFIER, 29, 30, 17 },
            { LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER, 23, 55, 7 },
         };

         for (auto door_data : door_datas)
         {
            if (current_level_identifier == std::get<0>(door_data) && tile_x == std::get<1>(door_data) && tile_y == std::get<2>(door_data))
            {
               go_into_door(doors.at(std::get<3>(door_data)), player_entity, levels, meshes, water_meshes, player_yaw, current_tile_map, current_tile_map_mesh, current_tile_map_water_mesh, title_text);
            }
         }
         // the player encountered a new collision
      }
   }
   //entity_tile_map_collision_stepper.get_events_from_last_processed_step();
   //title_text.set(top_text, headline_text, al_get_time());
};





void add_thing_to_world(
      std::vector<LabyrinthOfLore::Entity::Base*> *all_entities,
      LabyrinthOfLore::Entity::ThingDictionary *thing_dictionary,
      int thing_id,
      std::string level_identifier,
      AllegroFlare::vec3d position,
      bool billboard_at_camera=true,
      bool can_be_picked_up=true,
      bool must_be_picked_up_to_be_used=false // this here

   )
{
   //if (!all_entities) throw std::runtime_error("cannot add_thing_to_world with a nullptr all_entities"); 

   LabyrinthOfLore::Entity::ThingDefinition thing_definition = thing_dictionary->find_definition(thing_id);
   Tileo::TileAtlas *this_things_tile_atlas = thing_definition.get_tile_atlas();
   if (!this_things_tile_atlas) throw std::runtime_error("cannot add_thing_to_world with a nullptr this_things_tile_atlas on the thing_definition"); 

   ALLEGRO_BITMAP *bitmap = this_things_tile_atlas->get_bitmap(thing_definition.get_tile_atlas_index_id());
   LabyrinthOfLore::Entity::Base* entity = new LabyrinthOfLore::Entity::Base;

   entity->set_billboard_at_camera(billboard_at_camera);
   entity->set_bitmap(bitmap);
   entity->set_identifier_for_level_within(level_identifier);

   entity->set(THING_ID_ATTRIBUTE, thing_id);
   if (can_be_picked_up) entity->set(CAN_BE_PICKED_UP_ATTRIBUTE);
   if (must_be_picked_up_to_be_used) entity->set(MUST_BE_PICKED_UP_TO_BE_USED);

   entity->get_placement_ref().size = AllegroFlare::vec3d(al_get_bitmap_width(bitmap), al_get_bitmap_height(bitmap), 0.0);
   entity->get_placement_ref().size = AllegroFlare::vec3d(al_get_bitmap_width(bitmap), al_get_bitmap_height(bitmap), 0.0);
   entity->get_placement_ref().scale = AllegroFlare::vec3d(0.005*4, 0.005*4, 0.005*4);
   entity->get_placement_ref().align = AllegroFlare::vec3d(0.5, 1.0, 0.0);
   entity->get_placement_ref().position = position; //AllegroFlare::vec3d(x + 0.5, y + 0.5, 3.01);
   ////entity->get_placement_ref().rotation = AllegroFlare::vec3d(0, random.get_random_float(-1, 1), 0);

   all_entities->push_back(entity);
}






ALLEGRO_BITMAP *create_scene_rendering_surface(int width, int height)
{
   int previous_depth = al_get_new_bitmap_depth();
   int previous_samples = al_get_new_bitmap_samples();
   ALLEGRO_STATE previous_state;
   al_store_state(&previous_state, ALLEGRO_STATE_BITMAP);

   al_set_new_bitmap_depth(32);
   al_set_new_bitmap_samples(0);
   //ALLEGRO_BITMAP *bmp = al_create_bitmap(w, h);

   ALLEGRO_BITMAP *buffer_buffer = al_create_bitmap(width, height);
   //ALLEGRO_BITMAP *buffer_buffer = al_get_backbuffer(display);

   al_restore_state(&previous_state);
   al_set_new_bitmap_depth(previous_depth);
   al_set_new_bitmap_samples(previous_samples);


   ALLEGRO_BITMAP *scene_rendering_surface = al_create_sub_bitmap(
         buffer_buffer,
         0,
         0,
         al_get_bitmap_width(buffer_buffer),
         al_get_bitmap_height(buffer_buffer)
      );

   return scene_rendering_surface;
}




//#include <LabyrinthOfLore/Gameplay/Screen.hpp>



namespace LabyrinthOfLore
{
namespace Gameplay
{



Gameplay::Gameplay()
   : bitmap_bin(nullptr)
   , font_bin(nullptr)
   , thing_definition_factory() // yet to be used
   , player_inventory()
   , message_scroll()
   , command_panel()
   , vitality_and_mana_bar()
   , character_panel()
   , map_button()
   , rune_shelf()
   , compass()
   , rotate_character_panel_button()
   , commands_hint_pane()
   , current_spells()
   , veiw_frame()
   , title_text()
   , current_tile_map()
   , current_tile_map_mesh()
   , current_tile_map_water_mesh()
   , classic_game() // This may be LabyrinthOfLore::Games::Base*
   , camera()
   , render_surface_width(0) // HERE
   , render_surface_height(0)
   , resolution_scale(3.0)
   , picking_buffer(0, 0, 32)
   , buffer_buffer(nullptr)
   , scene_rendering_surface(nullptr)
   , player_entity(nullptr)
   , player_yaw(0)
   , player_camera_ascent(0.65)
   , player_pitch(0.0)
   , player_turning(0.0)
   , max_player_turning_speed(0.0023)
   , player_movement_magnitude(0.0)
   , player_mouse_x(0)
   , player_mouse_y(0)
   , initialized(false)
{
}



void Gameplay::set_render_surface_width(int render_surface_width)
{
   if (initialized) throw std::runtime_error("[Lol::Gameplay::Gameplay::set_render_surface_width]: error: must be initialized");
   this->render_surface_width = render_surface_width;
}



void Gameplay::set_render_surface_height(int render_surface_height)
{
   if (initialized) throw std::runtime_error("[Lol::Gameplay::Gameplay::set_render_surface_height]: error: must be initialized");
   this->render_surface_height = render_surface_height;
}



void Gameplay::set_bitmap_bin(AllegroFlare::BitmapBin *bitmap_bin)
{
   if (initialized) throw std::runtime_error("[Lol::Gameplay::Gameplay::set_bitmap_bin]: error: must be initialized");
   this->bitmap_bin = bitmap_bin;
}



void Gameplay::set_font_bin(AllegroFlare::FontBin *font_bin)
{
   if (initialized) throw std::runtime_error("[Lol::Gameplay::Gameplay::set_font_bin]: error: must be initialized");
   this->font_bin = font_bin;
}



void Gameplay::initialize(ALLEGRO_DISPLAY *_display)
{
   if (initialized) throw std::runtime_error("[Lol::Gameplay::Gameplay::initialize]: error: cannot initialize twice");
   if (!bitmap_bin) throw std::runtime_error("[Lol::Gameplay::Gameplay::initialize]: error: bitmap_bin required");
   if (!font_bin) throw std::runtime_error("[Lol::Gameplay::Gameplay::initialize]: error: font_bin required");
   if (render_surface_width <= 0) throw std::runtime_error("[Lol::Gameplay::Gameplay::initialize]: error: You must set a render_surface_width");
   if (render_surface_height <= 0) throw std::runtime_error("[Lol::Gameplay::Gameplay::initialize]: error: You must set a render_surface_height");



   // Create rendering surfaces (unclear what these are needed for)

   int previous_depth = al_get_new_bitmap_depth();
   int previous_samples = al_get_new_bitmap_samples();
   ALLEGRO_STATE previous_state;
   al_store_state(&previous_state, ALLEGRO_STATE_BITMAP);

   al_set_new_bitmap_depth(32);
   al_set_new_bitmap_samples(0);
   //ALLEGRO_BITMAP *bmp = al_create_bitmap(w, h);

   buffer_buffer = al_create_bitmap(
      al_get_display_width(_display)/resolution_scale,
      al_get_display_height(_display)/resolution_scale
   );
   //ALLEGRO_BITMAP *buffer_buffer = al_get_backbuffer(display);

   al_restore_state(&previous_state);
   al_set_new_bitmap_depth(previous_depth);
   al_set_new_bitmap_samples(previous_samples);


   scene_rendering_surface = al_create_sub_bitmap(
         buffer_buffer,
         0,
         0,
         al_get_bitmap_width(buffer_buffer),
         al_get_bitmap_height(buffer_buffer)
      );
   if (!scene_rendering_surface) throw std::runtime_error("could not create scene_rendering_surface");


   // Init our other stuff

   picking_buffer.set_surface_width(render_surface_width/resolution_scale);
   picking_buffer.set_surface_height(render_surface_height/resolution_scale);
   picking_buffer.initialize();

   classic_game.set_bitmap_bin(bitmap_bin);
   classic_game.initialize();

   character_panel.set_player_inventory(&player_inventory);
   character_panel.set_thing_dictionary(&classic_game.get_thing_dictionary_ref());



   initialized = true;
}



void Gameplay::start_game()
{
   if (!initialized) throw std::runtime_error("[Lol::Gameplay::Gameplay::start_game]: error: must be initialized");


   message_scroll.clear_text();


    
   // Create the player
   player_entity = new LabyrinthOfLore::Entity::Base; // TODO: Destroy this player_entity on restart
   player_entity->get_velocity_ref().position = {0.0, 0.0, 0.0};
   player_entity->set_identifier_for_level_within(LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER);
   player_entity->get_placement_ref().position = {0.0, 0.0, 0.0};
   classic_game.get_all_entities_ref().push_back(player_entity);



   // Reset the controls
   player_mouse_x = 0;
   player_mouse_y = 0;


   go_into_door(
      classic_game.get_doors_ref().at(10),
      player_entity,
      classic_game.get_levels_ref(),
      classic_game.get_meshes_ref(),
      classic_game.get_water_meshes_ref(),
      player_yaw,
      current_tile_map,
      current_tile_map_mesh,
      current_tile_map_water_mesh,
      title_text
   );

}



void Gameplay::process_mouse_axes_event(ALLEGRO_EVENT &this_event)
{
         player_mouse_x = this_event.mouse.x;
         player_mouse_y = this_event.mouse.y;
         // observe mouse enter and mouse exit, emit game events if needed 
}



void Gameplay::process_mouse_button_down_event(ALLEGRO_EVENT &this_event)
{
         {
            player_mouse_x = this_event.mouse.x;
            player_mouse_y = this_event.mouse.y;

            process_click_event(
               player_mouse_x,
               player_mouse_y,
               picking_buffer,
               resolution_scale,
               classic_game.get_all_entities_ref(),
               classic_game.get_thing_dictionary_ref(),
               thing_definition_factory,
               message_scroll,
               command_panel,
               character_panel,
               player_inventory
            );

            //int picked_id = game.picking_buffer.get_id(player_mouse_x/resolution_scale, player_mouse_y/resolution_scale);
            //std::cout << "Picked ID: " << picked_id << std::endl;
            // observe clicked item, emit game events if needed 
            //break;
         }
}



void Gameplay::process_key_char_event(ALLEGRO_EVENT &this_event, bool &shutdown_program_flag)
{
         {
            bool shift = false;
            if (development_mode) shift = this_event.keyboard.modifiers & ALLEGRO_KEYMOD_SHIFT; /// DISABLE ON RELEASE

            if (this_event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) shutdown_program_flag = true;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_A) player_turning = shift ? 4*-max_player_turning_speed : -max_player_turning_speed;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_W) player_movement_magnitude = shift ? 0.1 : 0.022;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_D) player_turning = shift ? 4*max_player_turning_speed : max_player_turning_speed;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_S) player_movement_magnitude = shift ? -0.1 : -0.022;

            if (development_mode)
            {
               if (this_event.keyboard.keycode == ALLEGRO_KEY_Y) classic_game.get_depth_darken_shader_ref().set_torch_type(0); /// DISABLE ON RELEASE
               if (this_event.keyboard.keycode == ALLEGRO_KEY_H) classic_game.get_depth_darken_shader_ref().set_torch_type(1); /// DISABLE ON RELEASE
               if (this_event.keyboard.keycode == ALLEGRO_KEY_N) classic_game.get_depth_darken_shader_ref().set_torch_type(2); /// DISABLE ON RELEASE
            }

            process_cheat_keyboard_keydown_event(
               this_event,
               player_inventory
            );

            process_keyboard_keydown_event(
               this_event,
               classic_game.get_doors_ref(),
               player_entity,
               classic_game.get_levels_ref(),
               classic_game.get_meshes_ref(),
               classic_game.get_water_meshes_ref(),
               player_yaw,
               current_tile_map,
               current_tile_map_mesh,
               current_tile_map_water_mesh,
               title_text,
               command_panel
            );
         }
}



void Gameplay::process_key_up_event(ALLEGRO_EVENT &this_event)
{
         if (this_event.keyboard.keycode == ALLEGRO_KEY_A) player_turning = 0.0;
         if (this_event.keyboard.keycode == ALLEGRO_KEY_W) player_movement_magnitude = 0.0;
         if (this_event.keyboard.keycode == ALLEGRO_KEY_D) player_turning = 0.0;
         if (this_event.keyboard.keycode == ALLEGRO_KEY_S) player_movement_magnitude = 0.0;
}



void Gameplay::process_timer_event(ALLEGRO_EVENT &this_event, ALLEGRO_DISPLAY* _display)
{
         {
            player_yaw += player_turning;

            AllegroFlare::vec2d view_vector_2d = AllegroFlare::vec2d::polar_coords((player_yaw + 0.25) * ALLEGRO_PI*2, player_movement_magnitude);
            player_entity->get_velocity_ref().position.x = view_vector_2d.x; //view_vector_2d.x;
            player_entity->get_velocity_ref().position.y = view_vector_2d.y; //view_vector_2d.y;

            std::vector<LabyrinthOfLore::Entity::Base*> entities_in_the_current_level = LabyrinthOfLore::Entity::Selector(classic_game.get_all_entities_ref()).select_within_level(current_level_identifier);

            LabyrinthOfLore::Physics::GravityStepper gravity_stepper(entities_in_the_current_level);
            gravity_stepper.process_step();

            // process_post_gravity_effects(entities_in_the_current_level);

            LabyrinthOfLore::Physics::EntityTileMapCollisionStepper entity_tile_map_collision_stepper(current_tile_map, entities_in_the_current_level);
            entity_tile_map_collision_stepper.process_step();

            // observe tile map collision events, emit game events if needed 
            std::vector<LabyrinthOfLore::Physics::EntityTileMapCollisionEvent> collision_stepper_events = entity_tile_map_collision_stepper.get_events_from_last_processed_step();

            process_collision_stepper_events(
                  collision_stepper_events,
                  player_entity,
                  classic_game.get_levels_ref(),

                  // dependencies for go_into_door
                  classic_game.get_doors_ref(),
                  //LabyrinthOfLore::Entity::Base* player_entity,
                  //std::map<std::string, LabyrinthOfLore::WorldMap::Level> &levels,
                  classic_game.get_meshes_ref(),
                  classic_game.get_water_meshes_ref(),
                  player_yaw,
                  current_tile_map,
                  current_tile_map_mesh,
                  current_tile_map_water_mesh,
                  title_text
            );
            //LabyrinthOfLoreGame::EntityTileMapCollisionEventProcessor entity_tile_map_collision_event_processor(collision_stepper_events);

            camera.get_position_ref() = player_entity->get_placement_ref().position + AllegroFlare::vec3d(0, 0, player_camera_ascent); // player_camera_ascent
            camera.get_yaw_ref() = player_yaw + 0.5;// + sin(al_get_time()) * 0.02;
            camera.get_pitch_ref() = player_pitch - 0.02;;// + sin((al_get_time()+2.345)*0.8534) * 0.02;

            //

            LabyrinthOfLore::Rendering::SpritesBillboarder sprites_billboarder(camera, entities_in_the_current_level);
            sprites_billboarder.process();

            //

            LabyrinthOfLore::Rendering::SceneRenderer scene_renderer(scene_rendering_surface, &camera, &current_tile_map_mesh, &current_tile_map_water_mesh, entities_in_the_current_level, &classic_game.get_depth_darken_shader_ref());
            scene_renderer.render();

            //

            al_clear_depth_buffer(1);
            al_set_render_state(ALLEGRO_DEPTH_TEST, 1);
            LabyrinthOfLore::Rendering::PickingBufferRenderer picking_buffer_renderer(
               &picking_buffer,
               &camera,
               current_tile_map_mesh,
               entities_in_the_current_level,
               &classic_game.get_clamped_color_shader_ref()
            );
            picking_buffer_renderer.render();

            //

            al_set_target_bitmap(al_get_backbuffer(_display));
            al_set_render_state(ALLEGRO_DEPTH_TEST, 0);
            al_draw_scaled_bitmap(
               buffer_buffer,
               0,
               0,
               al_get_bitmap_width(buffer_buffer),
               al_get_bitmap_height(buffer_buffer),
               0,
               0,
               al_get_display_width(_display),
               al_get_display_height(_display),
               0
            );
            //al_draw_scaled_bitmap(picking_buffer.get_surface_render(), 0, 0, al_get_bitmap_width(buffer_buffer), al_get_bitmap_height(buffer_buffer), 0, 0, al_get_display_width(display), al_get_display_height(display), 0);

            //

            LabyrinthOfLore::Rendering::MousePointer mouse_pointer(player_mouse_x, player_mouse_y);
            LabyrinthOfLore::Rendering::Hud::Renderer hud_renderer(
                  al_get_backbuffer(_display),
                  font_bin,
                  &message_scroll,
                  &command_panel,
                  &vitality_and_mana_bar,
                  &character_panel,
                  &map_button,
                  &rune_shelf,
                  &compass,
                  &rotate_character_panel_button,
                  &commands_hint_pane,
                  &current_spells,
                  &veiw_frame,
                  &title_text,
                  &mouse_pointer
               );
            hud_renderer.render();

            al_flip_display();
         }

      // NOTE: This line was previously after the switch statement in the primary loop
      cleanup_all_entities_flagged_for_destruction(classic_game.get_all_entities_ref());
}



void Gameplay::run()
{
   System game_system;
   game_system.initialize();



   // initialize:

   set_bitmap_bin(&game_system.bitmap_bin);
   set_font_bin(&game_system.font_bin);
   set_render_surface_width(game_system.DISPLAY_WIDTH);
   set_render_surface_height(game_system.DISPLAY_HEIGHT);
   initialize(game_system.display);



   // Start game

   start_game();



   while(!game_system.shutdown_program)
   {
      ALLEGRO_EVENT this_event, next_event;
      al_wait_for_event(game_system.event_queue, &this_event);

      switch(this_event.type)
      {
      case ALLEGRO_EVENT_DISPLAY_CLOSE:
         game_system.shutdown_program = true;
         break;
      case ALLEGRO_EVENT_MOUSE_AXES:
         process_mouse_axes_event(this_event);
         break;
      case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
         process_mouse_button_down_event(this_event);
         break;
      case ALLEGRO_EVENT_KEY_CHAR: // using key down does not capture the SHIFT modifier for cheats
         process_key_char_event(this_event, game_system.shutdown_program);
         break;
      case ALLEGRO_EVENT_KEY_UP:
         process_key_up_event(this_event);
         break;
      case ALLEGRO_EVENT_TIMER:
         process_timer_event(this_event, game_system.display);
         while (al_peek_next_event(game_system.event_queue, &next_event)
               && next_event.type == ALLEGRO_EVENT_TIMER
               && next_event.timer.source == this_event.timer.source)
            al_drop_next_event(game_system.event_queue);
         break;
      }

      //cleanup_all_entities_flagged_for_destruction(classic_game.get_all_entities_ref());
   }

   //al_save_bitmap("tmp/buffer_buffer.png", buffer_buffer);
   //al_save_bitmap("tmp/scene.png", scene_rendering_surface);
   //al_save_bitmap("tmp/picking.png", picking_buffer.get_surface_render());
}



} // namespace Gameplay
} // namespace LabyrinthOfLore




