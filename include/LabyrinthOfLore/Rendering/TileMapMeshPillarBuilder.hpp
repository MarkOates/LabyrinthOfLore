#pragma once


#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class TileMapMeshPillarBuilder
      {
      private:
         int x;
         int y;
         float height;
         float mul;

      public:
         TileMapMeshPillarBuilder(int x=0, int y=0, float height=1.0f, float mul=1.0f);
         ~TileMapMeshPillarBuilder();


      ALLEGRO_VERTEX buildA();
      ALLEGRO_VERTEX buildB();
      ALLEGRO_VERTEX buildC();
      ALLEGRO_VERTEX buildD();
      ALLEGRO_VERTEX buildE();
      ALLEGRO_VERTEX buildF();
      ALLEGRO_VERTEX buildG();
      ALLEGRO_VERTEX buildH();
      ALLEGRO_COLOR random_color();
      std::vector<ALLEGRO_VERTEX> build_cube();
      };
   }
}



