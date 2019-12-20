
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Physics/Gravity.hpp>

TEST(LabyrinthOfLore_Physics_GravityTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Physics::Gravity gravity;
}

TEST(LabyrinthOfLore_Physics_GravityTest, process_step__applies_the_gravity_value_to_the_entities)
{
   LabyrinthOfLore::Physics::Gravity gravity;
   // not tested
}
