
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


#include <LabyrinthOfLore/Rendering/Camera.hpp>


class LabyrinthOfLore_Rendering_CameraTest : public ::testing::Test
{
protected:
   ALLEGRO_DISPLAY *display;

   LabyrinthOfLore_Rendering_CameraTest()
      : display(nullptr)
   {
   }

   virtual void SetUp() override
   {
      ASSERT_EQ(false, al_is_system_installed());
      ASSERT_EQ(true, al_init());

      ALLEGRO_DISPLAY *display = al_create_display(800, 600);
      ASSERT_NE(nullptr, display);
   }

   virtual void TearDown() override
   {
      if (display) al_destroy_display(display);
      al_uninstall_system();
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


