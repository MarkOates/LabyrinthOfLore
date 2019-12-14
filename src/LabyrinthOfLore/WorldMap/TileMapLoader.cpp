

#include <LabyrinthOfLore/WorldMap/TileMapLoader.hpp>
#include <LabyrinthOfLore/WorldMap/TileMap.hpp>


namespace LabyrinthOfLore
{
namespace WorldMap
{


TileMapLoader::TileMapLoader()
   : tile_map_data({})
{
}


TileMapLoader::~TileMapLoader()
{
}


LabyrinthOfLore::WorldMap::TileMap TileMapLoader::load()
{
if (tile_map_data.size() == 0)
{
   throw std::runtime_error("Attempting to load tilemap, but the passed tile_map_data is dimensionless");
}

int width = tile_map_data.size();
int height = tile_map_data[0].size();

LabyrinthOfLore::WorldMap::TileMap result;
result.resize(width, height);

for (unsigned y=0; y<width; y++)
{
   for (unsigned x=0; x<height; x++)
   {
      result.set_tile(x, y, tile_map_data[y][x]);
   }
}

return result;

}
} // namespace WorldMap
} // namespace LabyrinthOfLore


