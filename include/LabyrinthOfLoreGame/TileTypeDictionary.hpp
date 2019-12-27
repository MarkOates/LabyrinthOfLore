#pragma once


#include <LabyrinthOfLore/Rendering/TileTypeDictionary.hpp>


namespace LabyrinthOfLoreGame
{
   class TileTypeDictionary
   {
   private:

   public:
      TileTypeDictionary();
      ~TileTypeDictionary();


   LabyrinthOfLore::Rendering::TileTypeDictionary build_tile_type_dictionary();
   int number_for_door_no(int door_number=0);
   };
}



