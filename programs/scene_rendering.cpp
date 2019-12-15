#include <allegro5/allegro.h>

#include <allegro_flare/placement2d.h>

#include <LabyrinthOfLore/Rendering/SceneRenderer.hpp>


bool active = true;

int main(int argc, char **argv)
{
   if (active)
   {
      al_init();

      ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);

      allegro_flare::placement3d camera_placement;
      std::vector<LabyrinthOfLore::Entity::Base*> entities = {};

      float pos_min = -10;
      float pos_max = 10;
      for (unsigned i=0; i<10; i++)
      {
         entities.push_back(new LabyrinthOfLore::Entity::Base);
      }

      ALLEGRO_BITMAP *render_surface = al_get_backbuffer(display);

      LabyrinthOfLore::Rendering::SceneRenderer scene_renderer(camera_placement, render_surface, entities);
      scene_renderer.prep_render();

      scene_renderer.render();


      al_flip_display();

      sleep(1);
   }

   return 0;
}



