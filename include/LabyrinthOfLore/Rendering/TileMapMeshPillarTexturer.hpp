#pragma once


#include <Tileo/TileAtlas.hpp>
#include <allegro5/allegro_primitives.h>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class TileMapMeshPillarTexturer
      {
      private:
         Tileo::TileAtlas* tile_atlas;
         std::vector<ALLEGRO_VERTEX> pillar_vertexes;
         int tile_index_for_front_and_back_texture;
         int tile_index_for_right_and_left_texture;
         int tile_index_for_top_texture;
         bool needs_partial_height_side_faces_from_top;
         float height;
         bool left_face_is_removed;

      public:
         TileMapMeshPillarTexturer(Tileo::TileAtlas* tile_atlas=nullptr, std::vector<ALLEGRO_VERTEX> pillar_vertexes={}, int tile_index_for_front_and_back_texture=0, int tile_index_for_right_and_left_texture=0, int tile_index_for_top_texture=0, bool needs_partial_height_side_faces_from_top=false, float height=-1);
         ~TileMapMeshPillarTexturer();


      void assign_texture_to_face(int this_face_start_index=0, int index_num_for_tile=0, bool needs_partial_height_side_faces_from_top=false);
      int infer_number_of_front_right_left_back_sets_of_vertexes();
      std::vector<ALLEGRO_VERTEX> build_textured_pillar(bool scale_for_unit_sized_texture=true);
      };
   }
}



