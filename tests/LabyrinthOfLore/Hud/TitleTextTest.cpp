
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Hud/TitleText.hpp>

TEST(LabyrinthOfLore_Hud_TitleTextTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Hud::TitleText title_text;
}

TEST(LabyrinthOfLore_Hud_TitleTextTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Hud::TitleText title_text;

   title_text.set("Hello", "World", 1.03f);

   EXPECT_EQ("Hello", title_text.get_above_text());
   EXPECT_EQ("World", title_text.get_headline_text());
   EXPECT_EQ(1.03f, title_text.get_time_changed_at());
}
