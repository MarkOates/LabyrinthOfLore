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
         std::vector<ALLEGRO_VERTEX>* cube;
         int tile_index_for_right_and_left_texture;
         int tile_index_for_top_texture;

      public:
         TileMapMeshCubeTexturer(Tileo::TileAtlas* tile_atlas=nullptr, std::vector<ALLEGRO_VERTEX>* cube=nullptr, int tile_index_for_right_and_left_texture=0, int tile_index_for_top_texture=0);
         ~TileMapMeshCubeTexturer();


      void apply_textures();
      };
   }
}



