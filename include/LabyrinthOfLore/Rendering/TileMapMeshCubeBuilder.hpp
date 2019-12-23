#pragma once


#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class TileMapMeshCubeBuilder
      {
      private:
         float x;
         float y;
         float height;

      public:
         TileMapMeshCubeBuilder(float x=0.0f, float y=0.0f, float height=1.0f);
         ~TileMapMeshCubeBuilder();


      ALLEGRO_COLOR random_color();
      std::vector<ALLEGRO_VERTEX> build_cube();
      };
   }
}



