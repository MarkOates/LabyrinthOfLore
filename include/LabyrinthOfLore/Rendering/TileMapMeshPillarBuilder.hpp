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

      public:
         TileMapMeshPillarBuilder(int x=0, int y=0, float height=1.0f);
         ~TileMapMeshPillarBuilder();


      ALLEGRO_VERTEX buildA();
      ALLEGRO_VERTEX buildB();
      ALLEGRO_VERTEX buildC();
      ALLEGRO_VERTEX buildD();
      ALLEGRO_VERTEX buildE();
      ALLEGRO_VERTEX buildF();
      ALLEGRO_VERTEX buildG();
      ALLEGRO_VERTEX buildH();
      ALLEGRO_VERTEX buildA_whole();
      ALLEGRO_VERTEX buildB_whole();
      ALLEGRO_VERTEX buildC_whole();
      ALLEGRO_VERTEX buildD_whole();
      ALLEGRO_VERTEX buildE_whole();
      ALLEGRO_VERTEX buildF_whole();
      ALLEGRO_VERTEX buildG_whole();
      ALLEGRO_VERTEX buildH_whole();
      ALLEGRO_COLOR random_color();
      std::vector<ALLEGRO_VERTEX> build_pillar();
      };
   }
}



