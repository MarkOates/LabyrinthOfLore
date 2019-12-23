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
         float mul;

      public:
         TileMapMeshCubeBuilder(float x=0.0f, float y=0.0f, float height=1.0f, float mul=-1.0f);
         ~TileMapMeshCubeBuilder();


      ALLEGRO_VERTEX build_a();
      ALLEGRO_VERTEX build_b();
      ALLEGRO_VERTEX build_c();
      ALLEGRO_VERTEX build_d();
      ALLEGRO_VERTEX build_e();
      ALLEGRO_VERTEX build_f();
      ALLEGRO_VERTEX build_g();
      ALLEGRO_VERTEX build_h();
      ALLEGRO_COLOR random_color();
      std::vector<ALLEGRO_VERTEX> build_cube();
      };
   }
}



