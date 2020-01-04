#include <allegro5/allegro.h>

#include <LabyrinthOfLore/WorldMap/BasicRenderer.hpp>
#include <LabyrinthOfLore/WorldMap/Tile.hpp>
#include <LabyrinthOfLore/WorldMap/TileMapLoader.hpp>
#include <allegro_flare/placement2d.h>


std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> construct_tile_map_data = {
   { { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 2.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 3.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 4.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 5.0 }, { 0, 5.0 }, { 0, 5.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 }, { 0, 1.0 }, { 0, 5.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 }, { 0, 1.0 }, { 0, 6.0 }, { 0, 1.0 }, { 0, 6.0 }, { 0, 6.0 }, { 2, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, },
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

      allegro_flare::placement2d place(1920/2, 1080/2, tile_map.get_width() * 32, tile_map.get_height() * 32);
      place.align = AllegroFlare::vec2d(0.5, 0.5);

      place.start_transform();
      tile_map_renderer.render();
      place.restore_transform();

      al_flip_display();

      sleep(2);
   }

   return 0;
}

