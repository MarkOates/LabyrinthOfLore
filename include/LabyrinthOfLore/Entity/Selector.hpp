#pragma once


#include <LabyrinthOfLore/Entity/Base.hpp>
#include <string>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Entity
   {
      class Selector
      {
      private:
         std::vector<LabyrinthOfLore::Entity::Base*> all_entities;

      public:
         Selector(std::vector<LabyrinthOfLore::Entity::Base*> all_entities={});
         ~Selector();

         std::vector<LabyrinthOfLore::Entity::Base*> select_within_level(std::string level_identifier="");
      };
   }
}



