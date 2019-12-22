
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/Hud/CompassRenderer.hpp>

TEST(LabyrinthOfLore_Rendering_Hud_CompassRendererTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::Hud::CompassRenderer compass_renderer;
}

TEST(LabyrinthOfLore_Rendering_Hud_CompassRendererTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Rendering::Hud::CompassRenderer compass_renderer;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, compass_renderer.run());
}
