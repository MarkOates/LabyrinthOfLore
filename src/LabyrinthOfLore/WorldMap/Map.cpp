

#include <LabyrinthOfLore/WorldMap/Map.hpp>



namespace LabyrinthOfLore
{
namespace WorldMap
{


Map::Map(std::string name, LabyrinthOfLore::WorldMap::TileMap tile_map)
   : name(name)
   , tile_map(tile_map)
{
}


Map::~Map()
{
}


std::string Map::get_name()
{
   return name;
}


LabyrinthOfLore::WorldMap::TileMap Map::get_tile_map()
{
   return tile_map;
}


} // namespace WorldMap
} // namespace LabyrinthOfLore


