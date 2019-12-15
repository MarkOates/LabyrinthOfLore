#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include <allegro_flare/placement2d.h>

#include <LabyrinthOfLore/Rendering/SceneRenderer.hpp>
#include <AllegroFlare/Random.hpp>
#include <AllegroFlare/Useful.hpp> // for FULL_ROTATION
#include <AllegroFlare/Model3D.hpp>


void look_at(AllegroFlare::vec3d target)
{
}

void look_at(allegro_flare::placement3d &camera_placement, AllegroFlare::vec3d target)
{
   //view_vector = (target - camera_placement.position).normalized();
   //camera_placement.rotation = (target - camera_placement.position).normalized();
}


class SceneUpdater
{
private:
   allegro_flare::placement3d &camera_placement;
   int start_time_offset;

public:
   SceneUpdater(allegro_flare::placement3d &camera_placement)
      : camera_placement(camera_placement)
      , start_time_offset(4566432) // to make the movements less in sync
   {}

   void update()
   {
      camera_placement.position = AllegroFlare::vec3d(
            sin(al_get_time()+start_time_offset),
            sin((al_get_time()+start_time_offset)*0.81527),
            5+sin((al_get_time()+start_time_offset)*0.71527)
         );
      camera_placement.rotation = AllegroFlare::vec3d(
            sin(al_get_time()+start_time_offset)*0.05,
            sin(al_get_time()+start_time_offset)*0.05,
            sin(al_get_time()+start_time_offset)*0.05
         );
      //look_at(camera_placement, AllegroFlare::vec3d(0, 0, 0));
   }
};



bool active = true;

int main(int argc, char **argv)
{
   if (active)
   {
      al_init();
      al_init_image_addon();


      // setup the world objects

      // set a few options and flags
      al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 2, ALLEGRO_SUGGEST);
      al_set_new_display_option(ALLEGRO_DEPTH_SIZE, 32, ALLEGRO_SUGGEST);
      al_set_new_display_option(ALLEGRO_SAMPLES, 16, ALLEGRO_SUGGEST);
      //al_set_new_display_flags(display_flags);
      ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);

      ALLEGRO_BITMAP *billboard_tester_sprite = al_load_bitmap("bin/programs/data/bitmaps/billboarding_tester_sprite.png");
      if (!billboard_tester_sprite) throw std::runtime_error("could not load billboard_tester_sprite");

      AllegroFlare::Model3D world_model;
      world_model.load_obj_file("bin/programs/data/models/unit_cube-01.obj", 1.0);
      //if (!world_model) throw std::runtime_error("could not load unit_cube-01"); // not available when world_model is a solid
      ALLEGRO_BITMAP *world_model_texture = al_load_bitmap("bin/programs/data/bitmaps/unit_cube-01b.png");
      if (!world_model_texture) throw std::runtime_error("could not load world_model_texture");

      AllegroFlare::Random random;

      allegro_flare::placement3d camera_placement(0, 0, 5);
      std::vector<LabyrinthOfLore::Entity::Base*> entities = {};

      float pos_min = -3;
      float pos_max = 3;
      for (unsigned i=0; i<10; i++)
      {
         LabyrinthOfLore::Entity::Base* entity = new LabyrinthOfLore::Entity::Base;
         entity->set_bitmap(billboard_tester_sprite);
         entity->set_billboard_at_camera(true);
         entity->get_placement_ref().position = AllegroFlare::vec3d(
               random.get_random_int(pos_min, pos_max),
               random.get_random_int(pos_min, pos_max),
               random.get_random_int(pos_min, pos_max)
            );
         entity->get_placement_ref().rotation = AllegroFlare::vec3d(
               random.get_random_float(0, AllegroFlare::FULL_ROTATION),
               random.get_random_float(0, AllegroFlare::FULL_ROTATION),
               random.get_random_float(0, AllegroFlare::FULL_ROTATION)
            );
         entity->get_placement_ref().scale = AllegroFlare::vec3d(0.01, 0.01, 0.01);

         entities.push_back(entity);
      }

      LabyrinthOfLore::Entity::Base* world_entity = new LabyrinthOfLore::Entity::Base;
      world_entity->set_bitmap(world_model_texture);
      world_entity->set_model(&world_model);

      entities.push_back(world_entity);


      ALLEGRO_BITMAP *render_surface = al_get_backbuffer(display);


      // run the simulation

      ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

      al_install_keyboard();
      al_register_event_source(event_queue, al_get_keyboard_event_source());

      ALLEGRO_TIMER *primary_timer = al_create_timer(1.0/60.0);
      al_register_event_source(event_queue, al_get_timer_event_source(primary_timer));
      al_start_timer(primary_timer);

      bool shutdown_program = false;

      while(!shutdown_program)
      {
         ALLEGRO_EVENT this_event;
         al_wait_for_event(event_queue, &this_event);

         switch(this_event.type)
         {
         case ALLEGRO_EVENT_DISPLAY_CLOSE:
            shutdown_program = true;
            break;
         case ALLEGRO_EVENT_KEY_DOWN:
            shutdown_program = true;
            break;
         case ALLEGRO_EVENT_TIMER:
            {
               SceneUpdater scene_updater(camera_placement);
               scene_updater.update();

               LabyrinthOfLore::Rendering::SceneRenderer scene_renderer(camera_placement, render_surface, entities);
               scene_renderer.prep_render();
               scene_renderer.render();
               al_flip_display();
            }
            break;
         }
      }

      //sleep(5);

      // cleanup
      for (auto &entity : entities) { delete entity; }
   }

   return 0;
}



