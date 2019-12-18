#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include <allegro_flare/placement2d.h>

#include <LabyrinthOfLore/Rendering/SceneRenderer.hpp>
#include <LabyrinthOfLore/Rendering/PickingBufferRenderer.hpp>
#include <LabyrinthOfLore/Rendering/Camera.hpp>
#include <AllegroFlare/Random.hpp>
#include <AllegroFlare/Useful.hpp> // for FULL_ROTATION
#include <AllegroFlare/Model3D.hpp>



class SceneUpdater
{
private:
   allegro_flare::placement3d &camera_placement;
   LabyrinthOfLore::Rendering::Camera &camera;

public:
   SceneUpdater(allegro_flare::placement3d &camera_placement, LabyrinthOfLore::Rendering::Camera &camera)
      : camera_placement(camera_placement)
      , camera(camera)
   {}

   void update()
   {
      camera.get_position_ref().z = 0.5;
      camera.get_position_ref().x += 0.002;
      camera.get_yaw_ref() -= 0.0001;
      camera.get_pitch_ref() = sin(al_get_time()*0.5) * 0.01;
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
      al_set_new_display_flags(ALLEGRO_OPENGL | ALLEGRO_PROGRAMMABLE_PIPELINE);
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

      float pos_min = -6;
      float pos_max = 6;
      for (unsigned i=0; i<20; i++)
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


      for (int z=-3; z<3; z++)
      {
         for (int x=-3; x<3; x++)
         {
            LabyrinthOfLore::Entity::Base* entity_with_model = new LabyrinthOfLore::Entity::Base;
            entity_with_model->set_bitmap(world_model_texture);
            entity_with_model->set_model(&world_model);
            entity_with_model->get_placement_ref().position = AllegroFlare::vec3d(x*3, 0, z*3);
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



      AllegroFlare::PickingBuffer picking_buffer(al_get_display_width(display), al_get_display_height(display), 32);
      picking_buffer.initialize();
      LabyrinthOfLore::Shader::ClampedColor clamped_color_shader;
      clamped_color_shader.initialize();


      LabyrinthOfLore::Rendering::Camera camera;


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

               //LabyrinthOfLore::Rendering::PickingBufferRenderer picking_buffer_renderer(&picking_buffer, camera_placement, entities, &clamped_color_shader);
               //picking_buffer_renderer.render();

               //al_save_bitmap("/Users/markoates/Repos/LabyrinthOfLore/tmp/regular_render.png", render_surface);
               //al_save_bitmap("/Users/markoates/Repos/LabyrinthOfLore/tmp/picking_render.png", picking_buffer.get_surface_render());
               //shutdown_program = true;

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




