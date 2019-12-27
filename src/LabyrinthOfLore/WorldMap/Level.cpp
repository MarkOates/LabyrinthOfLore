

#include <LabyrinthOfLore/WorldMap/Level.hpp>



namespace LabyrinthOfLore
{
namespace WorldMap
{


Level::Level(std::string name, LabyrinthOfLore::WorldMap::TileMap tile_map)
   : name(name)
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


LabyrinthOfLore::WorldMap::TileMap Level::get_tile_map()
{
   return tile_map;
}


} // namespace WorldMap
} // namespace LabyrinthOfLore


