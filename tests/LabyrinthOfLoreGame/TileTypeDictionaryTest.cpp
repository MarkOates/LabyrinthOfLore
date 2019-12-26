
#include <gtest/gtest.h>

#include <LabyrinthOfLoreGame/TileTypeDictionary.hpp>

TEST(LabyrinthOfLoreGame_TileTypeDictionaryTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLoreGame::TileTypeDictionary tile_type_dictionary;
}

TEST(LabyrinthOfLoreGame_TileTypeDictionaryTest, build_dictionary__returns_a_dictionary_with_the_expected_values)
{
   //LabyrinthOfLore::Rendering::TileTypeDictionary;

   LabyrinthOfLoreGame::TileTypeDictionary tile_type_dictionary;
   tile_type_dictionary.build_dictionary();
}
