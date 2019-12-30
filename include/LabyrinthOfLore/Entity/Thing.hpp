#pragma once


#include <LabyrinthOfLore/Entity/ThingDefinition.hpp>
#include <map>


namespace LabyrinthOfLore
{
   namespace Entity
   {
      class Thing
      {
      private:
         std::map<int, LabyrinthOfLore::Entity::ThingDefinition> definitions;

      public:
         Thing(std::map<int, LabyrinthOfLore::Entity::ThingDefinition> definitions={});
         ~Thing();


      LabyrinthOfLore::Entity::ThingDefinition find_definition(int tile_type=0);
      };
   }
}



