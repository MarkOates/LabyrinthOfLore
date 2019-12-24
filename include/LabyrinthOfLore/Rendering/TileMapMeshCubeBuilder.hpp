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
         int x;
         int y;
         float height;
         float mul;

      public:
         TileMapMeshCubeBuilder(int x=0, int y=0, float height=1.0f, float mul=-1.0f);
         ~TileMapMeshCubeBuilder();


      ALLEGRO_VERTEX buildA(float u=0.0f, float v=0.0f);
      ALLEGRO_VERTEX buildB(float u=0.0f, float v=0.0f);
      ALLEGRO_VERTEX buildC(float u=0.0f, float v=0.0f);
      ALLEGRO_VERTEX buildD(float u=0.0f, float v=0.0f);
      ALLEGRO_VERTEX buildE(float u=0.0f, float v=0.0f);
      ALLEGRO_VERTEX buildF(float u=0.0f, float v=0.0f);
      ALLEGRO_VERTEX buildG(float u=0.0f, float v=0.0f);
      ALLEGRO_VERTEX buildH(float u=0.0f, float v=0.0f);
      ALLEGRO_COLOR random_color();
      std::vector<ALLEGRO_VERTEX> build_cube(float front_and_back_u1=0, float front_and_back_v1=0, float front_and_back_u2=0, float front_and_back_v2=0, float right_and_left_u1=0, float right_and_left_v1=0, float right_and_left_u2=0, float right_and_left_v2=0, float top_u1=0, float top_v1=0, float top_u2=0, float top_v2=0);
      };
   }
}



