
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Entity/Base.hpp>

TEST(LabyrinthOfLore_Entity_BaseTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Entity::Base base;
}

TEST(LabyrinthOfLore_Entity_BaseTest, get_billboard_at_camera__initializes_to_false)
{
   LabyrinthOfLore::Entity::Base base;
   EXPECT_EQ(false, base.get_billboard_at_camera());
}
