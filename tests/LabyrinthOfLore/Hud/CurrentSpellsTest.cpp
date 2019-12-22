
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Hud/CurrentSpells.hpp>

TEST(LabyrinthOfLore_Hud_CurrentSpellsTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Hud::CurrentSpells current_spells;
}

TEST(LabyrinthOfLore_Hud_CurrentSpellsTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Hud::CurrentSpells current_spells;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, current_spells.run());
}
