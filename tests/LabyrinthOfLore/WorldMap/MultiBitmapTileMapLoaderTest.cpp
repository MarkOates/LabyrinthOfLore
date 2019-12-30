
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

   std::string expected_message = "could not WorldBitmap::MultiBitmapTileMapLoader.load with a nullptr tile_map.";
   ASSERT_THROW_WITH_MESSAGE(bitmap_tile_map_loader.load_and_process(), std::runtime_error, expected_message);
}

TEST(LabyrinthOfLore_WorldMap_MultiBitmapTileMapLoaderTest, load_and_process__throws_an_exception_if_there_is_a_nullptr_source_bitmap)
{
   LabyrinthOfLore::WorldMap::TileMap *tile_map = new LabyrinthOfLore::WorldMap::TileMap();
   ALLEGRO_BITMAP *source_bitmap = nullptr;

   LabyrinthOfLore::WorldMap::MultiBitmapTileMapLoader bitmap_tile_map_loader(tile_map, source_bitmap);

   std::string expected_message = "could not WorldBitmap::MultiBitmapTileMapLoader.load with a nullptr source_bitmap.";
   ASSERT_THROW_WITH_MESSAGE(bitmap_tile_map_loader.load_and_process(), std::runtime_error, expected_message);

   delete tile_map;
}

TEST(LabyrinthOfLore_WorldMap_MultiBitmapTileMapLoaderTest, load_and_process__throws_an_exception_if_the_tile_map_dimensions_do_not_match_the_bitmap_dimensions)
{
   al_init();

   LabyrinthOfLore::WorldMap::TileMap tile_map;
   tile_map.resize(7, 9);
   ALLEGRO_BITMAP *source_bitmap = al_create_bitmap(tile_map.get_width()+1, tile_map.get_height());

   LabyrinthOfLore::WorldMap::MultiBitmapTileMapLoader bitmap_tile_map_loader(&tile_map, source_bitmap);

   std::string expected_message = "Could not WorldBitmap::MultiBitmapTileMapLoader.load with a tile_map and source_bitmap that are of different dimensions. The bitmap is (8,9) (-2 width, btw) and the tile_map is (7,9)";
   ASSERT_THROW_WITH_MESSAGE(bitmap_tile_map_loader.load_and_process(), std::runtime_error, expected_message);

   al_destroy_bitmap(source_bitmap);
   al_uninstall_system();
}

TEST(LabyrinthOfLore_WorldMap_MultiBitmapTileMapLoaderTest, load__with_a_valid_bitmap__succeeds)
{
   al_init();
   al_init_image_addon();

   LabyrinthOfLore::WorldMap::TileMap tile_map;
   tile_map.resize(50, 67);
   ALLEGRO_BITMAP *source_bitmap = al_load_bitmap("/Users/markoates/Repos/LabyrinthOfLore/bin/programs/data/bitmaps/test_bitmap_tile_map_loader-multi.png");
   ASSERT_NE(nullptr, source_bitmap);

   LabyrinthOfLore::WorldMap::MultiBitmapTileMapLoader bitmap_tile_map_loader(&tile_map, source_bitmap);
   LabyrinthOfLore::WorldMap::TileMap actual_tile_map = bitmap_tile_map_loader.load_and_process();

   al_uninstall_system();
   SUCCEED();
}

TEST(LabyrinthOfLore_WorldMap_MultiBitmapTileMapLoaderTest, pick_color__with_a_valid_bitmap__picks_the_color)
{
   al_init();
   al_init_image_addon();

   LabyrinthOfLore::WorldMap::TileMap tile_map;
   tile_map.resize(49, 66);
   ALLEGRO_BITMAP *source_bitmap = al_load_bitmap("/Users/markoates/Repos/LabyrinthOfLore/bin/programs/data/bitmaps/test_bitmap_tile_map_loader-multi.png");
   ASSERT_NE(nullptr, source_bitmap);

   LabyrinthOfLore::WorldMap::MultiBitmapTileMapLoader bitmap_tile_map_loader(&tile_map, source_bitmap);

   ALLEGRO_COLOR expected_color = al_color_html("45283c");
   ALLEGRO_COLOR actual_color = bitmap_tile_map_loader.pick_color(0, 0);

   EXPECT_EQ_COLOR(expected_color, actual_color);

   al_uninstall_system();
   SUCCEED();
}

