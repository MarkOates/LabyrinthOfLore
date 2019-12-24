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
         std::vector<ALLEGRO_VERTEX> cube;

      public:
         TileMapMeshCubeTexturer(Tileo::TileAtlas* tile_atlas=nullptr, std::vector<ALLEGRO_VERTEX> cube={});
         ~TileMapMeshCubeTexturer();


      std::vector<ALLEGRO_VERTEX> texture_cube();
      };
   }
}



