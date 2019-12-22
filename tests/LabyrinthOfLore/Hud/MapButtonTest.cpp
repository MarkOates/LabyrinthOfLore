
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Hud/MapButton.hpp>

TEST(LabyrinthOfLore_Hud_MapButtonTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Hud::MapButton map_button;
}

TEST(LabyrinthOfLore_Hud_MapButtonTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Hud::MapButton map_button;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, map_button.run());
}
