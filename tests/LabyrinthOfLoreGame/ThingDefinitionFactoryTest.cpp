
#include <gtest/gtest.h>

#include <LabyrinthOfLoreGame/ThingDefinitionFactory.hpp>

TEST(LabyrinthOfLoreGame_ThingDefinitionFactoryTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLoreGame::ThingDefinitionFactory thing_definition_factory;
}

TEST(LabyrinthOfLoreGame_ThingDefinitionFactoryTest, run__returns_the_expected_response)
{
   LabyrinthOfLoreGame::ThingDefinitionFactory thing_definition_factory;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, thing_definition_factory.run());
}
