
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/Hud/ViewFrameRenderer.hpp>

TEST(LabyrinthOfLore_Rendering_Hud_ViewFrameRendererTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::Hud::ViewFrameRenderer view_frame_renderer;
}

TEST(LabyrinthOfLore_Rendering_Hud_ViewFrameRendererTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Rendering::Hud::ViewFrameRenderer view_frame_renderer;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, view_frame_renderer.run());
}
