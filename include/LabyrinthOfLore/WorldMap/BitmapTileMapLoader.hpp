#pragma once


#include <LabyrinthOfLore/WorldMap/TileMap.hpp>
#include <allegro5/allegro.h>


namespace LabyrinthOfLore
{
   namespace WorldMap
   {
      class BitmapTileMapLoader
      {
      private:
         ALLEGRO_BITMAP* source_bitmap;

      public:
         BitmapTileMapLoader(ALLEGRO_BITMAP* source_bitmap=nullptr);
         ~BitmapTileMapLoader();


      LabyrinthOfLore::WorldMap::TileMap load();
      };
   }
}



