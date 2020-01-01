
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Entity/ThingDefinition.hpp>

#include <LabyrinthOfLoreGame/ItemIdEnums.hpp>


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

TEST(LabyrinthOfLore_Entity_ThingDefinitionTest, decorated_name__returns_the_expected_string)
{
   LabyrinthOfLore::Entity::ThingDefinition thing_definition(THING_TYPE_DOES_NOT_MATTER, "the", "amulet of fire");
   std::string expected_string = "the amulet of fire";
   EXPECT_EQ(expected_string, thing_definition.infer_decorated_name());
}

TEST(LabyrinthOfLore_Entity_ThingDefinitionTest, decorated_name__returns_the_expected_string_that_includes_mood)
{
   LabyrinthOfLore::Entity::ThingDefinition thing_definition(THING_TYPE_DOES_NOT_MATTER, "a", "man", nullptr, 0, 100, 10, "grumpy");
   std::string expected_string = "a grumpy man";
   EXPECT_EQ(expected_string, thing_definition.infer_decorated_name());
}

