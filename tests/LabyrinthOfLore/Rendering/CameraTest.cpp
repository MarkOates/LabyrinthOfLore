
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


#include <LabyrinthOfLore/Rendering/Camera.hpp>


#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <AllegroFlare/Useful.hpp> // for TAU


class LabyrinthOfLore_Rendering_CameraTest : public ::testing::Test
{
protected:
   ALLEGRO_DISPLAY *display;
   float near_threshold;

   LabyrinthOfLore_Rendering_CameraTest()
      : display(nullptr)
      , near_threshold(0.0001f)
   {
   }

   virtual void SetUp() override
   {
      if (!al_is_system_installed())
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

      ALLEGRO_DISPLAY *display = al_create_display(800, 600);
      ASSERT_NE(nullptr, display);
   }

   virtual void TearDown() override
   {
      if (display) al_destroy_display(display);
      al_uninstall_system();
   }

   void draw_targets()
   {
      float x = 0;
      float y = 0;
      float size = 0.3;
      al_draw_filled_rectangle(-size+x, -size+y, size+x, size+y, al_color_name("white"));

      x = 1;
      y = 0;
      al_draw_filled_rectangle(-size+x, -size+y, size+x, size+y, al_color_name("yellow"));

      x = -1;
      y = 0;
      al_draw_filled_rectangle(-size+x, -size+y, size+x, size+y, al_color_name("orange"));

      x = -2;
      y = 0;
      al_draw_filled_rectangle(-size+x, -size+y, size+x, size+y, al_color_name("cyan"));

      x = 1;
      y = -1;
      al_draw_filled_rectangle(-size+x, -size+y, size+x, size+y, al_color_name("chartreuse"));

      x = 1;
      y = -2;
      al_draw_filled_rectangle(-size+x, -size+y, size+x, size+y, al_color_name("green"));

      x = 0;
      y = 1;
      al_draw_filled_rectangle(-size+x, -size+y, size+x, size+y, al_color_name("pink"));

      x = 0;
      y = -2;
      al_draw_filled_rectangle(-size+x, -size+y, size+x, size+y, al_color_name("olive"));
   }

   void ASSERT_CENTRAL_PIXEL_MATCHES(ALLEGRO_BITMAP *surface, ALLEGRO_COLOR expected_color)
   {
      ASSERT_NE(nullptr, surface);
      ALLEGRO_COLOR actual_color = al_get_pixel(surface, al_get_bitmap_width(surface)/2, al_get_bitmap_height(surface)/2);
      EXPECT_NEAR(expected_color.r, actual_color.r, near_threshold);
      EXPECT_NEAR(expected_color.g, actual_color.g, near_threshold);
      EXPECT_NEAR(expected_color.b, actual_color.b, near_threshold);
      EXPECT_NEAR(expected_color.a, actual_color.a, near_threshold);
   }
};


TEST_F(LabyrinthOfLore_Rendering_CameraTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::Camera camera;
   SUCCEED();
}


TEST_F(LabyrinthOfLore_Rendering_CameraTest, start_projection__with_a_nullptr_surface_raises_an_exception)
{
   LabyrinthOfLore::Rendering::Camera camera;

   std::string expected_message = "[Camera::start_projection] error: cannot set the projection on nullptr surface";
   ASSERT_THROW_WITH_MESSAGE(camera.start_projection(), std::runtime_error, expected_message);
}


TEST_F(LabyrinthOfLore_Rendering_CameraTest, start_projection__with_a_valid_surface__does_not_blow_up)
{
   LabyrinthOfLore::Rendering::Camera camera;

   ALLEGRO_BITMAP *surface = al_create_bitmap(800, 600);
   ASSERT_NE(nullptr, surface);

   camera.start_projection(surface);

   al_destroy_bitmap(surface);
   SUCCEED();
}


TEST_F(LabyrinthOfLore_Rendering_CameraTest, start_projection__displaces_the_perspective_by_the_horizontal_position_right)
{
   ALLEGRO_BITMAP *surface = al_get_backbuffer(al_get_current_display());

   al_set_target_bitmap(surface);
   al_clear_to_color(al_color_name("brown"));

   LabyrinthOfLore::Rendering::Camera camera(AllegroFlare::vec3d(1, 2, 0));
   camera.start_projection(surface);

   draw_targets();

   ASSERT_CENTRAL_PIXEL_MATCHES(surface, al_color_name("yellow"));

   al_save_bitmap("tmp/save_test.png", surface);
   SUCCEED();
}


TEST_F(LabyrinthOfLore_Rendering_CameraTest, start_projection__displaces_the_perspective_by_the_horizontal_position_left)
{
   ALLEGRO_BITMAP *surface = al_get_backbuffer(al_get_current_display());

   al_set_target_bitmap(surface);
   al_clear_to_color(al_color_name("brown"));

   LabyrinthOfLore::Rendering::Camera camera(AllegroFlare::vec3d(-1, 2, 0));
   camera.start_projection(surface);

   draw_targets();

   ASSERT_CENTRAL_PIXEL_MATCHES(surface, al_color_name("orange"));

   al_save_bitmap("tmp/save_test.png", surface);
   SUCCEED();
}


TEST_F(LabyrinthOfLore_Rendering_CameraTest, start_projection__rotates_the_perspective_by_positive_yaw_right)
{
   ALLEGRO_BITMAP *surface = al_get_backbuffer(al_get_current_display());

   al_set_target_bitmap(surface);
   al_clear_to_color(al_color_name("brown"));

   LabyrinthOfLore::Rendering::Camera camera(AllegroFlare::vec3d(0, 1, 0), 0.125);
   camera.start_projection(surface);

   draw_targets();

   ASSERT_CENTRAL_PIXEL_MATCHES(surface, al_color_name("yellow"));

   al_save_bitmap("tmp/save_test.png", surface);
   SUCCEED();
}


TEST_F(LabyrinthOfLore_Rendering_CameraTest, start_projection__rotates_the_perspective_by_positive_pitch_up)
{
   ALLEGRO_BITMAP *surface = al_get_backbuffer(al_get_current_display());

   al_set_target_bitmap(surface);
   al_clear_to_color(al_color_name("brown"));

   LabyrinthOfLore::Rendering::Camera camera(AllegroFlare::vec3d(0, 1, 0), 0.0, 0.125);
   camera.start_projection(surface);

   draw_targets();

   ASSERT_CENTRAL_PIXEL_MATCHES(surface, al_color_name("pink"));

   al_save_bitmap("tmp/save_test.png", surface);
   SUCCEED();
}


TEST_F(LabyrinthOfLore_Rendering_CameraTest, start_projection__rotates_the_perspective_by_pitch_and_yaw_in_the_correct_order)
{
   ALLEGRO_BITMAP *surface = al_get_backbuffer(al_get_current_display());

   al_set_target_bitmap(surface);
   al_clear_to_color(al_color_name("brown"));

   LabyrinthOfLore::Rendering::Camera camera(AllegroFlare::vec3d(0, 1, 0), 0.12f, -0.12f); // kinda fudged here
   camera.start_projection(surface);

   draw_targets();

   ASSERT_CENTRAL_PIXEL_MATCHES(surface, al_color_name("chartreuse"));

   al_save_bitmap("tmp/save_test.png", surface);
   SUCCEED();
}


TEST_F(LabyrinthOfLore_Rendering_CameraTest, start_projection__observes_at_180_rotations)
{
   ALLEGRO_BITMAP *surface = al_get_backbuffer(al_get_current_display());

   al_set_target_bitmap(surface);
   al_clear_to_color(al_color_name("brown"));

   LabyrinthOfLore::Rendering::Camera camera(AllegroFlare::vec3d(0, -1, 0), 0.5);
   camera.start_projection(surface);

   draw_targets();

   ASSERT_CENTRAL_PIXEL_MATCHES(surface, al_color_name("white"));

   al_save_bitmap("tmp/save_test.png", surface);
   SUCCEED();
}


TEST_F(LabyrinthOfLore_Rendering_CameraTest, start_projection__observes_at_complex_rotations)
{
   ALLEGRO_BITMAP *surface = al_get_backbuffer(al_get_current_display());

   al_set_target_bitmap(surface);
   al_clear_to_color(al_color_name("brown"));

   LabyrinthOfLore::Rendering::Camera camera(AllegroFlare::vec3d(-2, -2, 1), 0.5-0.125, -0.125);
   camera.start_projection(surface);

   draw_targets();

   ASSERT_CENTRAL_PIXEL_MATCHES(surface, al_color_name("olive"));

   al_save_bitmap("tmp/save_test.png", surface);
   SUCCEED();
}



