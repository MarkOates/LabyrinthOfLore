#pragma once


#include <LabyrinthOfLore/Physics/EntityTileMapCollisionEvent.hpp>
#include <vector>


namespace LabyrinthOfLoreGame
{
   class EntityTileMapCollisionEventProcessor
   {
   private:
      std::vector<LabyrinthOfLore::Physics::EntityTileMapCollisionEvent> events;

   public:
      EntityTileMapCollisionEventProcessor(std::vector<LabyrinthOfLore::Physics::EntityTileMapCollisionEvent> events={});
      ~EntityTileMapCollisionEventProcessor();


   void process();
   };
}



