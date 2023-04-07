
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


#include <LabyrinthOfLore/WorldMap/BitmapFilenameToWorldBuilder.hpp>


#include <LabyrinthOfLore/WorldMap/PixelRenderer.hpp>
#include <LabyrinthOfLore/WorldMap/TileMapLoader.hpp>


#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <AllegroFlare/Useful.hpp> // for TAU


class LabyrinthOfLore_WorldMap_BitmapFilenameToWorldBuilderTest : public ::testing::Test
{
protected:
   ALLEGRO_DISPLAY *display;
   float near_threshold;

   LabyrinthOfLore_WorldMap_BitmapFilenameToWorldBuilderTest()
      : display(nullptr)
      , near_threshold(0.0001f)
   {
   }

   virtual void SetUp() override
   {
      if (al_is_system_installed())
      {
         std::cout << "Warning: This test is expecting to start with allegro in an uninstalled state. "
            << "However, during this test's setup, it was detected that allegro is installed. "
            << "This indicates that somewhere there is a leaky test which should be fixed. But in the "
            << "mean time, allegro will be uninstalled now so that this test setup can continue as expected."
            << std::endl;
         al_uninstall_system();
      }
      ASSERT_EQ(true, al_init());
      ASSERT_EQ(true, al_init_primitives_addon());
      ASSERT_EQ(true, al_init_image_addon());

      //al_set_new_display_option(ALLEGRO_DEPTH_SIZE, 32, ALLEGRO_SUGGEST);
      //al_set_new_display_flags(ALLEGRO_OPENGL | ALLEGRO_PROGRAMMABLE_PIPELINE);
      //ASSERT_EQ(ALLEGRO_OPENGL, al_get_new_display_flags() & ALLEGRO_OPENGL);
      //ASSERT_EQ(ALLEGRO_PROGRAMMABLE_PIPELINE, al_get_new_display_flags() & ALLEGRO_PROGRAMMABLE_PIPELINE);

      ALLEGRO_DISPLAY *display = al_create_display(1920, 1920);
      ASSERT_NE(nullptr, display);
   }

   virtual void TearDown() override
   {
      if (al_get_current_display()) al_destroy_display(al_get_current_display());
      al_uninstall_system();
   }
};


TEST_F(LabyrinthOfLore_WorldMap_BitmapFilenameToWorldBuilderTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::WorldMap::BitmapFilenameToWorldBuilder the_underworld;
}


TEST_F(LabyrinthOfLore_WorldMap_BitmapFilenameToWorldBuilderTest, build__without_a_proper_bitmap_source_filename__raises_an_exception)
{
   std::string not_present_filename = "foo/bar/a_file_that_does_not_exist.php";
   LabyrinthOfLore::WorldMap::BitmapFilenameToWorldBuilder the_underworld(not_present_filename);

   std::string expected_error_message = "[BitmapFilenameToWorldBuilder::build]: error: was unable to load bitmap \"foo/bar/a_file_that_does_not_exist.php\" when calling build.";
   ASSERT_THROW_WITH_MESSAGE(the_underworld.build(), std::runtime_error, expected_error_message);
}


TEST_F(LabyrinthOfLore_WorldMap_BitmapFilenameToWorldBuilderTest, get_bitmap_source_filename__returns_the_expected_default_filename)
{
   LabyrinthOfLore::WorldMap::BitmapFilenameToWorldBuilder the_underworld;

   std::string expected_production_bitmap_location = "data/bitmaps/the_underworld.png";
   EXPECT_EQ(expected_production_bitmap_location, the_underworld.get_bitmap_source_filename());
}


TEST_F(LabyrinthOfLore_WorldMap_BitmapFilenameToWorldBuilderTest, build__returns_a_map_of_the_expected_width_and_height)
{
   std::string real_source_location = "/Users/markoates/Repos/LabyrinthOfLore/bin/";
   std::string bitmap_source_filename = "data/bitmaps/the_underworld.png";

   std::string full_source_location = real_source_location + bitmap_source_filename;

   LabyrinthOfLore::WorldMap::BitmapFilenameToWorldBuilder the_underworld(full_source_location);
   LabyrinthOfLore::WorldMap::TileMap tile_map = the_underworld.build();

   EXPECT_EQ(123, tile_map.get_width());
   EXPECT_EQ(108, tile_map.get_height());
}


TEST_F(LabyrinthOfLore_WorldMap_BitmapFilenameToWorldBuilderTest, build__has_a_0_tile_in_the_top_left)
{
   std::string real_source_location = "/Users/markoates/Repos/LabyrinthOfLore/bin/";
   std::string bitmap_source_filename = "data/bitmaps/the_underworld.png";

   std::string full_source_location = real_source_location + bitmap_source_filename;

   LabyrinthOfLore::WorldMap::BitmapFilenameToWorldBuilder the_underworld(full_source_location);
   LabyrinthOfLore::WorldMap::TileMap tile_map = the_underworld.build();

   EXPECT_EQ(0, tile_map.get_tile(0, 0).get_type());
}

//TEST_F(LabyrinthOfLore_Maps_BitmapFilenameToWorldBuilderTest, build__has_the_expected_elevation_at_the_sparting_place)
//{
   //std::string real_source_location = "/Users/markoates/Repos/LabyrinthOfLore/bin/";
   //std::string bitmap_source_filename = "data/bitmaps/the_underworld.png";

   //std::string full_source_location = real_source_location + bitmap_source_filename;

   //LabyrinthOfLore::Maps::BitmapFilenameToWorldBuilder the_underworld(full_source_location);
   //LabyrinthOfLore::WorldMap::TileMap tile_map = the_underworld.build();

   //EXPECT_EQ(1, tile_map.get_tile(40, 87).get_type());
//}




