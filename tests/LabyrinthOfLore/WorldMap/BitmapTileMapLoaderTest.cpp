
#include <gtest/gtest.h>

#include <LabyrinthOfLore/WorldMap/BitmapTileMapLoader.hpp>

TEST(LabyrinthOfLore_WorldMap_BitmapTileMapLoaderTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::WorldMap::BitmapTileMapLoader bitmap_tile_map_loader;
}

TEST(LabyrinthOfLore_WorldMap_BitmapTileMapLoaderTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::WorldMap::BitmapTileMapLoader bitmap_tile_map_loader;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, bitmap_tile_map_loader.run());
}
