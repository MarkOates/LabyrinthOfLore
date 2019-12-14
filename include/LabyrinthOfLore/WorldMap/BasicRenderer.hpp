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

      public:
         BasicRenderer(LabyrinthOfLore::WorldMap::TileMap tile_map={});
         ~BasicRenderer();


      void intialize();
      void render();
      };
   }
}



