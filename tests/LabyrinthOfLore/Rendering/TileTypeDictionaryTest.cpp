
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/TileTypeDictionary.hpp>

void EXPECT_EQ_TILE_TYPE_DEFINITION(LabyrinthOfLore::Rendering::TileTypeDefinition expected, LabyrinthOfLore::Rendering::TileTypeDefinition actual)
{
   EXPECT_EQ(expected.get_tile_index_for_front_and_back_texture(), actual.get_tile_index_for_front_and_back_texture());
   EXPECT_EQ(expected.get_tile_index_for_right_and_left_texture(), actual.get_tile_index_for_right_and_left_texture());
   EXPECT_EQ(expected.get_tile_index_for_top_texture(), actual.get_tile_index_for_top_texture());
}

TEST(LabyrinthOfLore_Rendering_TileTypeDictionaryTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary;
}

TEST(LabyrinthOfLore_Rendering_TileTypeDictionaryTest, find_definition__returns_the_definition_in_the_dictionary)
{
   LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary;

   LabyrinthOfLore::Rendering::TileTypeDefinition expected_definition;
   EXPECT_EQ_TILE_TYPE_DEFINITION(expected_definition, tile_type_dictionary.find_definition(0));
}

