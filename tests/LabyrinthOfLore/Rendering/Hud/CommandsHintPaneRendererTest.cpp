
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/Hud/CommandsHintPaneRenderer.hpp>

TEST(LabyrinthOfLore_Rendering_Hud_CommandsHintPaneRendererTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::Hud::CommandsHintPaneRenderer commands_hint_pane_renderer;
}

TEST(LabyrinthOfLore_Rendering_Hud_CommandsHintPaneRendererTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Rendering::Hud::CommandsHintPaneRenderer commands_hint_pane_renderer;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, commands_hint_pane_renderer.run());
}
