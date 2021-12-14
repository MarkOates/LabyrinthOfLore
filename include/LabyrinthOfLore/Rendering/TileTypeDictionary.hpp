#pragma once


#include <LabyrinthOfLore/Rendering/TileTypeDefinition.hpp>
#include <map>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class TileTypeDictionary
      {
      private:
         std::map<int, LabyrinthOfLore::Rendering::TileTypeDefinition> definitions;

      public:
         TileTypeDictionary(std::map<int, LabyrinthOfLore::Rendering::TileTypeDefinition> definitions={});
         ~TileTypeDictionary();

         LabyrinthOfLore::Rendering::TileTypeDefinition find_definition(int tile_type=0);
      };
   }
}



