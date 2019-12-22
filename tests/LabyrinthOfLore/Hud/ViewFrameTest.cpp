
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Hud/ViewFrame.hpp>

TEST(LabyrinthOfLore_Hud_ViewFrameTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Hud::ViewFrame view_frame;
}

TEST(LabyrinthOfLore_Hud_ViewFrameTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Hud::ViewFrame view_frame;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, view_frame.run());
}
