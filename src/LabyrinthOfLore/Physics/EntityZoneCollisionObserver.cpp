

#include <LabyrinthOfLore/Physics/EntityZoneCollisionObserver.hpp>



namespace LabyrinthOfLore
{
namespace Physics
{


EntityZoneCollisionObserver::EntityZoneCollisionObserver()
   : collisions_at_start({})
   , collisions_at_end({})
{
}


EntityZoneCollisionObserver::~EntityZoneCollisionObserver()
{
}


std::vector<std::pair<LabyrinthOfLore::Entity::Base*, LabyrinthOfLore::WorldMap::Zone*>> EntityZoneCollisionObserver::get_collisions_at_start()
{
   return collisions_at_start;
}


std::vector<std::pair<LabyrinthOfLore::Entity::Base*, LabyrinthOfLore::WorldMap::Zone*>> EntityZoneCollisionObserver::get_collisions_at_end()
{
   return collisions_at_end;
}


std::vector<std::pair<LabyrinthOfLore::Entity::Base*, LabyrinthOfLore::WorldMap::Zone*>> EntityZoneCollisionObserver::get_collided(std::vector<LabyrinthOfLore::Entity::Base*> entities, std::vector<LabyrinthOfLore::WorldMap::Zone*> zones)
{
std::vector<std::pair<LabyrinthOfLore::Entity::Base*, LabyrinthOfLore::WorldMap::Zone*>> result;

for (auto &entity : entities)
{
   for (auto &zone : zones)
   {
      if (zone->collides(entity->get_placement_ref().position)) result.push_back({ entity, zone });
   }
}

return result;

}

void EntityZoneCollisionObserver::observe_start_state(std::vector<LabyrinthOfLore::Entity::Base*> entities, std::vector<LabyrinthOfLore::WorldMap::Zone*> zones)
{
collisions_at_start = get_collided(entities, zones);
return;

}

void EntityZoneCollisionObserver::observe_end_state(std::vector<LabyrinthOfLore::Entity::Base*> entities, std::vector<LabyrinthOfLore::WorldMap::Zone*> zones)
{
collisions_at_end = get_collided(entities, zones);
return;

}
} // namespace Physics
} // namespace LabyrinthOfLore


