#pragma once


#include <Tileo/TileAtlas.hpp>
#include <string>


namespace LabyrinthOfLore
{
   namespace Entity
   {
      class ThingDefinition
      {
      private:
         std::string article;
         std::string name;
         Tileo::TileAtlas* tile_atlas;
         int tile_atlas_index_id;

      public:
         ThingDefinition(std::string article="an", std::string name="unnamed thing", Tileo::TileAtlas* tile_atlas=nullptr, int tile_atlas_index_id=-1);
         ~ThingDefinition();


         std::string get_article();
         std::string get_name();
         Tileo::TileAtlas* get_tile_atlas();
         int get_tile_atlas_index_id();
      std::string infer_decorated_name();
      };
   }
}



