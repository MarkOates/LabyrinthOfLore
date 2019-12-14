

#include <LabyrinthOfLore/WorldMap/BasicRenderer.hpp>
#include <allegro5/allegro_primitives.h>
#include <LabyrinthOfLore/WorldMap/Tile.hpp>


namespace LabyrinthOfLore
{
namespace WorldMap
{


BasicRenderer::BasicRenderer()
   : tile_map({})
   , tile_height_map({})
{
}


BasicRenderer::~BasicRenderer()
{
}


void BasicRenderer::intialize()
{
al_init_primitives_addon();

}

void BasicRenderer::render()
{
for (unsigned y=0; y<tile_map.get_height(); y++)
  for (unsigned x=0; x<tile_map.get_width(); x++)
   {
      int tile_index_num = tile_map.get_tile(x, y);
      int tile_height = tile_height_map.get_tile(x, y);
      LabyrinthOfLore::WorldMap::Tile tile(tile_index_num, (float)tile_height / 3);
   }
return;

}
} // namespace WorldMap
} // namespace LabyrinthOfLore


