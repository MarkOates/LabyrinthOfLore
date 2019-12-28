

#include <LabyrinthOfLore/World.hpp>



namespace LabyrinthOfLore
{


World::World(std::vector<LabyrinthOfLore::WorldMap::Level> levels)
   : levels(levels)
{
}


World::~World()
{
}


} // namespace LabyrinthOfLore


