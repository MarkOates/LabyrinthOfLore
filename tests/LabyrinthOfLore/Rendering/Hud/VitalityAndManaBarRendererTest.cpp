
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/Hud/VitalityAndManaBarRenderer.hpp>

TEST(LabyrinthOfLore_Rendering_Hud_VitalityAndManaBarRendererTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::Hud::VitalityAndManaBarRenderer vitality_and_mana_bar_renderer;
}

TEST(LabyrinthOfLore_Rendering_Hud_VitalityAndManaBarRendererTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Rendering::Hud::VitalityAndManaBarRenderer vitality_and_mana_bar_renderer;
   //std::string expected_string = "Hello World!";
   //EXPECT_EQ(expected_string, vitality_and_mana_bar_renderer.run());
}
