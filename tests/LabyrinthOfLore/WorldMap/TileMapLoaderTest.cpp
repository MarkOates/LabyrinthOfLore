
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

TEST(LabyrinthOfLore_WorldMap_TileMapLoaderTest, build_tile_map__builds_a_tile_map_with_the_expected_dimensions)
{
   std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> tile_data = {
      { { 1, 100 }, { 4, 100 }, { 3, 90 }, },
      { { 12, 40 }, { 0, 20 },  { 9, 100 }, },
      { { 1, 70 },  { 15, 40 }, { 16, 100 }, },
      { { 1, 100 }, { 3, 60 },  { 11, 100 }, },
   };

   LabyrinthOfLore::WorldMap::TileMap tile_map = LabyrinthOfLore::WorldMap::TileMapLoader(tile_data).build_tile_map();

   EXPECT_EQ(3, tile_map.get_width());
   EXPECT_EQ(4, tile_map.get_height());
}

TEST(LabyrinthOfLore_WorldMap_TileMapLoaderTest, build_tile_map__builds_a_tile_map_with_the_expected_tile_types)
{
   std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> tile_data = {
      { { 1, 100 }, { 4, 100 }, { 3, 90 }, },
      { { 12, 40 }, { 0, 20 },  { 9, 100 }, },
      { { 1, 70 },  { 15, 40 }, { 16, 30 }, },
      { { 1, 100 }, { 3, 60 },  { 11, 100 }, },
   };

   LabyrinthOfLore::WorldMap::TileMap tile_map = LabyrinthOfLore::WorldMap::TileMapLoader(tile_data).build_tile_map();

   EXPECT_EQ(1, tile_map.get_tile(0, 0).get_type());
   EXPECT_EQ(4, tile_map.get_tile(1, 0).get_type());
   EXPECT_EQ(3, tile_map.get_tile(2, 0).get_type());

   EXPECT_EQ(12, tile_map.get_tile(0, 1).get_type());
   EXPECT_EQ(0, tile_map.get_tile(1, 1).get_type());
   EXPECT_EQ(9, tile_map.get_tile(2, 1).get_type());

   EXPECT_EQ(1, tile_map.get_tile(0, 2).get_type());
   EXPECT_EQ(15, tile_map.get_tile(1, 2).get_type());
   EXPECT_EQ(16, tile_map.get_tile(2, 2).get_type());

   EXPECT_EQ(1, tile_map.get_tile(0, 3).get_type());
   EXPECT_EQ(3, tile_map.get_tile(1, 3).get_type());
   EXPECT_EQ(11, tile_map.get_tile(2, 3).get_type());
}

TEST(LabyrinthOfLore_WorldMap_TileMapLoaderTest, build_tile_map__builds_a_tile_map_with_the_expected_tile_heights)
{
   std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> tile_data = {
      { { 1, 100 }, { 4, 100 }, { 3, 90 }, },
      { { 12, 40 }, { 0, 20 },  { 9, 100 }, },
      { { 1, 70 },  { 15, 40 }, { 16, 30 }, },
      { { 1, 100 }, { 3, 60 },  { 11, 100 }, },
   };

   LabyrinthOfLore::WorldMap::TileMap tile_map = LabyrinthOfLore::WorldMap::TileMapLoader(tile_data).build_tile_map();

   EXPECT_EQ(100, tile_map.get_tile(0, 0).get_height());
   EXPECT_EQ(100, tile_map.get_tile(1, 0).get_height());
   EXPECT_EQ(90, tile_map.get_tile(2, 0).get_height());

   EXPECT_EQ(40, tile_map.get_tile(0, 1).get_height());
   EXPECT_EQ(20, tile_map.get_tile(1, 1).get_height());
   EXPECT_EQ(100, tile_map.get_tile(2, 1).get_height());

   EXPECT_EQ(70, tile_map.get_tile(0, 2).get_height());
   EXPECT_EQ(40, tile_map.get_tile(1, 2).get_height());
   EXPECT_EQ(30, tile_map.get_tile(2, 2).get_height());

   EXPECT_EQ(100, tile_map.get_tile(0, 3).get_height());
   EXPECT_EQ(60, tile_map.get_tile(1, 3).get_height());
   EXPECT_EQ(100, tile_map.get_tile(2, 3).get_height());
}

