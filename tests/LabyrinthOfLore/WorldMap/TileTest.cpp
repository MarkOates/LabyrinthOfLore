
#include <gtest/gtest.h>

#include <LabyrinthOfLore/WorldMap/Tile.hpp>

TEST(LabyrinthOfLore_WorldMap_TileTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::WorldMap::Tile tile;
}

TEST(LabyrinthOfLore_WorldMap_TileTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::WorldMap::Tile tile;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, tile.run());
}

