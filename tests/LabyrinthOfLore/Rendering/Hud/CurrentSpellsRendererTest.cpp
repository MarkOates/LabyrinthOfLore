
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/Hud/CurrentSpellsRenderer.hpp>

TEST(LabyrinthOfLore_Rendering_Hud_CurrentSpellsRendererTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::Hud::CurrentSpellsRenderer current_spells_renderer;
}

TEST(LabyrinthOfLore_Rendering_Hud_CurrentSpellsRendererTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Rendering::Hud::CurrentSpellsRenderer current_spells_renderer;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, current_spells_renderer.run());
}
