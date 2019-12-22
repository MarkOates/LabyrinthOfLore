
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/Hud/RotateCharacterPanelButtonRenderer.hpp>

TEST(LabyrinthOfLore_Rendering_Hud_RotateCharacterPanelButtonRendererTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::Hud::RotateCharacterPanelButtonRenderer rotate_character_panel_button_renderer;
}

TEST(LabyrinthOfLore_Rendering_Hud_RotateCharacterPanelButtonRendererTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Rendering::Hud::RotateCharacterPanelButtonRenderer rotate_character_panel_button_renderer;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, rotate_character_panel_button_renderer.run());
}
