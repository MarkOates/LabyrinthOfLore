
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/Hud/TitleTextRenderer.hpp>

TEST(LabyrinthOfLore_Rendering_Hud_TitleTextRendererTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::Hud::TitleTextRenderer title_text_renderer;
}

TEST(LabyrinthOfLore_Rendering_Hud_TitleTextRendererTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Rendering::Hud::TitleTextRenderer title_text_renderer;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, title_text_renderer.run());
}
