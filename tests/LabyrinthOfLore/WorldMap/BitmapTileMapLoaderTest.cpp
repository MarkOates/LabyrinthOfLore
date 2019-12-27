
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <LabyrinthOfLore/WorldMap/BitmapTileMapLoader.hpp>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

TEST(LabyrinthOfLore_WorldMap_BitmapTileMapLoaderTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::WorldMap::BitmapTileMapLoader bitmap_tile_map_loader;
}

TEST(LabyrinthOfLore_WorldMap_BitmapTileMapLoaderTest, load__throws_an_exception_if_there_is_a_nullptr_source_bitmap)
{
   ALLEGRO_BITMAP *source_bitmap = nullptr;

   LabyrinthOfLore::WorldMap::BitmapTileMapLoader bitmap_tile_map_loader(source_bitmap);

   std::string expected_message = "could WorldBitmap::BitmapTileMapLoader.load with a nullptr source_bitmap";
   ASSERT_THROW_WITH_MESSAGE(bitmap_tile_map_loader.load(), std::runtime_error, expected_message);
}

TEST(LabyrinthOfLore_WorldMap_BitmapTileMapLoaderTest, load__with_a_valid_bitmap__succeeds)
{
   al_init();
   al_init_image_addon();

   ALLEGRO_BITMAP *source_bitmap = al_load_bitmap("/Users/markoates/Repos/LabyrinthOfLore/bin/programs/data/bitmaps/test_bitmap_tile_map_loader.png");
   ASSERT_NE(nullptr, source_bitmap);

   LabyrinthOfLore::WorldMap::BitmapTileMapLoader bitmap_tile_map_loader(source_bitmap);
   LabyrinthOfLore::WorldMap::TileMap actual_tile_map = bitmap_tile_map_loader.load();

   al_uninstall_system();
   SUCCEED();
}

