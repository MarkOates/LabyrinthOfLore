#pragma once


#include <LabyrinthOfLore/Entity/Base.hpp>
#include <LabyrinthOfLore/Physics/ZoneCollisionEventEnum.hpp>


namespace LabyrinthOfLore
{
   namespace Physics
   {
      class EntityZoneCollisionEvent
      {
      private:
         int zone_id;
         LabyrinthOfLore::Entity::Base* entity;
         LabyrinthOfLore::Physics::zone_collision_event_t event_type;

      protected:


      public:
         EntityZoneCollisionEvent(int zone_id=-1, LabyrinthOfLore::Entity::Base* entity=nullptr, LabyrinthOfLore::Physics::zone_collision_event_t event_type=LabyrinthOfLore::Physics::COLLISION_EVENT_NONE);
         ~EntityZoneCollisionEvent();

         int get_zone_id() const;
         LabyrinthOfLore::Entity::Base* get_entity() const;
         LabyrinthOfLore::Physics::zone_collision_event_t get_event_type() const;
      };
   }
}



