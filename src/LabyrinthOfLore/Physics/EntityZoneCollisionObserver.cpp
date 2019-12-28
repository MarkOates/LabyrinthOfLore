

#include <LabyrinthOfLore/Physics/EntityZoneCollisionObserver.hpp>



namespace LabyrinthOfLore
{
namespace Physics
{


EntityZoneCollisionObserver::EntityZoneCollisionObserver()
   : collisions_at_start({})
{
}


EntityZoneCollisionObserver::~EntityZoneCollisionObserver()
{
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

void EntityZoneCollisionObserver::observe_start(std::vector<LabyrinthOfLore::Entity::Base*> entities, std::vector<LabyrinthOfLore::WorldMap::Zone*> zones)
{
return;

}
} // namespace Physics
} // namespace LabyrinthOfLore


