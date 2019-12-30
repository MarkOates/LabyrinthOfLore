
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Entity/Thing.hpp>

TEST(LabyrinthOfLore_Entity_ThingTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Entity::Thing thing;
}

TEST(LabyrinthOfLore_Entity_ThingTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Entity::Thing thing;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, thing.run());
}
