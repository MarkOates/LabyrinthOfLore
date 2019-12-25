
#include <gtest/gtest.h>


#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


#include <LabyrinthOfLore/Shader/ClampedColor.hpp>
#include <AllegroFlare/ColorIDConverter.hpp>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro_flare/placement2d.h>


class LabyrinthOfLore_Shader_ClampedColorTest : public ::testing::Test
{
protected:
   ALLEGRO_DISPLAY *display;

   LabyrinthOfLore_Shader_ClampedColorTest()
      : display(nullptr)
   {
   }

   virtual void SetUp() override
   {
      ASSERT_EQ(false, al_is_system_installed());
      ASSERT_EQ(true, al_init());

      al_set_new_display_flags(ALLEGRO_OPENGL | ALLEGRO_PROGRAMMABLE_PIPELINE);
      ASSERT_EQ(ALLEGRO_OPENGL, al_get_new_display_flags() & ALLEGRO_OPENGL);
      ASSERT_EQ(ALLEGRO_PROGRAMMABLE_PIPELINE, al_get_new_display_flags() & ALLEGRO_PROGRAMMABLE_PIPELINE);
      ALLEGRO_DISPLAY *display = al_create_display(300, 200);
      ASSERT_NE(nullptr, display);
   }

   virtual void TearDown() override
   {
      if (al_get_current_display()) al_destroy_display(al_get_current_display());
      al_uninstall_system();
   }

   ALLEGRO_DISPLAY *get_display()
   {
      return display;
   }
};


TEST_F(LabyrinthOfLore_Shader_ClampedColorTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Shader::ClampedColor clamped_color_shader;
   SUCCEED();
}


TEST_F(LabyrinthOfLore_Shader_ClampedColorTest, activate__before_being_initialized_raises_an_exception)
{
   LabyrinthOfLore::Shader::ClampedColor clamped_color_shader;
   std::string expected_error_message = "[LabyrinthOfLore::Shader::ClampedColor] Attempting to activate() shader before it has been initialized";
   ASSERT_THROW_WITH_MESSAGE(clamped_color_shader.activate(), std::runtime_error, expected_error_message);
}


TEST_F(LabyrinthOfLore_Shader_ClampedColorTest, initialize__works_without_blowing_up)
{
   LabyrinthOfLore::Shader::ClampedColor clamped_color_shader;
   clamped_color_shader.initialize();
   SUCCEED();
}


TEST_F(LabyrinthOfLore_Shader_ClampedColorTest, activate__works_without_blowing_up)
{
   LabyrinthOfLore::Shader::ClampedColor clamped_color_shader;

   clamped_color_shader.initialize();
   clamped_color_shader.activate();
}


TEST_F(LabyrinthOfLore_Shader_ClampedColorTest, when_active__renders_the_image_with_the_expected_clamped_color)
{
   LabyrinthOfLore::Shader::ClampedColor clamped_color_shader;

   clamped_color_shader.initialize();
   clamped_color_shader.activate();

   al_init_image_addon();

   ALLEGRO_BITMAP *test_image = al_load_bitmap("/Users/markoates/Repos/LabyrinthOfLore/bin/programs/data/bitmaps/billboarding_tester_sprite.png");
   ASSERT_NE(nullptr, test_image);


   ALLEGRO_COLOR color = al_color_name("orange");

   clamped_color_shader.set_clamped_color(color);

   ALLEGRO_DISPLAY *current_display = al_get_current_display();
   ASSERT_NE(nullptr, current_display);

   allegro_flare::placement2d place(
         al_get_display_width(current_display)/2,
         al_get_display_height(current_display)/2,
         al_get_bitmap_width(test_image),
         al_get_bitmap_height(test_image));
   place.scale = AllegroFlare::vec2d(4, 4);
   place.start_transform();
   al_draw_bitmap(test_image, 0, 0, 0);
   place.restore_transform();


   ALLEGRO_COLOR expected_color = color;
   ALLEGRO_COLOR actual_color = al_get_pixel(al_get_backbuffer(current_display), al_get_display_width(current_display)/2, al_get_display_height(current_display)/2);

   ASSERT_EQ(color.r, actual_color.r);
   ASSERT_EQ(color.g, actual_color.g);
   ASSERT_EQ(color.b, actual_color.b);
   ASSERT_EQ(color.a, actual_color.a);

   std::string tmp_path = "/Users/markoates/Repos/LabyrinthOfLore/tmp/";
   std::string output_image_full_filename = tmp_path + "when_active__renders_the_image_with_the_expected_clamped_color.png";
   ASSERT_EQ(true, al_save_bitmap(output_image_full_filename.c_str(), al_get_backbuffer(current_display)));
}


TEST_F(LabyrinthOfLore_Shader_ClampedColorTest, when_active__only_renders_solid_and_non_solid_colors__aka_no_alphas)
{
   LabyrinthOfLore::Shader::ClampedColor clamped_color_shader;

   clamped_color_shader.initialize();
   clamped_color_shader.activate();

   al_init_image_addon();

   ALLEGRO_BITMAP *test_image = al_load_bitmap("/Users/markoates/Repos/LabyrinthOfLore/bin/programs/data/bitmaps/billboarding_tester_sprite.png");
   ASSERT_NE(nullptr, test_image);


   ALLEGRO_COLOR color = al_color_name("orange");
   ALLEGRO_COLOR black = al_color_name("black");

   clamped_color_shader.set_clamped_color(color);

   ALLEGRO_DISPLAY *current_display = al_get_current_display();
   ASSERT_NE(nullptr, current_display);

   int total_passes = 3;
   for (unsigned pass_num=0; pass_num<total_passes; pass_num++)
   {
      al_clear_to_color(al_color_name("black"));

      allegro_flare::placement2d place(
            al_get_display_width(current_display)/2,
            al_get_display_height(current_display)/2,
            al_get_bitmap_width(test_image),
            al_get_bitmap_height(test_image));
      place.scale = AllegroFlare::vec2d(4, 4);
      place.rotation = (float)pass_num / total_passes;
      place.start_transform();
      al_draw_bitmap(test_image, 0, 0, 0);
      place.restore_transform();

      ALLEGRO_BITMAP *surface = al_get_backbuffer(current_display);
      al_lock_bitmap(surface, ALLEGRO_PIXEL_FORMAT_ANY, ALLEGRO_LOCK_READONLY);
      for (unsigned y=0; y<al_get_bitmap_height(surface); y++)
      {
         for (unsigned x=0; x<al_get_bitmap_width(surface); x++)
         {
            ALLEGRO_COLOR expected_color = color;
            ALLEGRO_COLOR actual_color = al_get_pixel(surface, x, y);

            bool matches_color = false;
            bool matches_black = false;

            matches_color = actual_color.r == color.r && color.g == actual_color.g && color.b == actual_color.b && color.a == actual_color.a;
            matches_black = actual_color.r == black.r && black.g == actual_color.g && black.b == actual_color.b && black.a == actual_color.a;

            ASSERT_EQ(true, matches_color || matches_black);
         }
      }
      al_unlock_bitmap(surface);
   }

   std::string tmp_path = "/Users/markoates/Repos/LabyrinthOfLore/tmp/";
   std::string output_image_full_filename = tmp_path + "when_active__renders_the_image_with_the_expected_clamped_color.png";
   ASSERT_EQ(true, al_save_bitmap(output_image_full_filename.c_str(), al_get_backbuffer(current_display)));
}


TEST_F(LabyrinthOfLore_Shader_ClampedColorTest, when_active__is_able_to_render_the_entire_range_of_color_ids)
{
   LabyrinthOfLore::Shader::ClampedColor clamped_color_shader;

   clamped_color_shader.initialize();
   clamped_color_shader.activate();

   al_init_image_addon();

   ALLEGRO_BITMAP *test_image = al_load_bitmap("/Users/markoates/Repos/LabyrinthOfLore/bin/programs/data/bitmaps/billboarding_tester_sprite.png");
   ASSERT_NE(nullptr, test_image);


   ALLEGRO_COLOR color = al_color_name("orange");
   ALLEGRO_COLOR black = al_color_name("pink");

   clamped_color_shader.set_clamped_color(color);

   ALLEGRO_DISPLAY *current_display = al_get_current_display();
   ASSERT_NE(nullptr, current_display);

   int total_passes = AllegroFlare::ColorIDConverter::ID_MAX / 10000;
   ALLEGRO_BITMAP *surface = al_get_backbuffer(current_display);

   for (int color_id_num=0; color_id_num<total_passes; color_id_num++)
   {
      ALLEGRO_COLOR color = AllegroFlare::ColorIDConverter::encode_id(color_id_num);
      clamped_color_shader.set_clamped_color(color);

      al_draw_bitmap(test_image, 0, 0, 0);
      ALLEGRO_COLOR actual_color = al_get_pixel(surface, 0, 0);

      ASSERT_EQ(color.r, actual_color.r);
      ASSERT_EQ(color.g, actual_color.g);
      ASSERT_EQ(color.b, actual_color.b);
   }

   std::string tmp_path = "/Users/markoates/Repos/LabyrinthOfLore/tmp/";
   std::string output_image_full_filename = tmp_path + "when_active__all_ids.png";
   ASSERT_EQ(true, al_save_bitmap(output_image_full_filename.c_str(), al_get_backbuffer(current_display)));
}


