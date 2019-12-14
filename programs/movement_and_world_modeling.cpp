#include <allegro5/allegro.h>

#include <LabyrinthOfLore/WorldMap/BasicRenderer.hpp>


bool active = false;

int main(int argc, char **argv)
{
   if (active)
   {
      al_init();

      ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);

      LabyrinthOfLore::WorldMap::BasicRenderer tile_map_renderer;

      tile_map_renderer.render();

      al_flip_display();

      sleep(2);
   }

   return 0;
}

