

#include <LabyrinthOfLoreGame/Maps/TheUnderworld.hpp>
#include <LabyrinthOfLore/WorldMap/TileMapLoader.hpp>


namespace LabyrinthOfLoreGame
{
namespace Maps
{


TheUnderworld::TheUnderworld()
{
}


TheUnderworld::~TheUnderworld()
{
}


LabyrinthOfLore::WorldMap::TileMap TheUnderworld::build_the_underworld()
{
return LabyrinthOfLore::WorldMap::TileMapLoader(build_the_underworld_data()).build_tile_map();
}

std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> TheUnderworld::build_the_underworld_data()
{
float topmost_wall_height = 2.0;
float &t = topmost_wall_height;
float floor_level = 0.0f;
float &_ = floor_level;
float ground_level = 6.0f;
float &g = ground_level;
int level_number_doors_start = 20;

int D0 = level_number_doors_start + 0;
int D1 = level_number_doors_start + 1;
int D2 = level_number_doors_start + 2;
int D3 = level_number_doors_start + 3;
int D4 = level_number_doors_start + 4;
int D5 = level_number_doors_start + 5;
int D6 = level_number_doors_start + 6;
int D7 = level_number_doors_start + 7;
int D8 = level_number_doors_start + 8;
int D9 = level_number_doors_start + 9;

return {};

}
} // namespace Maps
} // namespace LabyrinthOfLoreGame


