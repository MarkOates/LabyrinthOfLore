
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


#include <allegro5/allegro.h>

#define FLOATING_POINT_ERROR_MARGIN (0.00001f)

static void EXPECT_EQ_COLOR(ALLEGRO_COLOR expected, ALLEGRO_COLOR actual)
{
   EXPECT_EQ(expected.r, actual.r);
   EXPECT_EQ(expected.g, actual.g);
   EXPECT_EQ(expected.b, actual.b);
   EXPECT_EQ(expected.a, actual.a);
}


#include <LabyrinthOfLore/WorldMap/MultiBitmapTileMapLoader.hpp>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

TEST(LabyrinthOfLore_WorldMap_MultiBitmapTileMapLoaderTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::WorldMap::MultiBitmapTileMapLoader bitmap_tile_map_loader;
}

TEST(LabyrinthOfLore_WorldMap_MultiBitmapTileMapLoaderTest, load_and_process__throws_an_exception_if_there_is_a_nullptr_tile_map)
{
   LabyrinthOfLore::WorldMap::TileMap *tile_map = nullptr;
   ALLEGRO_BITMAP *source_bitmap = nullptr;

   LabyrinthOfLore::WorldMap::MultiBitmapTileMapLoader bitmap_tile_map_loader(tile_map, source_bitmap);

   std::string expected_message = "could WorldBitmap::MultiBitmapTileMapLoader.load with a nullptr tile_map.";
   ASSERT_THROW_WITH_MESSAGE(bitmap_tile_map_loader.load_and_process(), std::runtime_error, expected_message);
}

TEST(LabyrinthOfLore_WorldMap_MultiBitmapTileMapLoaderTest, load_and_process__throws_an_exception_if_there_is_a_nullptr_source_bitmap)
{
   LabyrinthOfLore::WorldMap::TileMap *tile_map = new LabyrinthOfLore::WorldMap::TileMap();
   ALLEGRO_BITMAP *source_bitmap = nullptr;

   LabyrinthOfLore::WorldMap::MultiBitmapTileMapLoader bitmap_tile_map_loader(tile_map, source_bitmap);

   std::string expected_message = "could WorldBitmap::MultiBitmapTileMapLoader.load with a nullptr source_bitmap.";
   ASSERT_THROW_WITH_MESSAGE(bitmap_tile_map_loader.load_and_process(), std::runtime_error, expected_message);

   delete tile_map;
}

//TEST(LabyrinthOfLore_WorldMap_MultiBitmapTileMapLoaderTest, load_and_process__throws_an_exception_if_there_is_a_nullptr_source_bitmap)
//{
   //LabyrinthOfLore::WorldMap::TileMap *tile_map = nullptr;
   //ALLEGRO_BITMAP *source_bitmap = nullptr;

   //LabyrinthOfLore::WorldMap::MultiBitmapTileMapLoader bitmap_tile_map_loader(tile_map, source_bitmap);

   //std::string expected_message = "could WorldBitmap::MultiBitmapTileMapLoader.load with a nullptr source_bitmap";
   //ASSERT_THROW_WITH_MESSAGE(bitmap_tile_map_loader.load_and_process(), std::runtime_error, expected_message);
//}

