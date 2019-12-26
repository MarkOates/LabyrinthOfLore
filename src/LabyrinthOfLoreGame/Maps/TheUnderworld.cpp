

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
float ground_level = 1.0f;
float &_ = ground_level;

std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> construct_tile_map_data = {
   { { 1, t }, { 1, t }, { 1, t }, { 1, t }, { 1, t }, { 1, t }, { 1, t }, { 1, t }, },
   { { 1, t },  { 1, _ },      { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, _ },      { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, _ },      { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, _+0.25f }, { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 2, t }, },
   { { 1, t },  { 1, _+0.50f }, { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, 1.0 }, { 1, t }, },
   { { 1, t },  { 1, _+0.75f }, { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, _+_ },  { 1, _+5.0f }, { 1, 5.0 }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, _+1.25f }, { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, _+1.50f }, { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, _+1.75f }, { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, _+2.0f },  { 1, _+5.0f }, { 1, 5.0 }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, _+2.25f }, { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, _+2.50f }, { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, _+2.75f }, { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, _+3.0f },  { 1, _+5.0f }, { 1, 5.0 }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, _+3.25f }, { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, _+3.50f }, { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, _+3.75f }, { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, _+4.0f },  { 1, _+5.0f }, { 1, 5.0 }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, _ },      { 1, _ },     { 1, 5.0 }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, _ },      { 1, _ },     { 1, 6.0 }, { 1, _ }, { 1, 6.0 }, { 1, 6.0 }, { 1, t }, },
   { { 1, t },  { 1, _ },      { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, _ },      { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 2, t }, },
   { { 1, t },  { 1, _ },      { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, _ },      { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, _ },      { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
   { { 1, t },  { 1, t }, { 1, t }, { 1, t }, { 1, t }, { 1, t }, { 1, t }, { 1, t }, },
};

return construct_tile_map_data;

}
} // namespace Maps
} // namespace LabyrinthOfLoreGame


