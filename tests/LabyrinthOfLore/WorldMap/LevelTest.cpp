
#include <gtest/gtest.h>

#include <LabyrinthOfLore/WorldMap/Level.hpp>

TEST(LabyrinthOfLore_WorldMap_LevelTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::WorldMap::Level level;
}

TEST(LabyrinthOfLore_WorldMap_LevelTest, has_the_expected_getters_with_the_expected_defaults)
{
   LabyrinthOfLore::WorldMap::Level level;

   EXPECT_EQ("Level 0", level.get_heading());
   EXPECT_EQ("Unmade World", level.get_name());
   EXPECT_EQ(1, level.get_ground_height());
   //EXPECT_EQ(LabyrinthOfLore::WorldMap::TileMap(), level.get_tile_map());
   //EXPECT_EQ(LabyrinthOfLore::Rendering::TileMapMesh(), level.get_tile_map_mesh());
}
