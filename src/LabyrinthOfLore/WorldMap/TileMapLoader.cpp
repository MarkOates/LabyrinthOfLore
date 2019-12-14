

#include <LabyrinthOfLore/WorldMap/TileMapLoader.hpp>
#include <LabyrinthOfLore/WorldMap/TileMap.hpp>


namespace LabyrinthOfLore
{
namespace WorldMap
{


TileMapLoader::TileMapLoader(std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> tile_map_data)
   : tile_map_data(tile_map_data)
{
}


TileMapLoader::~TileMapLoader()
{
}


void TileMapLoader::validate_size_and_integrity()
{
if (tile_map_data.size() == 0)
{
   throw std::runtime_error("Attempting to load tilemap, but the passed tile_map_data is dimensionless");
}

int expected_size = tile_map_data.size();
for (int i=0; i<tile_map_data.size(); i++)
{
   if (tile_map_data[i].size() != expected_size)
   {
      throw std::runtime_error("Attempting to load tilemap, but the number of columns is uneven among all of the rows.");
   }
}

}

LabyrinthOfLore::WorldMap::TileMap TileMapLoader::build_tile_map()
{
validate_size_and_integrity();

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


