

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


std::string EntityZoneCollisionObserver::run()
{
return "Hello World!";
}
} // namespace Physics
} // namespace LabyrinthOfLore


