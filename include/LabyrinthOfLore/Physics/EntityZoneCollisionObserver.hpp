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
         std::vector<std::pair<LabyrinthOfLore::Entity::Base*, LabyrinthOfLore::WorldMap::Zone*>> collisions_at_start;

      public:
         EntityZoneCollisionObserver(std::vector<LabyrinthOfLore::Entity::Base*> entities={}, std::vector<LabyrinthOfLore::WorldMap::Zone*> zones={});
         ~EntityZoneCollisionObserver();


      std::vector<std::pair<LabyrinthOfLore::Entity::Base*, LabyrinthOfLore::WorldMap::Zone*>> get_collided();
      void observe_start(std::vector<LabyrinthOfLore::Entity::Base*> entities={}, std::vector<LabyrinthOfLore::WorldMap::Zone*> zones={});
      };
   }
}



