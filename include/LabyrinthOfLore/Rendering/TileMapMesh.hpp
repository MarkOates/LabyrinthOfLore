#pragma once


#include <LabyrinthOfLore/WorldMap/TileMap.hpp>
#include <Tileo/TileAtlas.hpp>
#include <allegro5/allegro.h>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class TileMapMesh
      {
      private:
         Tileo::TileAtlas* tile_atlas;
         LabyrinthOfLore::WorldMap::TileMap tile_map;
         ALLEGRO_BITMAP* texture;
         std::vector<ALLEGRO_VERTEX> vertexes;

      public:
         TileMapMesh(Tileo::TileAtlas* tile_atlas=nullptr, LabyrinthOfLore::WorldMap::TileMap tile_map={}, ALLEGRO_BITMAP* texture=nullptr);
         ~TileMapMesh();


         std::vector<ALLEGRO_VERTEX> get_vertexes();
      bool build();
      void draw();
      };
   }
}



