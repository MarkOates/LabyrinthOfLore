#pragma once


#include <LabyrinthOfLore/WorldMap/Tile.hpp>
#include <vector>


namespace LabyrinthOfLoreGame
{
   class Maps
   {
   private:

   public:
      Maps();
      ~Maps();


   std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> build_construct_tile_map_data();
   };
}



