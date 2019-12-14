
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

TEST(LabyrinthOfLore_WorldMap_TileMapLoaderTest, build_tile_map__works_successfully)
{
   std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> tile_data = {
      { { 1, 100 }, { 1, 100 }, { 1, 100 }, },
      { { 1, 100 }, { 0, 10 }, { 1, 100 }, },
      { { 1, 100 }, { 0, 10 }, { 1, 100 }, },
      { { 1, 100 }, { 1, 100 }, { 1, 100 }, },
   };

   LabyrinthOfLore::WorldMap::TileMapLoader tile_map_loader(tile_data);

   tile_map_loader.build_tile_map();
}

TEST(LabyrinthOfLore_WorldMap_TileMapLoaderTest, build_tile_map__raises_an_exception_if_the_passed_data_is_dimensionless)
{
   LabyrinthOfLore::WorldMap::TileMapLoader tile_map_loader;

   std::string expected_error_message = "Attempting to load tilemap, but the passed tile_map_data is dimensionless";
   ASSERT_THROW_WITH_MESSAGE(tile_map_loader.build_tile_map(), std::runtime_error, expected_error_message);
}

TEST(LabyrinthOfLore_WorldMap_TileMapLoaderTest, build_tile_map__raises_an_exception_if_the_passed_data_does_not_have_the_same_number_of_columns_in_each_row)
{
   std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> uneven_tile_data = {
      { { 1, 100 }, { 1, 100 }, { 1, 100 }, },
      { { 0, 10 }, },
      { { 0, 10 }, { 0, 10 } },
      { { 1, 100 }, { 1, 100 }, { 1, 100 }, },
   };

   LabyrinthOfLore::WorldMap::TileMapLoader tile_map_loader(uneven_tile_data);

   std::string expected_error_message = "Attempting to load tilemap, but the number of columns is uneven among all of the rows.";
   ASSERT_THROW_WITH_MESSAGE(tile_map_loader.build_tile_map(), std::runtime_error, expected_error_message);
}

