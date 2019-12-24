#pragma once


#include <LabyrinthOfLore/Rendering/TileTypeDefinition.hpp>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class TileTypeDictionary
      {
      private:
         std::vector<LabyrinthOfLore::Rendering::TileTypeDefinition> definitions;

      public:
         TileTypeDictionary(std::vector<LabyrinthOfLore::Rendering::TileTypeDefinition> definitions={});
         ~TileTypeDictionary();


      LabyrinthOfLore::Rendering::TileTypeDefinition find_definition(int tile_type=0);
      };
   }
}



