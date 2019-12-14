
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Entity/Base.hpp>

TEST(LabyrinthOfLore_Entity_BaseTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Entity::Base base;
}

TEST(LabyrinthOfLore_Entity_BaseTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Entity::Base base;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, base.run());
}
