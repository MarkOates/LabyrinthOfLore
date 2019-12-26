#pragma once


#include <LabyrinthOfLore/WorldMap/TileMap.hpp>


namespace LabyrinthOfLore
{
   namespace WorldMap
   {
      class PixelRenderer
      {
      private:
         LabyrinthOfLore::WorldMap::TileMap tile_map;

      public:
         PixelRenderer(LabyrinthOfLore::WorldMap::TileMap tile_map={});
         ~PixelRenderer();


      void initialize();
      void render();
      };
   }
}



