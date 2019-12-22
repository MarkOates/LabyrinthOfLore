
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Hud/CharacterPanel.hpp>

TEST(LabyrinthOfLore_Hud_CharacterPanelTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Hud::CharacterPanel character_panel;
}

TEST(LabyrinthOfLore_Hud_CharacterPanelTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Hud::CharacterPanel character_panel;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, character_panel.run());
}
