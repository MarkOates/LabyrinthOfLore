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

      public:
         TileMapMeshCubeTexturer(Tileo::TileAtlas* tile_atlas=nullptr, std::vector<ALLEGRO_VERTEX> cube_vertexes={});
         ~TileMapMeshCubeTexturer();


      std::vector<ALLEGRO_VERTEX> texture_cube();
      };
   }
}



