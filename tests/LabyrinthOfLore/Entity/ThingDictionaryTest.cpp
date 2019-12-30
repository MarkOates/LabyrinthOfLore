
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Entity/ThingDictionary.hpp>

TEST(LabyrinthOfLore_Entity_ThingDictionaryTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary;
}

TEST(LabyrinthOfLore_Entity_ThingDictionaryTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, thing_dictionary.run());
}
