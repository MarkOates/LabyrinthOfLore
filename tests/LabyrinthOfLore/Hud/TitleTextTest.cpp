
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Hud/TitleText.hpp>

TEST(LabyrinthOfLore_Hud_TitleTextTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Hud::TitleText title_text;
}

TEST(LabyrinthOfLore_Hud_TitleTextTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Hud::TitleText title_text;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, title_text.run());
}
