#pragma once


#include <LabyrinthOfLore/Rendering/TileTypeDictionary.hpp>
#include <LabyrinthOfLore/WorldMap/TileMap.hpp>
#include <allegro5/allegro.h>


namespace LabyrinthOfLore
{
   namespace WorldMap
   {
      class PixelRenderer
      {
      private:
         LabyrinthOfLore::WorldMap::TileMap tile_map;
         LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary;
         float ground_level;

      protected:


      public:
         PixelRenderer(LabyrinthOfLore::WorldMap::TileMap tile_map={}, LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary={}, float ground_level=1.0);
         ~PixelRenderer();

         void initialize();
         ALLEGRO_BITMAP* create_render();
      };
   }
}



