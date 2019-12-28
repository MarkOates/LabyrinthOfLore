

#include <LabyrinthOfLore/World.hpp>



namespace LabyrinthOfLore
{


World::World(std::map<std::string, LabyrinthOfLore::WorldMap::Level> levels)
   : levels(levels)
{
}


World::~World()
{
}


} // namespace LabyrinthOfLore


