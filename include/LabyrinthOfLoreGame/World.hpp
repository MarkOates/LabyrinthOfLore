#pragma once


#include <LabyrinthOfLore/WorldMap/Map.hpp>
#include <string>
#include <vector>


namespace LabyrinthOfLoreGame
{
   class World
   {
   private:
      std::vector<LabyrinthOfLore::WorldMap::Map> maps;

   public:
      World(std::vector<LabyrinthOfLore::WorldMap::Map> maps={});
      ~World();


   std::string run();
   };
}



