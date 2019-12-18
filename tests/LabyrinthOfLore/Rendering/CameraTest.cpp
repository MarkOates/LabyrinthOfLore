
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


#include <LabyrinthOfLore/Rendering/Camera.hpp>


TEST(LabyrinthOfLore_Rendering_CameraTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::Camera camera;
}


TEST(LabyrinthOfLore_Rendering_CameraTest, start_projection__with_a_nullptr_surface_raises_an_exception)
{
   LabyrinthOfLore::Rendering::Camera camera;

   std::string expected_message = "[Camera::start_projection] error: cannot set the projection on nullptr surface";
   ASSERT_THROW_WITH_MESSAGE(camera.start_projection(), std::runtime_error, expected_message);
}


