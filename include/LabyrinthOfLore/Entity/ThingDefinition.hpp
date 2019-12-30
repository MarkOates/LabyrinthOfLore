#pragma once


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
         int tile_atlas_index_id;

      public:
         ThingDefinition(std::string article="an", std::string name="unnamed thing", int tile_atlas_index_id=-1);
         ~ThingDefinition();


         std::string get_article();
         std::string get_name();
         int get_tile_atlas_index_id();
      std::string infer_decorated_name();
      };
   }
}



