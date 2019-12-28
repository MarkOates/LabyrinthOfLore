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
         std::vector<std::pair<LabyrinthOfLore::Entity::Base*, LabyrinthOfLore::WorldMap::Zone*>> collisions_at_start;

      public:
         EntityZoneCollisionObserver();
         ~EntityZoneCollisionObserver();


         std::vector<std::pair<LabyrinthOfLore::Entity::Base*, LabyrinthOfLore::WorldMap::Zone*>> get_collisions_at_start();
      std::vector<std::pair<LabyrinthOfLore::Entity::Base*, LabyrinthOfLore::WorldMap::Zone*>> get_collided(std::vector<LabyrinthOfLore::Entity::Base*> entities={}, std::vector<LabyrinthOfLore::WorldMap::Zone*> zones={});
      void observe_start_state(std::vector<LabyrinthOfLore::Entity::Base*> entities={}, std::vector<LabyrinthOfLore::WorldMap::Zone*> zones={});
      };
   }
}



