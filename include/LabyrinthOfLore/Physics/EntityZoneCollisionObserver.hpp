#pragma once


#include <LabyrinthOfLore/Entity/Base.hpp>
#include <LabyrinthOfLore/WorldMap/Zone.hpp>
#include <utility>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Physics
   {
      class EntityZoneCollisionObserver
      {
      private:
         std::vector<LabyrinthOfLore::Entity::Base*> entities;
         std::vector<LabyrinthOfLore::WorldMap::Zone*> zones;

      public:
         EntityZoneCollisionObserver(std::vector<LabyrinthOfLore::Entity::Base*> entities={}, std::vector<LabyrinthOfLore::WorldMap::Zone*> zones={});
         ~EntityZoneCollisionObserver();


      std::vector<std::pair<LabyrinthOfLore::Entity::Base*, LabyrinthOfLore::WorldMap::Zone*>> get_collided();
      };
   }
}



