#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include <allegro_flare/placement2d.h>

#include <LabyrinthOfLore/Rendering/SceneRenderer.hpp>
#include <AllegroFlare/Random.hpp>
#include <AllegroFlare/Useful.hpp> // for FULL_ROTATION
#include <AllegroFlare/Model3D.hpp>


bool active = true;

int main(int argc, char **argv)
{
   if (active)
   {
      al_init();
      al_init_image_addon();

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

      LabyrinthOfLore::Rendering::SceneRenderer scene_renderer(camera_placement, render_surface, entities);
      scene_renderer.prep_render();

      scene_renderer.render();


      al_flip_display();

      sleep(5);

      // cleanup
      for (auto &entity : entities) { delete entity; }
   }

   return 0;
}



