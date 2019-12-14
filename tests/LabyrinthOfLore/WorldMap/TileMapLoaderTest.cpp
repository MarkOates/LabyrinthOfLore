
#include <gtest/gtest.h>

#include <LabyrinthOfLore/WorldMap/TileMapLoader.hpp>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


TEST(LabyrinthOfLore_WorldMap_TileMapLoaderTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::WorldMap::TileMapLoader tile_map_loader;
}

TEST(LabyrinthOfLore_WorldMap_TileMapLoaderTest, load__raises_an_exception_if_the_passed_data_is_dimensionless)
{
   LabyrinthOfLore::WorldMap::TileMapLoader tile_map_loader;
   LabyrinthOfLore::WorldMap::TileMap expected_tile_map;

   std::string expected_error_message = "Attempting to load tilemap, but the passed tile_map_data is dimensionless";
   ASSERT_THROW_WITH_MESSAGE(tile_map_loader.load(), std::runtime_error, expected_error_message);
}

//TEST(LabyrinthOfLore_WorldMap_TileMapLoaderTest, load__returns_the_expected_response)
//{
   //LabyrinthOfLore::WorldMap::TileMapLoader tile_map_loader;
   //LabyrinthOfLore::WorldMap::TileMap expected_tile_map;

   //tile_map_loader.load();
//}

