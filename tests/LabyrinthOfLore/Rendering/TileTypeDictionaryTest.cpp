
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

TEST(LabyrinthOfLore_Rendering_TileTypeDictionaryTest, find_definition__without_definitions__returns_the_expected_default)
{
   LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary;

   LabyrinthOfLore::Rendering::TileTypeDefinition expected_definition;
   EXPECT_EQ_TILE_TYPE_DEFINITION(expected_definition, tile_type_dictionary.find_definition(0));
}

TEST(LabyrinthOfLore_Rendering_TileTypeDictionaryTest, find_definition__returns_the_definition_in_the_dictionary)
{
   LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary({
         { 0, LabyrinthOfLore::Rendering::TileTypeDefinition{ 3, 2, 1 } },
      });

   LabyrinthOfLore::Rendering::TileTypeDefinition expected_definition(3, 2, 1);
   EXPECT_EQ_TILE_TYPE_DEFINITION(expected_definition, tile_type_dictionary.find_definition(0));
}

TEST(LabyrinthOfLore_Rendering_TileTypeDictionaryTest, find_definition__with_multiple_duplicate_entries__returns_the_first_definition_in_the_dictionary)
{
   LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary({
         { 0, LabyrinthOfLore::Rendering::TileTypeDefinition{ 3, 2, 1 } },
         { 7, LabyrinthOfLore::Rendering::TileTypeDefinition{ 55, 14, 10 } },
         { 2, LabyrinthOfLore::Rendering::TileTypeDefinition{ 7, 11, 82 } },
         { 16, LabyrinthOfLore::Rendering::TileTypeDefinition{ 9, 2, 5 } },
         { 7, LabyrinthOfLore::Rendering::TileTypeDefinition{ 73, 84, 91 } },
      });

   LabyrinthOfLore::Rendering::TileTypeDefinition expected_definition;

   expected_definition = LabyrinthOfLore::Rendering::TileTypeDefinition(55, 14, 10);
   EXPECT_EQ_TILE_TYPE_DEFINITION(expected_definition, tile_type_dictionary.find_definition(7));
}

TEST(LabyrinthOfLore_Rendering_TileTypeDictionaryTest, find_definition__returns_the_definition_in_the_dictionary_2)
{
   LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary({
         { 0, LabyrinthOfLore::Rendering::TileTypeDefinition{ 3, 2, 1 } },
         { 7, LabyrinthOfLore::Rendering::TileTypeDefinition{ 55, 14, 10 } },
         { 2, LabyrinthOfLore::Rendering::TileTypeDefinition{ 7, 11, 82 } },
         { 16, LabyrinthOfLore::Rendering::TileTypeDefinition{ 9, 2, 5 } },
         { 7, LabyrinthOfLore::Rendering::TileTypeDefinition{ 73, 84, 91 } },
      });

   LabyrinthOfLore::Rendering::TileTypeDefinition expected_definition;

   expected_definition = LabyrinthOfLore::Rendering::TileTypeDefinition(3, 2, 1);
   EXPECT_EQ_TILE_TYPE_DEFINITION(expected_definition, tile_type_dictionary.find_definition(0));

   expected_definition = LabyrinthOfLore::Rendering::TileTypeDefinition(7, 11, 82);
   EXPECT_EQ_TILE_TYPE_DEFINITION(expected_definition, tile_type_dictionary.find_definition(2));

   expected_definition = LabyrinthOfLore::Rendering::TileTypeDefinition(9, 2, 5 );
   EXPECT_EQ_TILE_TYPE_DEFINITION(expected_definition, tile_type_dictionary.find_definition(16));
}

TEST(LabyrinthOfLore_Rendering_TileTypeDictionaryTest, find_definition__can_use_definitions_with_netative_types__even_though_its_shouldnt_really_be_used)
{
   LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary({
         { -2, LabyrinthOfLore::Rendering::TileTypeDefinition{ 3, 2, 1 } },
         { -999, LabyrinthOfLore::Rendering::TileTypeDefinition{ 55, 14, 10 } },
      });

   LabyrinthOfLore::Rendering::TileTypeDefinition expected_definition;

   expected_definition = LabyrinthOfLore::Rendering::TileTypeDefinition(3, 2, 1);
   EXPECT_EQ_TILE_TYPE_DEFINITION(expected_definition, tile_type_dictionary.find_definition(-2));

   expected_definition = LabyrinthOfLore::Rendering::TileTypeDefinition(55, 14, 10);
   EXPECT_EQ_TILE_TYPE_DEFINITION(expected_definition, tile_type_dictionary.find_definition(-999));
}
