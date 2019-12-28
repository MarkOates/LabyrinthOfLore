

#include <LabyrinthOfLore/Physics/EntityZoneCollisionEvent.hpp>



namespace LabyrinthOfLore
{
namespace Physics
{


EntityZoneCollisionEvent::EntityZoneCollisionEvent(int zone_id, LabyrinthOfLore::Entity::Base* entity, LabyrinthOfLore::Physics::zone_collision_event_t event_type)
   : zone_id(zone_id)
   , entity(entity)
   , event_type(event_type)
{
}


EntityZoneCollisionEvent::~EntityZoneCollisionEvent()
{
}


int EntityZoneCollisionEvent::get_zone_id()
{
   return zone_id;
}


LabyrinthOfLore::Entity::Base* EntityZoneCollisionEvent::get_entity()
{
   return entity;
}


LabyrinthOfLore::Physics::zone_collision_event_t EntityZoneCollisionEvent::get_event_type()
{
   return event_type;
}


} // namespace Physics
} // namespace LabyrinthOfLore


