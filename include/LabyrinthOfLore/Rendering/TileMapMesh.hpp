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
      class TileMapMesh
      {
      private:
         Tileo::TileAtlas* tile_atlas;
         LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary;
         LabyrinthOfLore::WorldMap::TileMap tile_map;
         ALLEGRO_BITMAP* texture;
         int offset_to_first_texture_index;
         std::vector<ALLEGRO_VERTEX> vertexes;

      protected:


      public:
         TileMapMesh(Tileo::TileAtlas* tile_atlas=nullptr, LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary={}, LabyrinthOfLore::WorldMap::TileMap tile_map={}, ALLEGRO_BITMAP* texture=nullptr, int offset_to_first_texture_index=0);
         ~TileMapMesh();

         std::vector<ALLEGRO_VERTEX> get_vertexes() const;
         bool build();
         void draw();
      };
   }
}



