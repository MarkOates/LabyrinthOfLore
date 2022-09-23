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
         bool do_not_include_top_face;
         bool do_not_include_front_face;
         bool do_not_include_right_face;
         bool do_not_include_left_face;
         bool do_not_include_back_face;

      protected:


      public:
         TileMapMeshPillarBuilder(int x=0, int y=0, float height=1.0f, bool do_not_include_top_face=false, bool do_not_include_front_face=false, bool do_not_include_right_face=false, bool do_not_include_left_face=false, bool do_not_include_back_face=false);
         ~TileMapMeshPillarBuilder();

         float get_height() const;
         ALLEGRO_VERTEX buildA();
         ALLEGRO_VERTEX buildB();
         ALLEGRO_VERTEX buildC();
         ALLEGRO_VERTEX buildD();
         ALLEGRO_VERTEX buildE();
         ALLEGRO_VERTEX buildF();
         ALLEGRO_VERTEX buildG();
         ALLEGRO_VERTEX buildH();
         ALLEGRO_VERTEX buildA_whole(float height_origin=0.0f);
         ALLEGRO_VERTEX buildB_whole(float height_origin=0.0f);
         ALLEGRO_VERTEX buildC_whole(float height_origin=0.0f);
         ALLEGRO_VERTEX buildD_whole(float height_origin=0.0f);
         ALLEGRO_VERTEX buildE_whole(float height_origin=0.0f);
         ALLEGRO_VERTEX buildF_whole(float height_origin=0.0f);
         ALLEGRO_VERTEX buildG_whole(float height_origin=0.0f);
         ALLEGRO_VERTEX buildH_whole(float height_origin=0.0f);
         bool needs_partial_height_side_faces_from_top();
         int infer_number_of_whole_number_cubes_from_bottom();
         ALLEGRO_COLOR random_color();
         std::vector<ALLEGRO_VERTEX> build_pillar();
      };
   }
}



