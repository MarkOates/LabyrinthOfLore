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
   };
}



