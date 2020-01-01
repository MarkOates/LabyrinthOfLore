
#include <gtest/gtest.h>

#include <LabyrinthOfLoreGame/TalkInteractions.hpp>

TEST(LabyrinthOfLoreGame_TalkInteractionsTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLoreGame::TalkInteractions talk_interactions;
}

TEST(LabyrinthOfLoreGame_TalkInteractionsTest, run__returns_the_expected_response)
{
   LabyrinthOfLoreGame::TalkInteractions talk_interactions;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, talk_interactions.run());
}
