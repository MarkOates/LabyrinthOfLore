#include <allegro5/allegro.h>

#include <LabyrinthOfLore/Entity/Base.hpp>
#include <LabyrinthOfLore/WorldMap/Tile.hpp>
#include <LabyrinthOfLore/WorldMap/TileMapLoader.hpp>
#include <LabyrinthOfLore/Rendering/SceneRenderer.hpp>
#include <LabyrinthOfLore/Rendering/TileMapMesh.hpp>
#include <LabyrinthOfLore/Physics/GravityStepper.hpp>
#include <LabyrinthOfLore/Physics/EntityTileMapCollisionStepper.hpp>
#include <allegro_flare/placement2d.h>
#include <cmath>


std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> construct_tile_map_data = {
   { { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+0.25 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+0.50 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+0.75 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+1.0 }, { 0, 1.0+5.0 }, { 0, 5.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+1.25 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+1.50 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+1.75 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+2.0 }, { 0, 1.0+5.0 }, { 0, 5.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+2.25 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+2.50 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+2.75 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+3.0 }, { 0, 1.0+5.0 }, { 0, 5.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+3.25 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+3.50 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+3.75 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+4.0 }, { 0, 1.0+5.0 }, { 0, 5.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 5.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 6.0 }, { 0, 1.0 }, { 0, 6.0 }, { 0, 6.0 }, { 2, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, },
};


class TileEntitiesBuilder
{
private:
   LabyrinthOfLore::WorldMap::TileMap &tile_map;
   AllegroFlare::Model3D cube_model;
   ALLEGRO_BITMAP *cube_texture;

public:
   TileEntitiesBuilder(LabyrinthOfLore::WorldMap::TileMap &tile_map)
      : tile_map(tile_map)
      , cube_model()
      , cube_texture(nullptr)
   {}
   ~TileEntitiesBuilder() {}

   void initialize()
   {
      cube_model.load_obj_file("data/models/unit_cube-01.obj", 1.0);
      cube_texture = al_load_bitmap("data/bitmaps/unit_cube-01b.png");
   }

   std::vector<LabyrinthOfLore::Entity::Base*> build_entities()
   {
      std::vector<LabyrinthOfLore::Entity::Base*> entities = {};

      for (unsigned y=0; y<tile_map.get_height(); y++)
      {
         for (unsigned x=0; x<tile_map.get_width(); x++)
         {
            int tile_type = tile_map.get_tile(x, y).get_type();
            float tile_height = tile_map.get_tile(x, y).get_height();
            LabyrinthOfLore::Entity::Base* entity = new LabyrinthOfLore::Entity::Base;

            entity->get_placement_ref().position = AllegroFlare::vec3d(x, tile_height, y);
            entity->set_model(&cube_model);
            entity->set_bitmap(cube_texture);

            entities.push_back(entity);
         }
      }

      return entities;
   }
};


bool active = true;

int main(int argc, char **argv)
{
   if (active)
   {
      al_init();
      al_init_image_addon();
      //al_init_path_addon();

      ALLEGRO_PATH *resource_path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
      al_change_directory(al_path_cstr(resource_path, ALLEGRO_NATIVE_PATH_SEP));
      al_destroy_path(resource_path);

      // set a few options and flags
      al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 2, ALLEGRO_SUGGEST);
      al_set_new_display_option(ALLEGRO_DEPTH_SIZE, 32, ALLEGRO_SUGGEST);
      al_set_new_display_option(ALLEGRO_SAMPLES, 16, ALLEGRO_SUGGEST);
      al_set_new_display_flags(ALLEGRO_RESIZABLE | ALLEGRO_OPENGL | ALLEGRO_PROGRAMMABLE_PIPELINE);

      ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);


      std::vector<LabyrinthOfLore::Entity::Base*> entities = {};
      LabyrinthOfLore::Rendering::Camera camera({0, 0, 0}, 0.0, 0.0);

      //

      LabyrinthOfLore::WorldMap::TileMap tile_map = LabyrinthOfLore::WorldMap::TileMapLoader(construct_tile_map_data).build_tile_map();

      //

      TileEntitiesBuilder tile_entities_builder(tile_map);
      tile_entities_builder.initialize();
      entities = tile_entities_builder.build_entities();

      LabyrinthOfLore::Entity::Base* camera_entity = new LabyrinthOfLore::Entity::Base;
      camera_entity->get_placement_ref().position = AllegroFlare::vec3d(1.5, 1.5, 1.01);

      entities.push_back(camera_entity);

      LabyrinthOfLore::Rendering::TileMapMesh tile_map_mesh(tile_map);
      tile_map_mesh.build();


      //


      bool shutdown_program = false;

      ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

      al_install_keyboard();
      al_register_event_source(event_queue, al_get_keyboard_event_source());

      ALLEGRO_TIMER *primary_timer = al_create_timer(1.0/60.0);
      al_register_event_source(event_queue, al_get_timer_event_source(primary_timer));
      al_start_timer(primary_timer);


      //

      float player_yaw = 0.0;
      float player_pitch = 0.0;
      camera_entity->get_velocity_ref().position = {0.0, 0.06, 0};
      camera_entity->get_placement_ref().rotation = {0.0, 0.0, 0.0};

      while(!shutdown_program)
      {
         ALLEGRO_EVENT this_event, next_event;
         al_wait_for_event(event_queue, &this_event);

         switch(this_event.type)
         {
         case ALLEGRO_EVENT_DISPLAY_CLOSE:
            shutdown_program = true;
            break;
         case ALLEGRO_EVENT_KEY_DOWN:
            if (this_event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) shutdown_program = true;
            break;
         case ALLEGRO_EVENT_TIMER:
            {
               LabyrinthOfLore::Physics::GravityStepper gravity_stepper(entities);
               gravity_stepper.process_step();

               LabyrinthOfLore::Physics::EntityTileMapCollisionStepper entity_tile_map_collision_stepper(tile_map, entities);
               entity_tile_map_collision_stepper.process_step();

               camera.get_position_ref() = camera_entity->get_placement_ref().position + AllegroFlare::vec3d(0, 0, 0.5);//{5, 20, 2.01 + 0.5};
               camera.get_yaw_ref() = player_yaw + 0.5 + sin(al_get_time()) * 0.02;
               camera.get_pitch_ref() = player_pitch + sin((al_get_time()+2.345)*0.8534) * 0.02;

               LabyrinthOfLore::Rendering::SceneRenderer scene_renderer(al_get_backbuffer(display), &camera, tile_map_mesh, entities);
               scene_renderer.render();

               al_flip_display();
            }
            while (al_peek_next_event(event_queue, &next_event)
                  && next_event.type == ALLEGRO_EVENT_TIMER
                  && next_event.timer.source == this_event.timer.source)
               al_drop_next_event(event_queue);
         }
      }
   }

   return 0;
}


