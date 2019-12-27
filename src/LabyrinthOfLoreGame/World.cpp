

#include <LabyrinthOfLoreGame/World.hpp>



namespace LabyrinthOfLoreGame
{


World::World(std::vector<LabyrinthOfLore::WorldMap::Level> maps)
   : maps(maps)
{
}


World::~World()
{
}


} // namespace LabyrinthOfLoreGame


