#pragma once


#include <LabyrinthOfLore/Rendering/TileTypeDefinition.hpp>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class TileTypeDictionary
      {
      private:

      public:
         TileTypeDictionary();
         ~TileTypeDictionary();


      LabyrinthOfLore::Rendering::TileTypeDefinition find_definition(int tile_type=0);
      };
   }
}



