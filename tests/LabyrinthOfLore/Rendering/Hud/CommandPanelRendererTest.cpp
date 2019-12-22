
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/Hud/CommandPanelRenderer.hpp>

TEST(LabyrinthOfLore_Rendering_Hud_CommandPanelRendererTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::Hud::CommandPanelRenderer command_panel_renderer;
}

TEST(LabyrinthOfLore_Rendering_Hud_CommandPanelRendererTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Rendering::Hud::CommandPanelRenderer command_panel_renderer;
   //std::string expected_string = "Hello World!";
   //EXPECT_EQ(expected_string, command_panel_renderer.run());
}
