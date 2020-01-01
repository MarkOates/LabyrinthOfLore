#pragma once


#include <LabyrinthOfLore/Rendering/TileTypeDictionary.hpp>
#include <LabyrinthOfLore/WorldMap/TileMap.hpp>
#include <Tileo/TileAtlas.hpp>
#include <allegro5/allegro.h>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class TileMapWaterMesh
      {
      private:
         Tileo::TileAtlas* tile_atlas;
         LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary;
         LabyrinthOfLore::WorldMap::TileMap tile_map;
         ALLEGRO_BITMAP* texture;
         int __unused_offset_to_first_texture_index;
         std::vector<ALLEGRO_VERTEX> vertexes;

      public:
         TileMapWaterMesh(Tileo::TileAtlas* tile_atlas=nullptr, LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary={}, LabyrinthOfLore::WorldMap::TileMap tile_map={}, ALLEGRO_BITMAP* texture=nullptr, int __unused_offset_to_first_texture_index=0);
         ~TileMapWaterMesh();


         std::vector<ALLEGRO_VERTEX> get_vertexes();
      bool build();
      void draw();
      };
   }
}



