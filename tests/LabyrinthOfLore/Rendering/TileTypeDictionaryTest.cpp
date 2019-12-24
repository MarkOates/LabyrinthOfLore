
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/TileTypeDictionary.hpp>

TEST(LabyrinthOfLore_Rendering_TileTypeDictionaryTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary;
}

TEST(LabyrinthOfLore_Rendering_TileTypeDictionaryTest, find_definition__returns_the_definition_in_the_dictionary)
{
   LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary;

   LabyrinthOfLore::Rendering::TileTypeDefinition expected_definition;
   //EXPECT_EQ(expected_definition, tile_type_dictionary.find_definition(0));
}
