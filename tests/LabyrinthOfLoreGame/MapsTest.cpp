
#include <gtest/gtest.h>

#include <LabyrinthOfLoreGame/Maps.hpp>

TEST(LabyrinthOfLoreGame_MapsTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLoreGame::Maps maps;
}

TEST(LabyrinthOfLoreGame_MapsTest, run__returns_the_expected_response)
{
   LabyrinthOfLoreGame::Maps maps;
   std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> actual_construct_tile_map_data = maps.build_construct_tile_map_data();
}
