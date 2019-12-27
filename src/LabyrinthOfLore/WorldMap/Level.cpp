

#include <LabyrinthOfLore/WorldMap/Level.hpp>



namespace LabyrinthOfLore
{
namespace WorldMap
{


Level::Level(std::string name, float ground_height, LabyrinthOfLore::WorldMap::TileMap tile_map)
   : name(name)
   , ground_height(ground_height)
   , tile_map(tile_map)
{
}


Level::~Level()
{
}


std::string Level::get_name()
{
   return name;
}


float Level::get_ground_height()
{
   return ground_height;
}


LabyrinthOfLore::WorldMap::TileMap Level::get_tile_map()
{
   return tile_map;
}


} // namespace WorldMap
} // namespace LabyrinthOfLore


