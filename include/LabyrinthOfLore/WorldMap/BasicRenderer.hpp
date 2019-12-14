#pragma once


#include <Tileo/TileMap.hpp>


namespace LabyrinthOfLore
{
   namespace WorldMap
   {
      class BasicRenderer
      {
      private:
         Tileo::TileMap tile_map;
         Tileo::TileMap tile_height_map;

      public:
         BasicRenderer();
         ~BasicRenderer();


      void intialize();
      void render();
      };
   }
}



