
#include <gtest/gtest.h>

#include <LabyrinthOfLore/WorldMap/TileMap.hpp>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


TEST(LabyrinthOfLore_WorldMap_TileMapTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::WorldMap::TileMap tile_map;
}


TEST(LabyrinthOfLore_WorldMap_TileMapTest, get_tile__when_requesting_a_tile_outside_of_bounds__returns_a_minus1_type_tile)
{
   LabyrinthOfLore::WorldMap::TileMap tile_map;

   ASSERT_EQ(-1, tile_map.get_tile(-1, -1).get_type());
}


TEST(LabyrinthOfLore_WorldMap_TileMapTest, resize__will_fill_the_tiles_with_the_default_tile)
{
   LabyrinthOfLore::WorldMap::TileMap tile_map;
   tile_map.resize(10, 10);

   LabyrinthOfLore::WorldMap::Tile default_tile;
   ASSERT_EQ(default_tile.get_type(), tile_map.get_tile(3, 7).get_type());
   ASSERT_EQ(default_tile.get_height(), tile_map.get_tile(3, 7).get_height());
}


TEST(LabyrinthOfLore_WorldMap_TileMapTest, resize__will_fill_the_tiles_with_the_passed_tile)
{
   LabyrinthOfLore::WorldMap::TileMap tile_map;
   LabyrinthOfLore::WorldMap::Tile tile(7, 12.0);

   tile_map.resize(10, 10, tile);

   LabyrinthOfLore::WorldMap::Tile expected_tile = tile;
   LabyrinthOfLore::WorldMap::Tile actual_tile = tile_map.get_tile(3, 7);

   ASSERT_EQ(tile.get_type(), actual_tile.get_type());
   ASSERT_EQ(tile.get_height(), actual_tile.get_height());
}


