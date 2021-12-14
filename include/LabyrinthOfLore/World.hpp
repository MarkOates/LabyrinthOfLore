#pragma once


#include <LabyrinthOfLore/WorldMap/Level.hpp>
#include <map>


namespace LabyrinthOfLore
{
   class World
   {
   private:
      std::map<std::string, LabyrinthOfLore::WorldMap::Level> levels;

   public:
      World(std::map<std::string, LabyrinthOfLore::WorldMap::Level> levels={});
      ~World();

      std::map<std::string, LabyrinthOfLore::WorldMap::Level> &get_levels_ref();
   };
}



