#pragma once


#include <LabyrinthOfLore/WorldMap/TileMap.hpp>
#include <allegro5/allegro.h>


namespace LabyrinthOfLore
{
   namespace WorldMap
   {
      class PixelRenderer
      {
      private:
         LabyrinthOfLore::WorldMap::TileMap tile_map;
         float ground_level;

      public:
         PixelRenderer(LabyrinthOfLore::WorldMap::TileMap tile_map={}, float ground_level=1.0);
         ~PixelRenderer();


      void initialize();
      ALLEGRO_BITMAP* create_render();
      };
   }
}



