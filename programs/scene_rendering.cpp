#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include <allegro_flare/placement2d.h>

#include <LabyrinthOfLore/Rendering/SceneRenderer.hpp>
#include <AllegroFlare/Random.hpp>
#include <AllegroFlare/Useful.hpp> // for FULL_ROTATION


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

      AllegroFlare::Random random;

      allegro_flare::placement3d camera_placement(0, 0, 50);
      std::vector<LabyrinthOfLore::Entity::Base*> entities = {};

      float pos_min = -20;
      float pos_max = 20;
      for (unsigned i=0; i<10; i++)
      {
         LabyrinthOfLore::Entity::Base* entity = new LabyrinthOfLore::Entity::Base;
         entity->set_bitmap(billboard_tester_sprite);
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
         entity->get_placement_ref().scale = AllegroFlare::vec3d(0.1, 0.1, 0.1);

         entities.push_back(entity);
      }

      ALLEGRO_BITMAP *render_surface = al_get_backbuffer(display);

      LabyrinthOfLore::Rendering::SceneRenderer scene_renderer(camera_placement, render_surface, entities);
      scene_renderer.prep_render();

      scene_renderer.render();


      al_flip_display();

      sleep(5);
   }

   return 0;
}



