#pragma once


#include <LabyrinthOfLore/WorldMap/TileMap.hpp>
#include <allegro5/allegro.h>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class TileMapMesh
      {
      private:
         LabyrinthOfLore::WorldMap::TileMap tile_map;
         ALLEGRO_BITMAP* texture;
         std::vector<ALLEGRO_VERTEX> vertexes;

      public:
         TileMapMesh(LabyrinthOfLore::WorldMap::TileMap tile_map={}, ALLEGRO_BITMAP* texture=nullptr);
         ~TileMapMesh();


      bool build();
      void draw();
      };
   }
}



