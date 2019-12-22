
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/Hud/CharacterPanelRenderer.hpp>

TEST(LabyrinthOfLore_Rendering_Hud_CharacterPanelRendererTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::Hud::CharacterPanelRenderer character_panel_renderer;
}

TEST(LabyrinthOfLore_Rendering_Hud_CharacterPanelRendererTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Rendering::Hud::CharacterPanelRenderer character_panel_renderer;
   //std::string expected_string = "Hello World!";
   //EXPECT_EQ(expected_string, character_panel_renderer.run());
}
