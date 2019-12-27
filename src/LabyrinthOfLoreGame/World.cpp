

#include <LabyrinthOfLoreGame/World.hpp>



namespace LabyrinthOfLoreGame
{


World::World(std::vector<LabyrinthOfLore::WorldMap::Map> maps)
   : maps(maps)
{
}


World::~World()
{
}


std::string World::run()
{
return "Hello World!";
}
} // namespace LabyrinthOfLoreGame


