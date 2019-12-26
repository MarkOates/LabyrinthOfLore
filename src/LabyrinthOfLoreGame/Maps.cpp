

#include <LabyrinthOfLoreGame/Maps.hpp>



namespace LabyrinthOfLoreGame
{


Maps::Maps()
{
}


Maps::~Maps()
{
}


std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> Maps::build_construct_tile_map_data()
{
float topmost_wall_height = 2.0;

std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> construct_tile_map_data = {
   { { 1, topmost_wall_height }, { 1, topmost_wall_height }, { 1, topmost_wall_height }, { 1, topmost_wall_height }, { 1, topmost_wall_height }, { 1, topmost_wall_height }, { 1, topmost_wall_height }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0 },     { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0 },     { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0+0.25 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0+0.50 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0+0.75 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0+1.0 }, { 1, 1.0+5.0 }, { 1, 5.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0+1.25 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0+1.50 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0+1.75 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0+2.0 }, { 1, 1.0+5.0 }, { 1, 5.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0+2.25 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0+2.50 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0+2.75 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0+3.0 }, { 1, 1.0+5.0 }, { 1, 5.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0+3.25 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0+3.50 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0+3.75 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0+4.0 }, { 1, 1.0+5.0 }, { 1, 5.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0 },     { 1, 1.0 }, { 1, 5.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0 },     { 1, 1.0 }, { 1, 6.0 }, { 1, 1.0 }, { 1, 6.0 }, { 1, 6.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0 },     { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0 },     { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 2, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0 },     { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0 },     { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height },  { 1, 1.0 },     { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, 1.0 }, { 1, topmost_wall_height }, },
   { { 1, topmost_wall_height }, { 1, topmost_wall_height }, { 1, topmost_wall_height }, { 1, topmost_wall_height }, { 1, topmost_wall_height }, { 1, topmost_wall_height }, { 1, topmost_wall_height }, { 1, topmost_wall_height }, },
};

return construct_tile_map_data;

}
} // namespace LabyrinthOfLoreGame


