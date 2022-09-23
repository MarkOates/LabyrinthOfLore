#pragma once


#include <LabyrinthOfLore/WorldMap/Level.hpp>
#include <map>
#include <string>


namespace LabyrinthOfLore
{
   class World
   {
   private:
      std::map<std::string, LabyrinthOfLore::WorldMap::Level> levels;

   protected:


   public:
      World(std::map<std::string, LabyrinthOfLore::WorldMap::Level> levels={});
      ~World();

      std::map<std::string, LabyrinthOfLore::WorldMap::Level> &get_levels_ref();
   };
}



