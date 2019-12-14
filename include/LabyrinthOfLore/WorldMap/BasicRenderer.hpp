#pragma once


#include <LabyrinthOfLore/WorldMap/TileMap.hpp>


namespace LabyrinthOfLore
{
   namespace WorldMap
   {
      class BasicRenderer
      {
      private:
         LabyrinthOfLore::WorldMap::TileMap tile_map;
         LabyrinthOfLore::WorldMap::TileMap tile_height_map;

      public:
         BasicRenderer();
         ~BasicRenderer();


      void intialize();
      void render();
      };
   }
}



