#pragma once


#include <LabyrinthOfLore/Entity/Base.hpp>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class EntityRenderer
      {
      private:
         LabyrinthOfLore::Entity::Base* entity;

      public:
         EntityRenderer(LabyrinthOfLore::Entity::Base* entity=nullptr);
         ~EntityRenderer();


      void render();
      };
   }
}



