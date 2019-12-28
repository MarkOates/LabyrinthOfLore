#pragma once


#include <AllegroFlare/Vec3D.hpp>
#include <LabyrinthOfLore/Entity/Base.hpp>
#include <LabyrinthOfLore/WorldMap/Zone.hpp>
#include <tuple>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Physics
   {
      class EntityZoneCollisionObserver
      {
      private:
         std::vector<std::tuple<LabyrinthOfLore::Entity::Base*, AllegroFlare::vec3d, LabyrinthOfLore::WorldMap::Zone*>> collisions_at_start;
         std::vector<std::tuple<LabyrinthOfLore::Entity::Base*, AllegroFlare::vec3d, LabyrinthOfLore::WorldMap::Zone*>> collisions_at_end;

      public:
         EntityZoneCollisionObserver();
         ~EntityZoneCollisionObserver();


         std::vector<std::tuple<LabyrinthOfLore::Entity::Base*, AllegroFlare::vec3d, LabyrinthOfLore::WorldMap::Zone*>> get_collisions_at_start();
         std::vector<std::tuple<LabyrinthOfLore::Entity::Base*, AllegroFlare::vec3d, LabyrinthOfLore::WorldMap::Zone*>> get_collisions_at_end();
      std::vector<std::tuple<LabyrinthOfLore::Entity::Base*, AllegroFlare::vec3d, LabyrinthOfLore::WorldMap::Zone*>> get_collided(std::vector<LabyrinthOfLore::Entity::Base*> entities={}, std::vector<LabyrinthOfLore::WorldMap::Zone*> zones={});
      void observe_start_state(std::vector<LabyrinthOfLore::Entity::Base*> entities={}, std::vector<LabyrinthOfLore::WorldMap::Zone*> zones={});
      void observe_end_state(std::vector<LabyrinthOfLore::Entity::Base*> entities={}, std::vector<LabyrinthOfLore::WorldMap::Zone*> zones={});
      };
   }
}



