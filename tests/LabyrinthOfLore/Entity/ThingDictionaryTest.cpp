
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Entity/ThingDictionary.hpp>

TEST(LabyrinthOfLore_Entity_ThingDictionaryTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary;
}


#include <LabyrinthOfLoreGame/ItemIdEnums.hpp>


TEST(LabyrinthOfLore_Entity_ThingDictionaryTest, create_new_definition__adds_a_new_thing_to_the_dictionary)
{
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary;
   thing_dictionary.create_new_definition({ THING_TYPE_TORCH, "a", "rock" });
   ASSERT_EQ(1, thing_dictionary.size());
}

TEST(LabyrinthOfLore_Entity_ThingDictionaryTest, create_new_definition__returns_the_id_of_the_newly_created_item__which_can_be_retrieved)
{
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary;
   int newly_crated_definition_id = thing_dictionary.create_new_definition({ THING_TYPE_TORCH, "a", "rock" });

   LabyrinthOfLore::Entity::ThingDefinition retrieved_thing = thing_dictionary.find_definition(newly_crated_definition_id);
   ASSERT_EQ(1, thing_dictionary.size());
   ASSERT_EQ("a rock", retrieved_thing.infer_decorated_name());
}

TEST(LabyrinthOfLore_Entity_ThingDictionaryTest, create_new_definition__adds_a_new_thing_to_the_dictionary_with_an_id_that_is_at_least_CREATED_THINGS_START)
{
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary;
   int new_id_1 = thing_dictionary.create_new_definition({ THING_TYPE_TORCH, "a", "rock" });
   int new_id_2 = thing_dictionary.create_new_definition({ THING_TYPE_TORCH, "a", "spring" });
   int new_id_3 = thing_dictionary.create_new_definition({ THING_TYPE_TORCH, "a", "rubber band" });

   ASSERT_EQ(3, thing_dictionary.size());

   EXPECT_EQ(CREATED_THINGS_START+1, new_id_1);
   EXPECT_EQ(CREATED_THINGS_START+2, new_id_2);
   EXPECT_EQ(CREATED_THINGS_START+3, new_id_3);
}

