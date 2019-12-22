
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Hud/Compass.hpp>

TEST(LabyrinthOfLore_Hud_CompassTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Hud::Compass compass;
}

TEST(LabyrinthOfLore_Hud_CompassTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Hud::Compass compass;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, compass.run());
}
