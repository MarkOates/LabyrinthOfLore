

#include <LabyrinthOfLore/Physics/EntityZoneCollisionObserver.hpp>
#include <algorithm>
#include <algorithm>


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

std::vector<std::pair<LabyrinthOfLore::Entity::Base*, LabyrinthOfLore::WorldMap::Zone*>> EntityZoneCollisionObserver::collisions_added()
{
std::vector<std::pair<LabyrinthOfLore::Entity::Base*, LabyrinthOfLore::WorldMap::Zone*>> diff;

std::set_difference(
  collisions_at_end.begin(), collisions_at_end.end(),
  collisions_at_start.begin(), collisions_at_start.end(),
  std::inserter(diff, diff.begin())
);

return diff;

}

std::vector<std::pair<LabyrinthOfLore::Entity::Base*, LabyrinthOfLore::WorldMap::Zone*>> EntityZoneCollisionObserver::collisions_removed()
{
std::vector<std::pair<LabyrinthOfLore::Entity::Base*, LabyrinthOfLore::WorldMap::Zone*>> diff;

std::set_difference(
  collisions_at_start.begin(), collisions_at_start.end(),
  collisions_at_end.begin(), collisions_at_end.end(),
  std::inserter(diff, diff.begin())
);

return diff;

}
} // namespace Physics
} // namespace LabyrinthOfLore


