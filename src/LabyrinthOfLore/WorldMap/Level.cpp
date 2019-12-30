

#include <LabyrinthOfLore/WorldMap/Level.hpp>



namespace LabyrinthOfLore
{
namespace WorldMap
{


Level::Level(std::string heading, std::string name, float ground_height, LabyrinthOfLore::WorldMap::TileMap tile_map, LabyrinthOfLore::Rendering::TileMapMesh tile_map_mesh)
   : heading(heading)
   , name(name)
   , ground_height(ground_height)
   , tile_map(tile_map)
   , tile_map_mesh(tile_map_mesh)
{
}


Level::~Level()
{
}


std::string Level::get_heading()
{
   return heading;
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


LabyrinthOfLore::Rendering::TileMapMesh Level::get_tile_map_mesh()
{
   return tile_map_mesh;
}


} // namespace WorldMap
} // namespace LabyrinthOfLore


