
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/Hud/MapButtonRenderer.hpp>

TEST(LabyrinthOfLore_Rendering_Hud_MapButtonRendererTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::Hud::MapButtonRenderer map_button_renderer;
}

TEST(LabyrinthOfLore_Rendering_Hud_MapButtonRendererTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Rendering::Hud::MapButtonRenderer map_button_renderer;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, map_button_renderer.run());
}
