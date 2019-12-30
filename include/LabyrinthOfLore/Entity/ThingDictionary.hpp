#pragma once


#include <LabyrinthOfLore/Entity/ThingDefinition.hpp>
#include <map>


namespace LabyrinthOfLore
{
   namespace Entity
   {
      class ThingDictionary
      {
      private:
         std::map<int, LabyrinthOfLore::Entity::ThingDefinition> definitions;

      public:
         ThingDictionary(std::map<int, LabyrinthOfLore::Entity::ThingDefinition> definitions={});
         ~ThingDictionary();


      LabyrinthOfLore::Entity::ThingDefinition find_definition(int tile_type=0);
      LabyrinthOfLore::Entity::ThingDefinition& find_definition_ref(int tile_type=0);
      };
   }
}



