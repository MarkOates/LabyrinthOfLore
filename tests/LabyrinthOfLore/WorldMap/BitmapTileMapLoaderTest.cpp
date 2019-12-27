
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

TEST(LabyrinthOfLore_WorldMap_BitmapTileMapLoaderTest, pick_color__with_a_valid_bitmap__picks_the_color)
{
   al_init();
   al_init_image_addon();

   ALLEGRO_BITMAP *source_bitmap = al_load_bitmap("/Users/markoates/Repos/LabyrinthOfLore/bin/programs/data/bitmaps/test_bitmap_tile_map_loader.png");
   ASSERT_NE(nullptr, source_bitmap);

   LabyrinthOfLore::WorldMap::BitmapTileMapLoader bitmap_tile_map_loader(source_bitmap);

   ALLEGRO_COLOR expected_color = al_color_html("6abe30");
   ALLEGRO_COLOR actual_color = bitmap_tile_map_loader.pick_color(0, 0);

   EXPECT_EQ_COLOR(expected_color, actual_color);

   al_uninstall_system();
   SUCCEED();
}

TEST(LabyrinthOfLore_WorldMap_BitmapTileMapLoaderTest, pick_index_I_color__returns_the_expected_value)
{
   al_init();
   al_init_image_addon();

   ALLEGRO_BITMAP *source_bitmap = al_load_bitmap("/Users/markoates/Repos/LabyrinthOfLore/bin/programs/data/bitmaps/test_bitmap_tile_map_loader.png");
   ASSERT_NE(nullptr, source_bitmap);

   LabyrinthOfLore::WorldMap::BitmapTileMapLoader bitmap_tile_map_loader(source_bitmap);

   ALLEGRO_COLOR expected_color;
   ALLEGRO_COLOR actual_color;

   expected_color = al_color_html("45283c");
   actual_color = bitmap_tile_map_loader.pick_index_null_color();
   EXPECT_EQ_COLOR(expected_color, actual_color);

   expected_color = al_color_html("ffffff");
   actual_color = bitmap_tile_map_loader.pick_index_top_color();
   EXPECT_EQ_COLOR(expected_color, actual_color);

   expected_color = al_color_html("6abe30");
   actual_color = bitmap_tile_map_loader.pick_index_ground_color();
   EXPECT_EQ_COLOR(expected_color, actual_color);

   al_uninstall_system();
   SUCCEED();
}

TEST(LabyrinthOfLore_WorldMap_BitmapTileMapLoaderTest, pick_index_G_color__returns_the_expected_height_colors)
{
   al_init();
   al_init_image_addon();

   ALLEGRO_BITMAP *source_bitmap = al_load_bitmap("/Users/markoates/Repos/LabyrinthOfLore/bin/programs/data/bitmaps/test_bitmap_tile_map_loader.png");
   ASSERT_NE(nullptr, source_bitmap);

   LabyrinthOfLore::WorldMap::BitmapTileMapLoader bitmap_tile_map_loader(source_bitmap);

   ALLEGRO_COLOR expected_color;
   ALLEGRO_COLOR actual_color;

   expected_color = al_color_html("5b6ee1");
   actual_color = bitmap_tile_map_loader.pick_index_gp_color();
   EXPECT_EQ_COLOR(expected_color, actual_color);

   expected_color = al_color_html("639bff");
   actual_color = bitmap_tile_map_loader.pick_index_gpp_color();
   EXPECT_EQ_COLOR(expected_color, actual_color);

   expected_color = al_color_html("5fcde4");
   actual_color = bitmap_tile_map_loader.pick_index_gppp_color();
   EXPECT_EQ_COLOR(expected_color, actual_color);

   expected_color = al_color_html("cbdbfc");
   actual_color = bitmap_tile_map_loader.pick_index_g1_color();
   EXPECT_EQ_COLOR(expected_color, actual_color);

   al_uninstall_system();
   SUCCEED();
}

