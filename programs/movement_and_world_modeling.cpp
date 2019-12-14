#include <allegro5/allegro.h>

#include <LabyrinthOfLore/WorldMap/BasicRenderer.hpp>
#include <LabyrinthOfLore/WorldMap/Tile.hpp>
#include <LabyrinthOfLore/WorldMap/TileMapLoader.hpp>


std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> construct_tile_map_data = {
   { { 1, 100 }, { 1, 100 }, { 1, 100 }, { 1, 100 }, { 1, 100 }, { 1, 100 }, { 1, 100 }, { 1, 100 }, },
   { { 1, 100 },  { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 1, 100 }, },
   { { 1, 100 },  { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 1, 100 }, },
   { { 1, 100 },  { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 1, 100 }, },
   { { 1, 100 },  { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 1, 100 }, },
   { { 1, 100 },  { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 1, 100 }, },
   { { 1, 100 },  { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 1, 100 }, },
   { { 1, 100 },  { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 1, 100 }, },
   { { 1, 100 },  { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 1, 100 }, },
   { { 1, 100 },  { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 1, 100 }, },
   { { 1, 100 },  { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 1, 100 }, },
   { { 1, 100 },  { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 1, 100 }, },
   { { 1, 100 },  { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 1, 100 }, },
   { { 1, 100 },  { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 0, 10 }, { 1, 100 }, },
   { { 1, 100 }, { 1, 100 }, { 1, 100 }, { 1, 100 }, { 1, 100 }, { 1, 100 }, { 1, 100 }, { 1, 100 }, },
};


bool active = true;

int main(int argc, char **argv)
{
   if (active)
   {
      al_init();

      ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);

      LabyrinthOfLore::WorldMap::TileMap tile_map = LabyrinthOfLore::WorldMap::TileMapLoader(construct_tile_map_data).build_tile_map();
      LabyrinthOfLore::WorldMap::BasicRenderer tile_map_renderer(tile_map);

      tile_map_renderer.initialize();

      tile_map_renderer.render();

      al_flip_display();

      sleep(2);
   }

   return 0;
}

