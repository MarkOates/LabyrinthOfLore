
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/Hud/RuneShelfRenderer.hpp>

TEST(LabyrinthOfLore_Rendering_Hud_RuneShelfRendererTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::Hud::RuneShelfRenderer rune_shelf_renderer;
}

TEST(LabyrinthOfLore_Rendering_Hud_RuneShelfRendererTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Rendering::Hud::RuneShelfRenderer rune_shelf_renderer;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, rune_shelf_renderer.run());
}
