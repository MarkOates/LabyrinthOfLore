

#include <LabyrinthOfLore/World.hpp>



namespace LabyrinthOfLore
{


World::World(std::vector<LabyrinthOfLore::WorldMap::Level> maps)
   : maps(maps)
{
}


World::~World()
{
}


} // namespace LabyrinthOfLore


