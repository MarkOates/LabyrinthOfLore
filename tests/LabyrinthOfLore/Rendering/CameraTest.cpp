
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/Camera.hpp>

TEST(LabyrinthOfLore_Rendering_CameraTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::Camera camera;
}

TEST(LabyrinthOfLore_Rendering_CameraTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Rendering::Camera camera;
   //std::string expected_string = "Hello World!";
   //EXPECT_EQ(expected_string, camera.run());
}

