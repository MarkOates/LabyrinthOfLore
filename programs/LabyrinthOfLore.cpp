#define ALLEGRO_UNSTABLE


#include <allegro5/allegro.h>


#include <LabyrinthOfLore/Entity/Base.hpp>
#include <LabyrinthOfLore/Entity/Selector.hpp>
#include <LabyrinthOfLore/WorldMap/Tile.hpp>
#include <LabyrinthOfLore/WorldMap/TileMapLoader.hpp>
#include <LabyrinthOfLore/WorldMap/Level.hpp>
#include <LabyrinthOfLore/Rendering/SceneRenderer.hpp>
#include <LabyrinthOfLore/Rendering/TileMapMesh.hpp>
#include <LabyrinthOfLore/Physics/GravityStepper.hpp>
#include <LabyrinthOfLore/Physics/EntityTileMapCollisionStepper.hpp>
#include <LabyrinthOfLore/Rendering/PickingBufferRenderer.hpp>
#include <LabyrinthOfLore/Rendering/MousePointer.hpp>
#include <LabyrinthOfLore/Rendering/SpritesBillboarder.hpp>
#include <LabyrinthOfLore/Rendering/TileTypeDefinition.hpp>
#include <LabyrinthOfLore/Rendering/TileTypeDictionary.hpp>
#include <LabyrinthOfLore/Rendering/Hud/Renderer.hpp>
//#include <LabyrinthOfLore/Rendering/Hud/MessageScrollRenderer.hpp>
//#include <LabyrinthOfLore/Rendering/Hud/CommandPanelRenderer.hpp>
#include <LabyrinthOfLore/Hud/MessageScroll.hpp>
#include <LabyrinthOfLore/Hud/CommandPanel.hpp>
#include <LabyrinthOfLore/Hud/VitalityAndManaBar.hpp>
#include <LabyrinthOfLore/Hud/CharacterPanel.hpp>
#include <LabyrinthOfLore/Hud/MapButton.hpp>
#include <LabyrinthOfLore/Hud/RuneShelf.hpp>
#include <LabyrinthOfLore/Hud/Compass.hpp>
#include <LabyrinthOfLore/Hud/RotateCharacterPanelButton.hpp>
#include <LabyrinthOfLore/Hud/CommandsHintPane.hpp>
#include <LabyrinthOfLore/Hud/CurrentSpells.hpp>
#include <LabyrinthOfLore/Hud/ViewFrame.hpp>
#include <LabyrinthOfLore/Hud/TitleText.hpp>
#include <Tileo/TileIndexInfo.hpp>
#include <Tileo/TileAtlas.hpp>
#include <AllegroFlare/FontBin.hpp>
#include <AllegroFlare/BitmapBin.hpp>
#include <AllegroFlare/PickingBuffer.hpp>
#include <AllegroFlare/Random.hpp>
#include <allegro_flare/placement2d.h>
#include <AllegroFlare/Useful.hpp>
#include <allegro5/allegro_ttf.h>
#include <cmath>
#include <LabyrinthOfLore/WorldMap/MultiBitmapFilenameToWorldBuilder.hpp>
#include <LabyrinthOfLore/WorldMap/BitmapFilenameToWorldBuilder.hpp>
#include <LabyrinthOfLore/Entity/ThingDefinition.hpp>
#include <LabyrinthOfLore/Entity/ThingDictionary.hpp>
#include <LabyrinthOfLore/Hud/CommandPanelModeEnum.hpp>
#include <LabyrinthOfLore/WorldMap/TileTypeEnum.hpp>
#include <LabyrinthOfLore/Entity/Cleanup.hpp>
//#include <algorithm> // for std::max


#include <iostream>
using namespace std;

void capitalize (string &s)
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



#include <AllegroFlare/Inventory.hpp>

using AllegroFlare::radians_to_degrees;
using AllegroFlare::Random;

#define USER_EVENT_APPEND_MESSAGE_TO_MESSAGE_SCROLL ALLEGRO_GET_EVENT_TYPE('A','p','d','M')


static const std::string THE_UNDERWORLD_IDENTIFIER = "the_underworld";
static const std::string THE_CAVE_IDENTIFIER = "the_cave";
static const std::string AN_ABANDONED_TEMPLE_IDENTIFIER = "an_abandoned_temple";
static const std::string DUNGEON_OF_THE_CURSED_IDENTIFIER = "dungeon_of_the_cursed";
static const std::string TEMPLE_OF_WATER_IDENTIFIER = "temple_of_water";
static const std::string WORLD_OF_FIRE_IDENTIFIER = "world_of_fire";
static const std::string FINAL_TEMPLE_IDENTIFIER = "final_temple";
static const std::string VILLAGE_OF_THE_FORGOTTEN_IDENTIFIER = "village_of_the_forgotten";


#define THING_ID_ATTRIBUTE ("thing_id")
#define CAN_BE_PICKED_UP_ATTRIBUTE ("can_be_picked_up")
#define MUST_BE_PICKED_UP_TO_BE_USED ("must_be_picked_up_to_be_used")
#define DESTROY_THIS_ITEM_AT_CLEANUP ("destroy_this_item_at_cleanup")


enum item_id_t
{
   ITEM_NO_ID = 0,
   ITEM_TORCH_ID,
   ITEM_RING_OF_LOFT_ID,
   ITEM_INFINITY_TORCH_ID,
   ITEM_TORCH_FUEL_ID,

   // characters
   MAN_AT_THE_ENTRANCE_TO_THE_CAVE
};



std::string current_level_identifier = THE_UNDERWORLD_IDENTIFIER;


class Door
{
public:
   std::string level_identifier;
   float spawn_x;
   float spawn_y;
   float spawn_z;
   float spawn_facing_yaw;

   Door(std::string level_identifier, float spawn_x, float spawn_y, float spawn_z, float spawn_facing_yaw)
      : level_identifier(level_identifier)
      , spawn_x(spawn_x)
      , spawn_y(spawn_y)
      , spawn_z(spawn_z)
      , spawn_facing_yaw(spawn_facing_yaw)
   {}

   ~Door() {}
};


class Game
{
public:
   AllegroFlare::FontBin font_bin;
   AllegroFlare::BitmapBin bitmap_bin;
   ALLEGRO_DISPLAY *display;
   float resolution_scale;
   AllegroFlare::PickingBuffer picking_buffer;

   Game(ALLEGRO_DISPLAY *display, float resolution_scale)
      : font_bin()
      , bitmap_bin()
      , display(display)
      , resolution_scale(resolution_scale)
      , picking_buffer(al_get_display_width(display)/resolution_scale, al_get_display_height(display)/resolution_scale, 32)
   {
   }
   ~Game()
   {
   }

   void initialize()
   {
      font_bin.set_path("data/fonts");
      bitmap_bin.set_path("data/bitmaps");

      picking_buffer.initialize();

      // preload the logo

      //bitmap_bin.get("logo-fo-sho.png");
   }
   void run_timer_step()
   {
   }
};



void move_player_to_level(
      LabyrinthOfLore::Entity::Base* player_entity,
      std::map<std::string, LabyrinthOfLore::WorldMap::Level> &levels,
      std::map<std::string, LabyrinthOfLore::Rendering::TileMapMesh> &meshes,
      std::string level_identifier,
      AllegroFlare::vec3d spawn_point,
      LabyrinthOfLore::WorldMap::TileMap &current_tile_map,
      LabyrinthOfLore::Rendering::TileMapMesh &current_tile_map_mesh
   )
{
   current_tile_map = levels[level_identifier].get_tile_map();
   current_tile_map_mesh = meshes[level_identifier];

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
      Door door,
      LabyrinthOfLore::Entity::Base* player_entity,
      std::map<std::string, LabyrinthOfLore::WorldMap::Level> &levels,
      std::map<std::string, LabyrinthOfLore::Rendering::TileMapMesh> &meshes,
      float &player_yaw,
      LabyrinthOfLore::WorldMap::TileMap &current_tile_map,
      LabyrinthOfLore::Rendering::TileMapMesh &current_tile_map_mesh,
      LabyrinthOfLore::Hud::TitleText &title_text
   )
{
   move_player_to_level(
      player_entity,
      levels,
      meshes,
      door.level_identifier,
      AllegroFlare::vec3d(door.spawn_x, door.spawn_y, door.spawn_z),
      current_tile_map,
      current_tile_map_mesh
   );

   set_title_text(
      title_text,
      levels[door.level_identifier].get_heading(),
      levels[door.level_identifier].get_name()
   );

   player_yaw = door.spawn_facing_yaw;
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


   bool item_can_be_used_without_picking_up; //// WILL NEED TO FINISHE THIS THOUGHT HERE

   if (entity->exists(MUST_BE_PICKED_UP_TO_BE_USED))
   {
      message_scroll.append_message(al_get_time(), you_must_pickup_this_item_to_use_it(this_thing_definition));
   }
   else
   {
      message_scroll.append_message(al_get_time(), this_cannot_be_used(this_thing_definition));
   }
}



void process_click_event(
      float player_mouse_x,
      float player_mouse_y,
      AllegroFlare::PickingBuffer &picking_buffer,
      float resolution_scale,
      std::vector<LabyrinthOfLore::Entity::Base *> &all_entities,
      LabyrinthOfLore::Entity::ThingDictionary &thing_dictionary,
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
      }
   }
}



void set_command_mode(LabyrinthOfLore::Hud::CommandPanel &command_panel, LabyrinthOfLore::Hud::command_mode_t new_command_mode)
{
    command_panel.set_current_mode(new_command_mode);
}



void process_keyboard_keydown_event(
      ALLEGRO_EVENT &this_event,
      std::map<char, Door> doors,
      LabyrinthOfLore::Entity::Base* player_entity,
      std::map<std::string, LabyrinthOfLore::WorldMap::Level> &levels,
      std::map<std::string, LabyrinthOfLore::Rendering::TileMapMesh> &meshes,
      float &player_yaw,
      LabyrinthOfLore::WorldMap::TileMap &current_tile_map,
      LabyrinthOfLore::Rendering::TileMapMesh &current_tile_map_mesh,
      LabyrinthOfLore::Hud::TitleText &title_text,
      LabyrinthOfLore::Hud::CommandPanel &command_panel
   )
{
   if (this_event.keyboard.keycode == ALLEGRO_KEY_0)
      go_into_door(doors.at(10), player_entity, levels, meshes, player_yaw, current_tile_map, current_tile_map_mesh, title_text);
   else if (this_event.keyboard.keycode == ALLEGRO_KEY_1)
      go_into_door(doors.at(1), player_entity, levels, meshes, player_yaw, current_tile_map, current_tile_map_mesh, title_text);
   else if (this_event.keyboard.keycode == ALLEGRO_KEY_2)
      go_into_door(doors.at(3), player_entity, levels, meshes, player_yaw, current_tile_map, current_tile_map_mesh, title_text);
   else if (this_event.keyboard.keycode == ALLEGRO_KEY_3)
      go_into_door(doors.at(2), player_entity, levels, meshes, player_yaw, current_tile_map, current_tile_map_mesh, title_text);
   else if (this_event.keyboard.keycode == ALLEGRO_KEY_4)
      go_into_door(doors.at(4), player_entity, levels, meshes, player_yaw, current_tile_map, current_tile_map_mesh, title_text);
   else if (this_event.keyboard.keycode == ALLEGRO_KEY_5)
      go_into_door(doors.at(5), player_entity, levels, meshes, player_yaw, current_tile_map, current_tile_map_mesh, title_text);
   else if (this_event.keyboard.keycode == ALLEGRO_KEY_6)
      go_into_door(doors.at(6), player_entity, levels, meshes, player_yaw, current_tile_map, current_tile_map_mesh, title_text);
   else if (this_event.keyboard.keycode == ALLEGRO_KEY_7)
      go_into_door(doors.at(7), player_entity, levels, meshes, player_yaw, current_tile_map, current_tile_map_mesh, title_text);


   else if (this_event.keyboard.keycode == ALLEGRO_KEY_T) set_command_mode(command_panel, LabyrinthOfLore::Hud::COMMAND_MODE_TALK);
   else if (this_event.keyboard.keycode == ALLEGRO_KEY_P) set_command_mode(command_panel, LabyrinthOfLore::Hud::COMMAND_MODE_PICKUP);
   else if (this_event.keyboard.keycode == ALLEGRO_KEY_L) set_command_mode(command_panel, LabyrinthOfLore::Hud::COMMAND_MODE_LOOK);
   else if (this_event.keyboard.keycode == ALLEGRO_KEY_K || this_event.keyboard.keycode == ALLEGRO_KEY_Z) set_command_mode(command_panel, LabyrinthOfLore::Hud::COMMAND_MODE_ATTACK);
   else if (this_event.keyboard.keycode == ALLEGRO_KEY_U) set_command_mode(command_panel, LabyrinthOfLore::Hud::COMMAND_MODE_USE);
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
      std::map<char, Door> doors,
      //LabyrinthOfLore::Entity::Base* player_entity,
      //std::map<std::string, LabyrinthOfLore::WorldMap::Level> &levels,
      std::map<std::string, LabyrinthOfLore::Rendering::TileMapMesh> &meshes,
      float &player_yaw,
      LabyrinthOfLore::WorldMap::TileMap &current_tile_map,
      LabyrinthOfLore::Rendering::TileMapMesh &current_tile_map_mesh,
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
            { THE_CAVE_IDENTIFIER, 32, 14, 11 },
            { THE_UNDERWORLD_IDENTIFIER, 56, 24, 1 },

            { AN_ABANDONED_TEMPLE_IDENTIFIER, 19, 43, 12 },
            { THE_UNDERWORLD_IDENTIFIER, 42, 44, 2 },

            { DUNGEON_OF_THE_CURSED_IDENTIFIER, 1, 24, 13 },
            { THE_UNDERWORLD_IDENTIFIER, 72, 92, 3 },

            { TEMPLE_OF_WATER_IDENTIFIER, 55, 58, 14 },
            { THE_UNDERWORLD_IDENTIFIER, 25, 20, 4 },

            { WORLD_OF_FIRE_IDENTIFIER, 19, 58, 15 },
            { THE_UNDERWORLD_IDENTIFIER, 103, 1, 5 },

            { FINAL_TEMPLE_IDENTIFIER, 39, 57, 16 },
            { THE_UNDERWORLD_IDENTIFIER, 40, 30, 6 },

            { VILLAGE_OF_THE_FORGOTTEN_IDENTIFIER, 29, 30, 17 },
            { THE_UNDERWORLD_IDENTIFIER, 23, 55, 7 },
         };

         for (auto door_data : door_datas)
         {
            if (current_level_identifier == std::get<0>(door_data) && tile_x == std::get<1>(door_data) && tile_y == std::get<2>(door_data))
            {
               go_into_door(doors.at(std::get<3>(door_data)), player_entity, levels, meshes, player_yaw, current_tile_map, current_tile_map_mesh, title_text);
            }
         }
         // the player encountered a new collision
      }
   }
   //entity_tile_map_collision_stepper.get_events_from_last_processed_step();
   //title_text.set(top_text, headline_text, al_get_time());
};





void add_thing_to_world(
      std::vector<LabyrinthOfLore::Entity::Base*> &all_entities,
      LabyrinthOfLore::Entity::ThingDictionary &thing_dictionary,
      int thing_id,
      std::string level_identifier,
      AllegroFlare::vec3d position,
      bool billboard_at_camera=true,
      bool can_be_picked_up=true,
      bool must_be_picked_up_to_be_used=false // this here

   )
{
   //if (!all_entities) throw std::runtime_error("cannot add_thing_to_world with a nullptr all_entities"); 

   LabyrinthOfLore::Entity::ThingDefinition thing_definition = thing_dictionary.find_definition(thing_id);
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

   all_entities.push_back(entity);
}









bool active = true;

int main(int argc, char **argv)
{
   if (active)
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
      al_set_new_display_option(ALLEGRO_SAMPLES, 16, ALLEGRO_SUGGEST);
      al_set_new_display_flags(ALLEGRO_RESIZABLE | ALLEGRO_OPENGL | ALLEGRO_PROGRAMMABLE_PIPELINE);


      float resolution_scale = 3;


      ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);

      //

      bool shutdown_program = false;

      ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

      al_install_keyboard();
      al_register_event_source(event_queue, al_get_keyboard_event_source());

      al_install_mouse();
      al_register_event_source(event_queue, al_get_mouse_event_source());

      ALLEGRO_TIMER *primary_timer = al_create_timer(1.0/60.0);
      al_register_event_source(event_queue, al_get_timer_event_source(primary_timer));
      al_start_timer(primary_timer);


      //



      Game game(display, resolution_scale);
      game.initialize();





      //

      LabyrinthOfLore::Shader::ClampedColor clamped_color_shader;
      clamped_color_shader.initialize();

      LabyrinthOfLore::Shader::DepthDarken depth_darken_shader;
      depth_darken_shader.initialize();

      //

      int previous_depth = al_get_new_bitmap_depth();
      int previous_samples = al_get_new_bitmap_samples();
      ALLEGRO_STATE previous_state;
      al_store_state(&previous_state, ALLEGRO_STATE_BITMAP);

      al_set_new_bitmap_depth(32);
      al_set_new_bitmap_samples(0);
      //ALLEGRO_BITMAP *bmp = al_create_bitmap(w, h);

      ALLEGRO_BITMAP *buffer_buffer = al_create_bitmap(al_get_display_width(display)/resolution_scale, al_get_display_height(display)/resolution_scale);
      //ALLEGRO_BITMAP *buffer_buffer = al_get_backbuffer(display);

      al_restore_state(&previous_state);
      al_set_new_bitmap_depth(previous_depth);
      al_set_new_bitmap_samples(previous_samples);


      ALLEGRO_BITMAP *scene_rendering_surface = al_create_sub_bitmap(buffer_buffer, 0, 0, al_get_bitmap_width(buffer_buffer), al_get_bitmap_height(buffer_buffer));
      if (!scene_rendering_surface) throw std::runtime_error("could not create scene_rendering_surface");

      ALLEGRO_BITMAP *hud_rendering_surface = al_create_sub_bitmap(buffer_buffer, 0, 0, al_get_bitmap_width(buffer_buffer), al_get_bitmap_height(buffer_buffer));
      if (!hud_rendering_surface) throw std::runtime_error("could not create hud_rendering_surface");


      //

      ALLEGRO_BITMAP *tile_mesh_texture = al_load_bitmap("data/bitmaps/billboarding_tester_sprite.png");
      if (!tile_mesh_texture) throw std::runtime_error("could not load tile_mesh_texture");

      ALLEGRO_BITMAP *billboarding_tester_sprite = al_load_bitmap("data/bitmaps/billboarding_tester_sprite.png");
      if (!billboarding_tester_sprite) throw std::runtime_error("could not load billboarding_tester_sprite.png");

      Tileo::TileAtlas item_tile_atlas;
      item_tile_atlas.load(game.bitmap_bin["item_spritesheet_full.png"], 16, 16, 0);

      Tileo::TileAtlas character_tile_atlas;
      character_tile_atlas.load(game.bitmap_bin["item_spritesheet_full.png"], 32, 32, 0);

      Tileo::TileAtlas world_texture_tile_atlas;
      //world_texture_tile_atlas.load(bitmap_bin["grid-texture-128.png"], 128/3, 128/3, 0);
      world_texture_tile_atlas.load(game.bitmap_bin["world_texture_tile_atlas-02.png"], 48, 48, 0);



      //

      LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary({
          { LabyrinthOfLore::WorldMap::NORMAL_GROUND_TILE, LabyrinthOfLore::Rendering::TileTypeDefinition(1, 1, 0) },
          { LabyrinthOfLore::WorldMap::DOOR_TILE,          LabyrinthOfLore::Rendering::TileTypeDefinition(2, 2, 0) },
          { LabyrinthOfLore::WorldMap::WATER_TILE,         LabyrinthOfLore::Rendering::TileTypeDefinition(2, 2, 0) },
          { LabyrinthOfLore::WorldMap::LAVA_TILE,          LabyrinthOfLore::Rendering::TileTypeDefinition(2, 2, 0) },
          { LabyrinthOfLore::WorldMap::GLOW_WATER_TILE,    LabyrinthOfLore::Rendering::TileTypeDefinition(2, 2, 0) },
      });

      //

      //LabyrinthOfLoreGame::WorldMap::BitmapFilenameToWorldBuilder("data/bitmaps/the_underworld.png");

      std::map<std::string, LabyrinthOfLore::WorldMap::Level> levels = {
         { THE_UNDERWORLD_IDENTIFIER,           LabyrinthOfLore::WorldMap::Level(
                                                   "",
                                                   "The Underworld",
                                                   2.0f,
                                                   LabyrinthOfLore::WorldMap::MultiBitmapFilenameToWorldBuilder("data/bitmaps/the_underworld.png", "data/bitmaps/the_underworld-type.png", 3.0).build()
                                                )
         },
         { THE_CAVE_IDENTIFIER,                 LabyrinthOfLore::WorldMap::Level(
                                                   "Level 1",
                                                   "The Cave",
                                                   3.0f,
                                                   LabyrinthOfLore::WorldMap::BitmapFilenameToWorldBuilder("data/bitmaps/the_cave.png", 3.0).build()
                                                )
         },
         { AN_ABANDONED_TEMPLE_IDENTIFIER,      LabyrinthOfLore::WorldMap::Level(
                                                   "Level 3",
                                                   "An Abandoned Temple",
                                                   3.0f,
                                                   LabyrinthOfLore::WorldMap::BitmapFilenameToWorldBuilder("data/bitmaps/an_abandoned_temple.png", 3.0, 1.0).build()
                                                )
         },
         { DUNGEON_OF_THE_CURSED_IDENTIFIER,    LabyrinthOfLore::WorldMap::Level(
                                                   "Level 2",
                                                   "Dungeon of the Cursed",
                                                   2.0f,
                                                   LabyrinthOfLore::WorldMap::BitmapFilenameToWorldBuilder("data/bitmaps/dungeon_of_the_cursed.png").build()
                                                )
         },
         { TEMPLE_OF_WATER_IDENTIFIER,          LabyrinthOfLore::WorldMap::Level(
                                                   "Level 4",
                                                   "Temple of Water",
                                                   2.0f,
                                                   LabyrinthOfLore::WorldMap::BitmapFilenameToWorldBuilder("data/bitmaps/temple_of_water.png", 6.0, 1.25).build()
                                                )
         },
         { WORLD_OF_FIRE_IDENTIFIER,            LabyrinthOfLore::WorldMap::Level(
                                                   "Level 5",
                                                   "World of Fire",
                                                   5.0f,
                                                   LabyrinthOfLore::WorldMap::BitmapFilenameToWorldBuilder("data/bitmaps/world_of_fire.png", 5.0).build()
                                                )
         },
         { FINAL_TEMPLE_IDENTIFIER,             LabyrinthOfLore::WorldMap::Level(
                                                   "",
                                                   "Final Temple",
                                                   3.0f,
                                                   LabyrinthOfLore::WorldMap::BitmapFilenameToWorldBuilder("data/bitmaps/final_temple.png", 3.0).build()
                                                )
         },
         { VILLAGE_OF_THE_FORGOTTEN_IDENTIFIER, LabyrinthOfLore::WorldMap::Level(
                                                   "",
                                                   "Village of the Forgotten",
                                                   2.0f,
                                                   LabyrinthOfLore::WorldMap::BitmapFilenameToWorldBuilder("data/bitmaps/village_of_the_forgotten.png").build()
                                                )
         },
      };

      //


      std::map<std::string, LabyrinthOfLore::Rendering::TileMapMesh> meshes = {
         { THE_UNDERWORLD_IDENTIFIER,           LabyrinthOfLore::Rendering::TileMapMesh(
                                                   &world_texture_tile_atlas,
                                                   tile_type_dictionary,
                                                   levels[THE_UNDERWORLD_IDENTIFIER].get_tile_map(),
                                                   world_texture_tile_atlas.get_bitmap(),
                                                   0
                                                ),
         },
         { THE_CAVE_IDENTIFIER,                 LabyrinthOfLore::Rendering::TileMapMesh(
                                                   &world_texture_tile_atlas,
                                                   tile_type_dictionary,
                                                   levels[THE_CAVE_IDENTIFIER].get_tile_map(),
                                                   world_texture_tile_atlas.get_bitmap(),
                                                   10
                                                ),
         },
         { AN_ABANDONED_TEMPLE_IDENTIFIER,      LabyrinthOfLore::Rendering::TileMapMesh(
                                                   &world_texture_tile_atlas,
                                                   tile_type_dictionary,
                                                   levels[AN_ABANDONED_TEMPLE_IDENTIFIER].get_tile_map(),
                                                   world_texture_tile_atlas.get_bitmap(),
                                                   20
                                                ),
         },
         { DUNGEON_OF_THE_CURSED_IDENTIFIER,    LabyrinthOfLore::Rendering::TileMapMesh(
                                                   &world_texture_tile_atlas,
                                                   tile_type_dictionary,
                                                   levels[DUNGEON_OF_THE_CURSED_IDENTIFIER].get_tile_map(),
                                                   world_texture_tile_atlas.get_bitmap(),
                                                   30
                                                ),
         },
         { TEMPLE_OF_WATER_IDENTIFIER,          LabyrinthOfLore::Rendering::TileMapMesh(
                                                   &world_texture_tile_atlas,
                                                   tile_type_dictionary,
                                                   levels[TEMPLE_OF_WATER_IDENTIFIER].get_tile_map(),
                                                   world_texture_tile_atlas.get_bitmap(),
                                                   40
                                                ),
         },
         { WORLD_OF_FIRE_IDENTIFIER,            LabyrinthOfLore::Rendering::TileMapMesh(
                                                   &world_texture_tile_atlas,
                                                   tile_type_dictionary,
                                                   levels[WORLD_OF_FIRE_IDENTIFIER].get_tile_map(),
                                                   world_texture_tile_atlas.get_bitmap(),
                                                   50
                                                ),
         },
         { FINAL_TEMPLE_IDENTIFIER,             LabyrinthOfLore::Rendering::TileMapMesh(
                                                   &world_texture_tile_atlas,
                                                   tile_type_dictionary,
                                                   levels[FINAL_TEMPLE_IDENTIFIER].get_tile_map(),
                                                   world_texture_tile_atlas.get_bitmap(),
                                                   60
                                                ),
         },
         { VILLAGE_OF_THE_FORGOTTEN_IDENTIFIER, LabyrinthOfLore::Rendering::TileMapMesh(
                                                   &world_texture_tile_atlas,
                                                   tile_type_dictionary,
                                                   levels[VILLAGE_OF_THE_FORGOTTEN_IDENTIFIER].get_tile_map(),
                                                   world_texture_tile_atlas.get_bitmap(),
                                                   70
                                                ),
         },
      };

      // build all the meshes

      for (auto &mesh : meshes) { mesh.second.build(); }



      //std::map<int, std::string> map_names = {
         //{ 0, THE_UNDERWORLD_IDENTIFIER },
         //{ 1, THE_CAVE_IDENTIFIER },
         //{ 2, AN_ABANDONED_TEMPLE_IDENTIFIER },
         //{ 3, DUNGEON_OF_THE_CURSED_IDENTIFIER },
         //{ 4, TEMPLE_OF_WATER_IDENTIFIER },
         //{ 5, WORLD_OF_FIRE_IDENTIFIER },
         //{ 6, FINAL_TEMPLE_IDENTIFIER },
         //{ 7, VILLAGE_OF_THE_FORGOTTEN_IDENTIFIER },
      //};

      std::map<char, Door> doors = {
         { 1, Door(THE_CAVE_IDENTIFIER, 32.5, 13.5, -5.0, 0.5) },
         { 2, Door(AN_ABANDONED_TEMPLE_IDENTIFIER, 19.5, 42.5, -5.0, 0.5) },
         { 3, Door(DUNGEON_OF_THE_CURSED_IDENTIFIER, 2.5, 24.5, -5.0, -0.25) },
         { 4, Door(TEMPLE_OF_WATER_IDENTIFIER, 55.5, 57.5, -5.0, 0.5) },
         { 5, Door(WORLD_OF_FIRE_IDENTIFIER, 19.5, 57.5, -5.0, 0.5) },
         { 6, Door(FINAL_TEMPLE_IDENTIFIER, 39.5, 56.5, -5.0, 0.5) },
         { 7, Door(VILLAGE_OF_THE_FORGOTTEN_IDENTIFIER, 28.5, 30.5, -5.0, 0.25) },

         { 10, Door(THE_UNDERWORLD_IDENTIFIER, 40.5, 88.5+18, -5.0, 0.5 ), }, // this is the primary spawn point, the game start

         { 11, Door(THE_UNDERWORLD_IDENTIFIER, 56.5, 25.5, -5.0, 0.0 ), },
         { 12, Door(THE_UNDERWORLD_IDENTIFIER, 42.5, 45.5, -5.0, 0.25 ), },
         { 13, Door(THE_UNDERWORLD_IDENTIFIER, 71.5, 92.5, -5.0, 0.25 ), },
         { 14, Door(THE_UNDERWORLD_IDENTIFIER, 25.5, 21.5, -5.0, 0.0 ), },
         { 15, Door(THE_UNDERWORLD_IDENTIFIER, 103.5, 2.5, -5.0, 0.0 ), },
         { 16, Door(THE_UNDERWORLD_IDENTIFIER, 40.5, 31.5, -5.0, 0.0 ), },
         { 17, Door(THE_UNDERWORLD_IDENTIFIER, 24.5, 55.5, -5.0, -0.25 ), },
      };


      //
      LabyrinthOfLore::Entity::ThingDictionary thing_dictionary({
          { ITEM_TORCH_ID,                         LabyrinthOfLore::Entity::ThingDefinition("a",   "torch",                                 &item_tile_atlas,      6 + 9*14,  1)  },
          { ITEM_RING_OF_LOFT_ID,                  LabyrinthOfLore::Entity::ThingDefinition("the", "ring of loft",                          &item_tile_atlas,      10+13*14,  1)  },
          { ITEM_INFINITY_TORCH_ID,                LabyrinthOfLore::Entity::ThingDefinition("the", "infinity torch",                        &item_tile_atlas,      6 + 9*14,  1)  },
          { ITEM_TORCH_FUEL_ID,                    LabyrinthOfLore::Entity::ThingDefinition("some","torch fuel",                            &item_tile_atlas,      27 + 5*14, 1)  },
          { MAN_AT_THE_ENTRANCE_TO_THE_CAVE,       LabyrinthOfLore::Entity::ThingDefinition("",    "a goblin at the entrance of the cave",  &character_tile_atlas, 4 + 11*7,  1)  },
      });



      //

      AllegroFlare::Inventory player_inventory;

      //
      //

      std::vector<LabyrinthOfLore::Entity::Base*> all_entities = {};
      LabyrinthOfLore::Rendering::Camera camera({0, 0, 0}, 0.0, 0.0);

      LabyrinthOfLore::Entity::Base* player_entity = new LabyrinthOfLore::Entity::Base;
      //player_entity->get_placement_ref().position = AllegroFlare::vec3d(1.5, 90.5, 1.01);
      //

      float player_yaw = -0.04 - 0.5;
      float player_camera_ascent = 0.65;
      float player_pitch = 0.0;
      float player_turning = 0.0;
      float max_player_turning_speed = 0.0023;
      float player_movement_magnitude = 0.0;

      int player_mouse_x = 0;
      int player_mouse_y = 0;

      player_entity->get_velocity_ref().position = {0.0, 0.0, 0.0};
      player_entity->set_identifier_for_level_within(THE_UNDERWORLD_IDENTIFIER);
      player_entity->get_placement_ref().position = {0.0, 0.0, 0.0};
      //player_entity->get_placement_ref().rotation = {2.5, 2.5, 0.0};

      //camera.get_position_ref() = player_entity->get_placement_ref().position + AllegroFlare::vec3d(0, 0, 0.65); //{5, 20, 2.01 + 0.5};

      all_entities.push_back(player_entity);




      //add_thing_to_world(LabyrinthOfLore::Entity::ThingDefinition, std::string level_identifier, placement3d placement, billboard_at_camera);

      //std::vector<LabyrinthOfLore::Entity::Base*> *all_entities,
      //LabyrinthOfLore::Entity::ThingDictionary &thing_dictionary,
      //int thing_id,
      //std::string level_identifier,
      //AllegroFlare::vec3d position,
      //bool billboard_at_camera=true

      add_thing_to_world(all_entities, thing_dictionary, ITEM_TORCH_ID,                   THE_UNDERWORLD_IDENTIFIER, {  42.5,  77.5, 3.0 }, true, true,  false);
      add_thing_to_world(all_entities, thing_dictionary, MAN_AT_THE_ENTRANCE_TO_THE_CAVE, THE_CAVE_IDENTIFIER,       {  31.5,  9.5, 1.0 },  true, false, false);


      //for (int y=0; y<36; y++)
      //{
         //for (int x=0; x<40; x++)
         //{
            //add_thing_to_world(&all_entities, thing_dictionary.find_definition(ITEM_TORCH_ID), THE_CAVE_IDENTIFIER,       { x + 0.5f, y + 0.5f, 6.0f }, true);
         //}
      //}

      //std::vector<LabyrinthOfLore::Entity::Base*> *all_entities,
      //LabyrinthOfLore::Entity::ThingDefinition thing_definition,
      //std::string level_identifier,
      //AllegroFlare::vec3d position,
      //bool billboard_at_camera=true

      //

      /*
      int x = 42;
      int y = 59+18;
      //int sprite_sheet_width = al_get_bitmap_width(item_tile_atlas.get_bitmap());
      //int torch_id = 9*13+6;
      ALLEGRO_BITMAP *bitmap = item_tile_atlas.get_bitmap(thing_dictionary.find_definition(ITEM_TORCH_ID).get_tile_atlas_index_id());
      LabyrinthOfLore::Entity::Base* entity = new LabyrinthOfLore::Entity::Base;
      entity->set_billboard_at_camera(true);
      entity->set_bitmap(bitmap);
      entity->set_identifier_for_level_within(THE_UNDERWORLD_IDENTIFIER);
      entity->get_placement_ref().size = AllegroFlare::vec3d(al_get_bitmap_width(bitmap), al_get_bitmap_height(bitmap), 0.0);
      entity->get_placement_ref().size = AllegroFlare::vec3d(al_get_bitmap_width(bitmap), al_get_bitmap_height(bitmap), 0.0);
      entity->get_placement_ref().scale = AllegroFlare::vec3d(0.005, 0.005, 0.005);
      entity->get_placement_ref().align = AllegroFlare::vec3d(0.5, 1.0, 0.0);
      entity->get_placement_ref().position = AllegroFlare::vec3d(x + 0.5, y + 0.5, 3.01);
      //entity->get_placement_ref().rotation = AllegroFlare::vec3d(0, random.get_random_float(-1, 1), 0);
      all_entities.push_back(entity);
      */

      //Random random;

      //for (int y=1; y<3; y++)
      //{
         //for (int x=1; x<3; x++)
         //{
            //LabyrinthOfLore::Entity::Base* entity = new LabyrinthOfLore::Entity::Base;
            //entity->set_billboard_at_camera(true);
            //entity->set_bitmap(item_tile_atlas.get_bitmap(9*8));
            //entity->set_identifier_for_level_within(THE_UNDERWORLD_IDENTIFIER);
            //entity->get_placement_ref().size = AllegroFlare::vec3d(al_get_bitmap_width(billboarding_tester_sprite), al_get_bitmap_height(billboarding_tester_sprite), 0.0);
            //entity->get_placement_ref().scale = AllegroFlare::vec3d(0.005, 0.005, 0.005);
            //entity->get_placement_ref().align = AllegroFlare::vec3d(0.5, 1.0, 0.0);
            //entity->get_placement_ref().position = AllegroFlare::vec3d(x + 0.5, y + 0.5, 1.01);
            //entity->get_placement_ref().rotation = AllegroFlare::vec3d(0, random.get_random_float(-1, 1), 0);
            ////entity->get_placement_ref().rotation = AllegroFlare::vec3d(random.get_random_float(-1, 1), random.get_random_float(-1, 1), random.get_random_float(-1, 1));

            //all_entities.push_back(entity);

            //std::cout << "entity made " << std::endl;
         //}
      //}



      //

      LabyrinthOfLore::Hud::MessageScroll message_scroll("");
      LabyrinthOfLore::Hud::CommandPanel command_panel;
      LabyrinthOfLore::Hud::VitalityAndManaBar vitality_and_mana_bar;
      LabyrinthOfLore::Hud::CharacterPanel character_panel(&player_inventory, &thing_dictionary);
      LabyrinthOfLore::Hud::MapButton map_button;
      LabyrinthOfLore::Hud::RuneShelf rune_shelf;
      LabyrinthOfLore::Hud::Compass compass;
      LabyrinthOfLore::Hud::RotateCharacterPanelButton rotate_character_panel_button;
      LabyrinthOfLore::Hud::CommandsHintPane commands_hint_pane;
      LabyrinthOfLore::Hud::CurrentSpells current_spells;
      LabyrinthOfLore::Hud::ViewFrame veiw_frame;
      LabyrinthOfLore::Hud::TitleText title_text;

      //

      LabyrinthOfLore::WorldMap::TileMap current_tile_map;
      LabyrinthOfLore::Rendering::TileMapMesh current_tile_map_mesh;

      //
         //{40.5, 87.5, levels[THE_UNDERWORLD_IDENTIFIER].get_ground_height()+0.001f },


      //move_player_to_level(
            //player_entity,
            //levels,
            //meshes,
            //TEMPLE_OF_WATER_IDENTIFIER,
            //{ 27, 14, 0 },
            //current_tile_map,
            //current_tile_map_mesh
      //);

      player_yaw += 0.5;
         
      //move_player_to_level(
         //player_entity,
         //levels,
         //meshes,
         //&player_yaw,
         //current_tile_map,
         //current_tile_map_mesh
      //);

      //set_title_text(
         //title_text,
         //"Level 0",
         //levels[THE_UNDERWORLD_IDENTIFIER].get_name()
      //);

      //

      // start game
      go_into_door(
         doors.at(10),
         player_entity,
         levels,
         meshes,
         player_yaw,
         current_tile_map,
         current_tile_map_mesh,
         title_text
      );


      while(!shutdown_program)
      {
         ALLEGRO_EVENT this_event, next_event;
         al_wait_for_event(event_queue, &this_event);

         switch(this_event.type)
         {
         case ALLEGRO_EVENT_DISPLAY_CLOSE:
            shutdown_program = true;
            break;
         case ALLEGRO_EVENT_MOUSE_AXES:
            player_mouse_x = this_event.mouse.x;
            player_mouse_y = this_event.mouse.y;
            // observe mouse enter and mouse exit, emit game events if needed 
            break;
         case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            {
               player_mouse_x = this_event.mouse.x;
               player_mouse_y = this_event.mouse.y;

               process_click_event(
                  player_mouse_x,
                  player_mouse_y,
                  game.picking_buffer,
                  resolution_scale,
                  all_entities,
                  thing_dictionary,
                  message_scroll,
                  command_panel,
                  character_panel,
                  player_inventory
               );

               //int picked_id = game.picking_buffer.get_id(player_mouse_x/resolution_scale, player_mouse_y/resolution_scale);
               //std::cout << "Picked ID: " << picked_id << std::endl;
               // observe clicked item, emit game events if needed 
               break;
            }
         case ALLEGRO_EVENT_KEY_CHAR: // using key down does not capture the SHIFT modifier for cheats
            if (this_event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) shutdown_program = true;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_A) player_turning = -max_player_turning_speed;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_W) player_movement_magnitude = 0.022;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_D) player_turning = max_player_turning_speed;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_S) player_movement_magnitude = -0.022;

            if (this_event.keyboard.keycode == ALLEGRO_KEY_T) depth_darken_shader.toggle_torch();

            process_cheat_keyboard_keydown_event(
               this_event,
               player_inventory
            );

            process_keyboard_keydown_event(
               this_event,
               doors,
               player_entity,
               levels,
               meshes,
               player_yaw,
               current_tile_map,
               current_tile_map_mesh,
               title_text,
               command_panel
            );
            break;
         case USER_EVENT_APPEND_MESSAGE_TO_MESSAGE_SCROLL:
            break;
         case ALLEGRO_EVENT_KEY_UP:
            if (this_event.keyboard.keycode == ALLEGRO_KEY_A) player_turning = 0.0;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_W) player_movement_magnitude = 0.0;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_D) player_turning = 0.0;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_S) player_movement_magnitude = 0.0;

            break;
         case ALLEGRO_EVENT_TIMER:
            game.run_timer_step();
            {
               player_yaw += player_turning;

               AllegroFlare::vec2d view_vector_2d = AllegroFlare::vec2d::polar_coords((player_yaw + 0.25) * ALLEGRO_PI*2, player_movement_magnitude);
               player_entity->get_velocity_ref().position.x = view_vector_2d.x; //view_vector_2d.x;
               player_entity->get_velocity_ref().position.y = view_vector_2d.y; //view_vector_2d.y;

               std::vector<LabyrinthOfLore::Entity::Base*> entities_in_the_current_level = LabyrinthOfLore::Entity::Selector(all_entities).select_within_level(current_level_identifier);

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
                     levels,

                     // dependencies for go_into_door
                     doors,
                     //LabyrinthOfLore::Entity::Base* player_entity,
                     //std::map<std::string, LabyrinthOfLore::WorldMap::Level> &levels,
                     meshes,
                     player_yaw,
                     current_tile_map,
                     current_tile_map_mesh,
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

               LabyrinthOfLore::Rendering::SceneRenderer scene_renderer(scene_rendering_surface, &camera, current_tile_map_mesh, entities_in_the_current_level, &depth_darken_shader);
               scene_renderer.render();

               //

               al_clear_depth_buffer(1);
               al_set_render_state(ALLEGRO_DEPTH_TEST, 1);
               LabyrinthOfLore::Rendering::PickingBufferRenderer picking_buffer_renderer(&game.picking_buffer, &camera, current_tile_map_mesh, entities_in_the_current_level, &clamped_color_shader);
               picking_buffer_renderer.render();

               //

               al_set_target_bitmap(al_get_backbuffer(display));
               al_set_render_state(ALLEGRO_DEPTH_TEST, 0);
               al_draw_scaled_bitmap(buffer_buffer, 0, 0, al_get_bitmap_width(buffer_buffer), al_get_bitmap_height(buffer_buffer), 0, 0, al_get_display_width(display), al_get_display_height(display), 0);
               //al_draw_scaled_bitmap(picking_buffer.get_surface_render(), 0, 0, al_get_bitmap_width(buffer_buffer), al_get_bitmap_height(buffer_buffer), 0, 0, al_get_display_width(display), al_get_display_height(display), 0);

               //

               LabyrinthOfLore::Rendering::MousePointer mouse_pointer(player_mouse_x, player_mouse_y);
               LabyrinthOfLore::Rendering::Hud::Renderer hud_renderer(
                     al_get_backbuffer(display),
                     &game.font_bin,
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
            while (al_peek_next_event(event_queue, &next_event)
                  && next_event.type == ALLEGRO_EVENT_TIMER
                  && next_event.timer.source == this_event.timer.source)
               al_drop_next_event(event_queue);
         }

         cleanup_all_entities_flagged_for_destruction(all_entities);
      }

      al_save_bitmap("tmp/buffer_buffer.png", buffer_buffer);
      //al_save_bitmap("tmp/scene.png", scene_rendering_surface);
      //al_save_bitmap("tmp/picking.png", picking_buffer.get_surface_render());
   }

   return 0;
}


