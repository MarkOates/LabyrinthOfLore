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

      public:
         TileMapMeshCubeBuilder();
         ~TileMapMeshCubeBuilder();


      ALLEGRO_COLOR random_color();
      std::vector<ALLEGRO_VERTEX> build_cube(float x=0, float y=0, float height=1);
      };
   }
}



