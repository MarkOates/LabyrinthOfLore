#pragma once


#include <LabyrinthOfLore/WorldMap/Level.hpp>
#include <vector>


namespace LabyrinthOfLore
{
   class World
   {
   private:
      std::vector<LabyrinthOfLore::WorldMap::Level> levels;

   public:
      World(std::vector<LabyrinthOfLore::WorldMap::Level> levels={});
      ~World();


   };
}



