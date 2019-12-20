
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/MousePointer.hpp>

TEST(LabyrinthOfLore_Rendering_MousePointerTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::MousePointer mouse_pointer;
}

TEST(LabyrinthOfLore_Rendering_MousePointerTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Rendering::MousePointer mouse_pointer;
   //std::string expected_string = "Hello World!";
   //EXPECT_EQ(expected_string, mouse_pointer.run());
}
