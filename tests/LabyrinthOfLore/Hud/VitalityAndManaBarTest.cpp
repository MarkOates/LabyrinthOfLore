
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Hud/VitalityAndManaBar.hpp>

TEST(LabyrinthOfLore_Hud_VitalityAndManaBarTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Hud::VitalityAndManaBar vitality_and_mana_bar;
}

TEST(LabyrinthOfLore_Hud_VitalityAndManaBarTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Hud::VitalityAndManaBar vitality_and_mana_bar;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, vitality_and_mana_bar.run());
}
