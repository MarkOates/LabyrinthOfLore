
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Entity/ThingDefinition.hpp>

TEST(LabyrinthOfLore_Entity_ThingDefinitionTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Entity::ThingDefinition thing_definition;
}

TEST(LabyrinthOfLore_Entity_ThingDefinitionTest, name__returns_the_expected_response)
{
   LabyrinthOfLore::Entity::ThingDefinition thing_definition;
   std::string expected_string = "unnamed thing";
   EXPECT_EQ(expected_string, thing_definition.get_name());
}
