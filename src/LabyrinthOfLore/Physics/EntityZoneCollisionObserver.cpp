

#include <LabyrinthOfLore/Physics/EntityZoneCollisionObserver.hpp>



namespace LabyrinthOfLore
{
namespace Physics
{


EntityZoneCollisionObserver::EntityZoneCollisionObserver(std::vector<LabyrinthOfLore::Entity::Base*> entities, std::vector<LabyrinthOfLore::WorldMap::Zone*> zones)
   : entities(entities)
   , zones(zones)
{
}


EntityZoneCollisionObserver::~EntityZoneCollisionObserver()
{
}


std::vector<std::pair<LabyrinthOfLore::Entity::Base*, LabyrinthOfLore::WorldMap::Zone*>> EntityZoneCollisionObserver::get_collided()
{
return {};

}
} // namespace Physics
} // namespace LabyrinthOfLore


