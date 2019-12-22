
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Hud/CommandPanel.hpp>

TEST(LabyrinthOfLore_Hud_CommandPanelTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Hud::CommandPanel command_panel;
}

TEST(LabyrinthOfLore_Hud_CommandPanelTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Hud::CommandPanel command_panel;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, command_panel.run());
}
