#pragma once


#include <LabyrinthOfLore/Entity/Base.hpp>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class EntityPickingRenderer
      {
      private:
         LabyrinthOfLore::Entity::Base* entity;

      public:
         EntityPickingRenderer(LabyrinthOfLore::Entity::Base* entity=nullptr);
         ~EntityPickingRenderer();


      void render();
      };
   }
}



