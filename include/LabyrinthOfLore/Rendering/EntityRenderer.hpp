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

      protected:


      public:
         EntityRenderer(LabyrinthOfLore::Entity::Base* entity=nullptr);
         ~EntityRenderer();

         void render_with_legacy_transform();
         void render_with_custom_transform();
         void render();
      };
   }
}



