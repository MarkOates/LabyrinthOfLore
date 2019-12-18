#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include <allegro_flare/placement2d.h>

#include <LabyrinthOfLore/Rendering/SceneRenderer.hpp>
#include <AllegroFlare/Random.hpp>
#include <AllegroFlare/Useful.hpp> // for FULL_ROTATION
#include <AllegroFlare/Model3D.hpp>



class SceneUpdater
{
private:
   allegro_flare::placement3d &camera_placement;
   LabyrinthOfLore::Rendering::Camera &camera;
   int start_time_offset;

public:
   SceneUpdater(allegro_flare::placement3d &camera_placement, LabyrinthOfLore::Rendering::Camera &camera)
      : camera_placement(camera_placement)
      , camera(camera)
      , start_time_offset(4566432) // to make the movements less in sync
   {}

   void update()
   {
      camera_placement.position = AllegroFlare::vec3d(
            sin(al_get_time()+start_time_offset),
            0.5 + sin((al_get_time()+start_time_offset)*0.81527),
            5 * sin((al_get_time()+start_time_offset)*0.71527)
         );
      camera_placement.rotation = AllegroFlare::vec3d(
            0, //sin(al_get_time()+start_time_offset)*0.1,
            sin(al_get_time()*0.2+start_time_offset)*1.0, // turning left and right (good), this is what the player controls for rotation
            0
            //sin(al_get_time()+start_time_offset)*0.1
         );

      camera.get_position_ref() = camera_placement.position;
      camera.get_yaw_ref() = -camera_placement.rotation.y;
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

      LabyrinthOfLore::Rendering::Camera camera;

      float pos_min = -20;
      float pos_max = 20;
      for (unsigned i=0; i<100; i++)
      {
         LabyrinthOfLore::Entity::Base* entity = new LabyrinthOfLore::Entity::Base;
         entity->set_bitmap(billboard_tester_sprite);
         entity->set_billboard_at_camera(true);
         entity->get_placement_ref().position = AllegroFlare::vec3d(
               random.get_random_int(pos_min, pos_max),
               0.5,
               random.get_random_int(pos_min, pos_max)
               //random.get_random_int(pos_min, pos_max)
            );
         entity->get_placement_ref().rotation = AllegroFlare::vec3d(
               random.get_random_float(0, AllegroFlare::FULL_ROTATION),
               random.get_random_float(0, AllegroFlare::FULL_ROTATION),
               random.get_random_float(0, AllegroFlare::FULL_ROTATION)
            );
         entity->get_placement_ref().scale = AllegroFlare::vec3d(0.02, 0.02, 0.02);

         entities.push_back(entity);
      }


      for (int z=-5; z<5; z++)
      {
         for (int x=-5; x<5; x++)
         {
            LabyrinthOfLore::Entity::Base* entity_with_model = new LabyrinthOfLore::Entity::Base;
            entity_with_model->set_bitmap(world_model_texture);
            entity_with_model->set_model(&world_model);
            entity_with_model->get_placement_ref().position = AllegroFlare::vec3d(x*4, 0, z*4);
            entities.push_back(entity_with_model);
         }
      }


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
            if (this_event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) shutdown_program = true;
            break;
         case ALLEGRO_EVENT_TIMER:
            {
               SceneUpdater scene_updater(camera_placement, camera);
               scene_updater.update();

               LabyrinthOfLore::Rendering::SceneRenderer scene_renderer(camera_placement, render_surface, entities, &camera);
               scene_renderer.render();
               al_flip_display();
            }
            break;
         }
      }

      // cleanup
      for (auto &entity : entities) { delete entity; }
   }

   return 0;
}



