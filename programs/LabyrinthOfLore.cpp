#define ALLEGRO_UNSTABLE


#include <allegro5/allegro.h>


#include <LabyrinthOfLore/Entity/Base.hpp>
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
#include <LabyrinthOfLore/WorldMap/BitmapFilenameToWorldBuilder.hpp>

using AllegroFlare::radians_to_degrees;
using AllegroFlare::Random;

#include <LabyrinthOfLoreGame/Maps/Construct.hpp>
#include <LabyrinthOfLoreGame/Maps/TheUnderworld.hpp>
#include <LabyrinthOfLoreGame/TileTypeDictionary.hpp>
#include <LabyrinthOfLoreGame/EntityTileMapCollisionEventProcessor.hpp>


#define USER_EVENT_APPEND_MESSAGE_TO_MESSAGE_SCROLL ALLEGRO_GET_EVENT_TYPE('A','p','d','M')


static const std::string THE_UNDERWORLD_IDENTIFIER = "the_underworld";
static const std::string THE_CAVE_IDENTIFIER = "the_cave";
static const std::string AN_ABANDONED_TEMPLE_IDENTIFIER = "an_abandoned_temple";
static const std::string DUNGEON_OF_THE_CURSED_IDENTIFIER = "dungeon_of_the_cursed";
static const std::string TEMPLE_OF_WATER_IDENTIFIER = "temple_of_water";
static const std::string WORLD_OF_FIRE_IDENTIFIER = "world_of_fire";
static const std::string FINAL_TEMPLE_IDENTIFIER = "final_temple";
static const std::string VILLAGE_OF_THE_FORGOTTEN_IDENTIFIER = "village_of_the_forgotten";


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
   player_entity->get_placement_ref().position = spawn_point;

   // reset the players's velocity - so no funny stuff, ok buddy? ;)
   player_entity->get_velocity_ref().position = AllegroFlare::vec3d(0.0, 0.0, 0.0);
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
      "Level n",
      levels[door.level_identifier].get_name()
   );

   player_yaw = door.spawn_facing_yaw;
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
      item_tile_atlas.load(game.bitmap_bin["spritesheet_4x.png"], 16*4, 16*4, 0);

      Tileo::TileAtlas world_texture_tile_atlas;
      //world_texture_tile_atlas.load(bitmap_bin["grid-texture-128.png"], 128/3, 128/3, 0);
      world_texture_tile_atlas.load(game.bitmap_bin["world_texture_tile_atlas-02.png"], 48, 48, 0);

      //

      LabyrinthOfLoreGame::TileTypeDictionary game_tile_type_dictionary;
      LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary = game_tile_type_dictionary.build_tile_type_dictionary();

      //

      //LabyrinthOfLoreGame::WorldMap::BitmapFilenameToWorldBuilder("data/bitmaps/the_underworld.png");

      std::map<std::string, LabyrinthOfLore::WorldMap::Level> levels = {
         { THE_UNDERWORLD_IDENTIFIER,           LabyrinthOfLore::WorldMap::Level(
                                                   "The Underworld",
                                                   2.0f,
                                                   LabyrinthOfLore::WorldMap::BitmapFilenameToWorldBuilder("data/bitmaps/the_underworld.png").build()
                                                )
         },
         { THE_CAVE_IDENTIFIER,                 LabyrinthOfLore::WorldMap::Level(
                                                   "The Cave",
                                                   2.0f,
                                                   LabyrinthOfLore::WorldMap::BitmapFilenameToWorldBuilder("data/bitmaps/the_cave.png").build()
                                                )
         },
         { AN_ABANDONED_TEMPLE_IDENTIFIER,      LabyrinthOfLore::WorldMap::Level(
                                                   "An Abandoned Temple",
                                                   2.5f,
                                                   LabyrinthOfLore::WorldMap::BitmapFilenameToWorldBuilder("data/bitmaps/an_abandoned_temple.png", 2.5, 1.0).build()
                                                )
         },
         { DUNGEON_OF_THE_CURSED_IDENTIFIER,    LabyrinthOfLore::WorldMap::Level(
                                                   "Dungeon of the Cursed",
                                                   2.0f,
                                                   LabyrinthOfLore::WorldMap::BitmapFilenameToWorldBuilder("data/bitmaps/dungeon_of_the_cursed.png").build()
                                                )
         },
         { TEMPLE_OF_WATER_IDENTIFIER,          LabyrinthOfLore::WorldMap::Level(
                                                   "Temple of Water",
                                                   2.0f,
                                                   LabyrinthOfLore::WorldMap::BitmapFilenameToWorldBuilder("data/bitmaps/temple_of_water.png", 6.0, 1.25).build()
                                                )
         },
         { WORLD_OF_FIRE_IDENTIFIER,            LabyrinthOfLore::WorldMap::Level(
                                                   "World of Fire",
                                                   2.0f,
                                                   LabyrinthOfLore::WorldMap::BitmapFilenameToWorldBuilder("data/bitmaps/world_of_fire.png").build()
                                                )
         },
         { FINAL_TEMPLE_IDENTIFIER,             LabyrinthOfLore::WorldMap::Level(
                                                   "Final Temple",
                                                   2.0f,
                                                   LabyrinthOfLore::WorldMap::BitmapFilenameToWorldBuilder("data/bitmaps/final_temple.png").build()
                                                )
         },
         { VILLAGE_OF_THE_FORGOTTEN_IDENTIFIER, LabyrinthOfLore::WorldMap::Level(
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
         { 1, Door(THE_CAVE_IDENTIFIER, 32.5, 12.5, -5.0, 0.5) },
         { 2, Door(AN_ABANDONED_TEMPLE_IDENTIFIER, 19.5, 43.5, -5.0, 0.5) },
         { 3, Door(DUNGEON_OF_THE_CURSED_IDENTIFIER, 1.5, 24.5, -5.0, -0.25) },
         { 4, Door(TEMPLE_OF_WATER_IDENTIFIER, 55.5, 57.5, -5.0, 0.5) },
         { 11, Door(THE_UNDERWORLD_IDENTIFIER, 40.5, 87.5, levels[THE_UNDERWORLD_IDENTIFIER].get_ground_height()+0.001f, 0.5 ), },
         //{ 3, Door(DUNGEON_OF_THE_CURSED_IDENTIFIER, 0.0, 0.0, 0.0, 0.0) },
         //{ 4, Door(TEMPLE_OF_WATER_IDENTIFIER, 0.0, 0.0, 0.0, 0.0) },
         //{ 5, Door(WORLD_OF_FIRE_IDENTIFIER, 0.0, 0.0, 0.0, 0.0) },
         //{ 6, Door(FINAL_TEMPLE_IDENTIFIER, 0.0, 0.0, 0.0, 0.0) },
         //{ 7, Door(VILLAGE_OF_THE_FORGOTTEN_IDENTIFIER, 0.0, 0.0, 0.0, 0.0) },
         //{ 1, Door(THE_CAVE_IDENTIFIER, 0.0, 0.0, 0.0, 0.0) },
         //{ 2, Door(AN_ABANDONED_TEMPLE_IDENTIFIER, 0.0, 0.0, 0.0, 0.0) },
         //{ 3, Door(DUNGEON_OF_THE_CURSED_IDENTIFIER, 0.0, 0.0, 0.0, 0.0) },
         //{ 4, Door(TEMPLE_OF_WATER_IDENTIFIER, 0.0, 0.0, 0.0, 0.0) },
         //{ 5, Door(WORLD_OF_FIRE_IDENTIFIER, 0.0, 0.0, 0.0, 0.0) },
         //{ 6, Door(FINAL_TEMPLE_IDENTIFIER, 0.0, 0.0, 0.0, 0.0) },
         //{ 7, Door(VILLAGE_OF_THE_FORGOTTEN_IDENTIFIER, 0.0, 0.0, 0.0, 0.0) },
      };


      //
      //

      std::vector<LabyrinthOfLore::Entity::Base*> entities = {};
      LabyrinthOfLore::Rendering::Camera camera({0, 0, 0}, 0.0, 0.0);

      LabyrinthOfLore::Entity::Base* player_entity = new LabyrinthOfLore::Entity::Base;
      //player_entity->get_placement_ref().position = AllegroFlare::vec3d(1.5, 90.5, 1.01);

      float player_yaw = -0.04 - 0.5;
      float player_pitch = 0.0;
      float player_turning = 0.0;
      float max_player_turning_speed = 0.0023;
      float player_movement_magnitude = 0.0;

      int player_mouse_x = 0;
      int player_mouse_y = 0;

      player_entity->get_velocity_ref().position = {0.0, 0.0, 0.0};
      player_entity->get_placement_ref().position = {0.0, 0.0, 0.0};
      //player_entity->get_placement_ref().rotation = {2.5, 2.5, 0.0};

      //camera.get_position_ref() = player_entity->get_placement_ref().position + AllegroFlare::vec3d(0, 0, 0.65); //{5, 20, 2.01 + 0.5};

      entities.push_back(player_entity);

      //

      int x = 42;
      int y = 59;
      //int sprite_sheet_width = al_get_bitmap_width(item_tile_atlas.get_bitmap());
      int torch_id = 9*13+6;
      ALLEGRO_BITMAP *bitmap = item_tile_atlas.get_bitmap(9*13+6);
      LabyrinthOfLore::Entity::Base* entity = new LabyrinthOfLore::Entity::Base;
      entity->set_billboard_at_camera(true);
      entity->set_bitmap(bitmap);
      entity->get_placement_ref().size = AllegroFlare::vec3d(al_get_bitmap_width(bitmap), al_get_bitmap_height(bitmap), 0.0);
      entity->get_placement_ref().scale = AllegroFlare::vec3d(0.005, 0.005, 0.005);
      entity->get_placement_ref().align = AllegroFlare::vec3d(0.5, 1.0, 0.0);
      entity->get_placement_ref().position = AllegroFlare::vec3d(x + 0.5, y + 0.5, 3.01);
      //entity->get_placement_ref().rotation = AllegroFlare::vec3d(0, random.get_random_float(-1, 1), 0);
      entities.push_back(entity);

      Random random;

      for (int y=1; y<3; y++)
      {
         for (int x=1; x<3; x++)
         {
            LabyrinthOfLore::Entity::Base* entity = new LabyrinthOfLore::Entity::Base;
            entity->set_billboard_at_camera(true);
            entity->set_bitmap(item_tile_atlas.get_bitmap(9*8));
            entity->get_placement_ref().size = AllegroFlare::vec3d(al_get_bitmap_width(billboarding_tester_sprite), al_get_bitmap_height(billboarding_tester_sprite), 0.0);
            entity->get_placement_ref().scale = AllegroFlare::vec3d(0.005, 0.005, 0.005);
            entity->get_placement_ref().align = AllegroFlare::vec3d(0.5, 1.0, 0.0);
            entity->get_placement_ref().position = AllegroFlare::vec3d(x + 0.5, y + 0.5, 1.01);
            entity->get_placement_ref().rotation = AllegroFlare::vec3d(0, random.get_random_float(-1, 1), 0);
            //entity->get_placement_ref().rotation = AllegroFlare::vec3d(random.get_random_float(-1, 1), random.get_random_float(-1, 1), random.get_random_float(-1, 1));

            entities.push_back(entity);

            std::cout << "entity made " << std::endl;
         }
      }



      //

      LabyrinthOfLore::Hud::MessageScroll message_scroll;
      LabyrinthOfLore::Hud::CommandPanel command_panel;
      LabyrinthOfLore::Hud::VitalityAndManaBar vitality_and_mana_bar;
      LabyrinthOfLore::Hud::CharacterPanel character_panel;
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


      go_into_door(
         doors.at(11),
         player_entity,
         levels,
         meshes,
         player_yaw,
         current_tile_map,
         current_tile_map_mesh,
         title_text
      );



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
               int picked_id = game.picking_buffer.get_id(player_mouse_x/resolution_scale, player_mouse_y/resolution_scale);
               std::cout << "Picked ID: " << picked_id << std::endl;
               // observe clicked item, emit game events if needed 
               break;
            }
         case ALLEGRO_EVENT_KEY_DOWN:
            if (this_event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) shutdown_program = true;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_A) player_turning = -max_player_turning_speed;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_W) player_movement_magnitude = 0.022;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_D) player_turning = max_player_turning_speed;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_S) player_movement_magnitude = -0.022;

            if (this_event.keyboard.keycode == ALLEGRO_KEY_T) depth_darken_shader.toggle_torch();

            if (this_event.keyboard.keycode == ALLEGRO_KEY_1)
            {
               go_into_door(
                  doors.at(11),
                  player_entity,
                  levels,
                  meshes,
                  player_yaw,
                  current_tile_map,
                  current_tile_map_mesh,
                  title_text
               );
            }
            if (this_event.keyboard.keycode == ALLEGRO_KEY_0)
            {
               go_into_door( doors.at(4), player_entity, levels, meshes, player_yaw, current_tile_map, current_tile_map_mesh, title_text);
            }
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

               LabyrinthOfLore::Physics::GravityStepper gravity_stepper(entities);
               gravity_stepper.process_step();

               LabyrinthOfLore::Physics::EntityTileMapCollisionStepper entity_tile_map_collision_stepper(current_tile_map, entities);
               entity_tile_map_collision_stepper.process_step();

               // observe tile map collision events, emit game events if needed 
               std::vector<LabyrinthOfLore::Physics::EntityTileMapCollisionEvent> collision_stepper_events = entity_tile_map_collision_stepper.get_events_from_last_processed_step();
               LabyrinthOfLoreGame::EntityTileMapCollisionEventProcessor entity_tile_map_collision_event_processor(collision_stepper_events);

               camera.get_position_ref() = player_entity->get_placement_ref().position + AllegroFlare::vec3d(0, 0, 0.65);//{5, 20, 2.01 + 0.5};
               camera.get_yaw_ref() = player_yaw + 0.5;// + sin(al_get_time()) * 0.02;
               camera.get_pitch_ref() = player_pitch - 0.02;;// + sin((al_get_time()+2.345)*0.8534) * 0.02;

               //

               LabyrinthOfLore::Rendering::SpritesBillboarder sprites_billboarder(camera, entities);
               sprites_billboarder.process();

               //

               LabyrinthOfLore::Rendering::SceneRenderer scene_renderer(scene_rendering_surface, &camera, current_tile_map_mesh, entities, &depth_darken_shader);
               scene_renderer.render();

               //

               al_clear_depth_buffer(1);
               al_set_render_state(ALLEGRO_DEPTH_TEST, 1);
               LabyrinthOfLore::Rendering::PickingBufferRenderer picking_buffer_renderer(&game.picking_buffer, &camera, current_tile_map_mesh, entities, &clamped_color_shader);
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
      }

      al_save_bitmap("tmp/buffer_buffer.png", buffer_buffer);
      //al_save_bitmap("tmp/scene.png", scene_rendering_surface);
      //al_save_bitmap("tmp/picking.png", picking_buffer.get_surface_render());
   }

   return 0;
}


