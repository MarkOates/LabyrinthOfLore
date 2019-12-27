
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


#include <LabyrinthOfLoreGame/Maps/TheUnderworld.hpp>


#include <LabyrinthOfLore/WorldMap/PixelRenderer.hpp>
#include <LabyrinthOfLore/WorldMap/TileMapLoader.hpp>


#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <AllegroFlare/Useful.hpp> // for TAU


class LabyrinthOfLoreGame_Maps_TheUnderworldTest : public ::testing::Test
{
protected:
   ALLEGRO_DISPLAY *display;
   float near_threshold;

   LabyrinthOfLoreGame_Maps_TheUnderworldTest()
      : display(nullptr)
      , near_threshold(0.0001f)
   {
   }

   virtual void SetUp() override
   {
      if (al_is_system_installed())
      {
         std::cout << "Warning: This test is expecting to start with allegro in an uninstalled state. "
            << "However, during test setup, allegro is installed. This should be fixed, but in the "
            << "mean time allegro will be uninstalled so that setup can continue as expected."
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


TEST_F(LabyrinthOfLoreGame_Maps_TheUnderworldTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLoreGame::Maps::TheUnderworld the_underworld;
}


TEST_F(LabyrinthOfLoreGame_Maps_TheUnderworldTest, build_the_underworld__without_a_proper_bitmap_source_filename__raises_an_exception)
{
   std::string not_present_filename = "foo/bar/a_file_that_does_not_exist.php";
   LabyrinthOfLoreGame::Maps::TheUnderworld the_underworld(not_present_filename);

   std::string expected_error_message = "was unable to load bitmap \"foo/bar/a_file_that_does_not_exist.php\" when calling build_the_underworld.";
   ASSERT_THROW_WITH_MESSAGE(the_underworld.build_the_underworld(), std::runtime_error, expected_error_message);
}


TEST_F(LabyrinthOfLoreGame_Maps_TheUnderworldTest, build_the_underworld__returns_a_map_of_the_expected_width_and_height)
{
   std::string real_source_location = "/Users/markoates/Repos/LabyrinthOfLore/bin/programs/";
   std::string bitmap_source_filename = "data/bitmaps/the_underworld.png";

   std::string full_source_location = real_source_location + bitmap_source_filename;

   LabyrinthOfLoreGame::Maps::TheUnderworld the_underworld(full_source_location);
   LabyrinthOfLore::WorldMap::TileMap tile_map = the_underworld.build_the_underworld();

   EXPECT_EQ(99, tile_map.get_width());
   EXPECT_EQ(90, tile_map.get_height());
}


