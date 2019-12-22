
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Hud/RotateCharacterPanelButton.hpp>

TEST(LabyrinthOfLore_Hud_RotateCharacterPanelButtonTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Hud::RotateCharacterPanelButton rotate_character_panel_button;
}

TEST(LabyrinthOfLore_Hud_RotateCharacterPanelButtonTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Hud::RotateCharacterPanelButton rotate_character_panel_button;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, rotate_character_panel_button.run());
}
