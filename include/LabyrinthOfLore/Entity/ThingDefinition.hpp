#pragma once


#include <LabyrinthOfLoreGame/ItemIdEnums.hpp>
#include <Tileo/TileAtlas.hpp>
#include <string>


namespace LabyrinthOfLore
{
   namespace Entity
   {
      class ThingDefinition
      {
      private:
         thing_type_t type;
         std::string article;
         std::string name;
         Tileo::TileAtlas* tile_atlas;
         int tile_atlas_index_id;
         int weight;
         int health;
         std::string mood;
         std::string condition;

      protected:


      public:
         ThingDefinition(thing_type_t type=THING_TYPE_UNDEFINED, std::string article="an", std::string name="unnamed thing", Tileo::TileAtlas* tile_atlas=nullptr, int tile_atlas_index_id=-1, int weight=1, int health=1, std::string mood="", std::string condition="");
         ~ThingDefinition();

         void set_health(int health);
         void set_mood(std::string mood);
         void set_condition(std::string condition);
         thing_type_t get_type() const;
         std::string get_article() const;
         std::string get_name() const;
         Tileo::TileAtlas* get_tile_atlas() const;
         int get_tile_atlas_index_id() const;
         int get_weight() const;
         int get_health() const;
         std::string get_mood() const;
         std::string get_condition() const;
         bool infer_is_dead();
         std::string infer_short_decorated_name();
         std::string infer_decorated_name();
      };
   }
}



