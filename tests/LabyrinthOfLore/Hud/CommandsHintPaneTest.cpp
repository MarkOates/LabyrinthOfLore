
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Hud/CommandsHintPane.hpp>

TEST(LabyrinthOfLore_Hud_CommandsHintPaneTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Hud::CommandsHintPane commands_hint_pane;
}

TEST(LabyrinthOfLore_Hud_CommandsHintPaneTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Hud::CommandsHintPane commands_hint_pane;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, commands_hint_pane.run());
}
