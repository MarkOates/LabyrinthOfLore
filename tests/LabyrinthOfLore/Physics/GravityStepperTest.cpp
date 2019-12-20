
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Physics/GravityStepper.hpp>

TEST(LabyrinthOfLore_Physics_GravityStepperTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Physics::GravityStepper gravity_stepper;
}

TEST(LabyrinthOfLore_Physics_GravityStepperTest, process_step__applies_the_gravity_value_to_the_entities)
{
   LabyrinthOfLore::Physics::GravityStepper gravity_stepper;
   // not tested
}
