#pragma once


#include <Tileo/TileAtlas.hpp>
#include <allegro5/allegro_primitives.h>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class TileMapMeshCubeTexturer
      {
      private:
         Tileo::TileAtlas* tile_atlas;
         std::vector<ALLEGRO_VERTEX> cube_vertexes;
         int tile_index_for_front_and_back_texture;
         int tile_index_for_right_and_left_texture;
         int tile_index_for_top_texture;

      public:
         TileMapMeshCubeTexturer(Tileo::TileAtlas* tile_atlas=nullptr, std::vector<ALLEGRO_VERTEX> cube_vertexes={}, int tile_index_for_front_and_back_texture=0, int tile_index_for_right_and_left_texture=0, int tile_index_for_top_texture=0);
         ~TileMapMeshCubeTexturer();

         std::vector<ALLEGRO_VERTEX> build_textured_cube(bool scale_for_unit_sized_texture=true);
      };
   }
}



