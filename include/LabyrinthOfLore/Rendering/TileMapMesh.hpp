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
         std::vector<ALLEGRO_VERTEX> vertexes;

      public:
         TileMapMesh(LabyrinthOfLore::WorldMap::TileMap tile_map={});
         ~TileMapMesh();


      ALLEGRO_COLOR random_color();
      std::vector<ALLEGRO_VERTEX> build_cube(float x=0, float y=0, float height=1);
      bool build();
      void draw();
      };
   }
}



