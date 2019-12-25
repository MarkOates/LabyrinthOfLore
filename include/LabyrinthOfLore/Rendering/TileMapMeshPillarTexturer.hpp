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

      public:
         TileMapMeshPillarTexturer(Tileo::TileAtlas* tile_atlas=nullptr, std::vector<ALLEGRO_VERTEX> pillar_vertexes={}, int tile_index_for_front_and_back_texture=0, int tile_index_for_right_and_left_texture=0, int tile_index_for_top_texture=0);
         ~TileMapMeshPillarTexturer();


      std::vector<ALLEGRO_VERTEX> build_textured_pillar(bool scale_for_unit_sized_texture=true);
      };
   }
}



