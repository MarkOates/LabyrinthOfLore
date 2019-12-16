#pragma once


#include <LabyrinthOfLore/Entity/Base.hpp>
#include <LabyrinthOfLore/Shader/ClampedColor.hpp>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class EntityPickingRenderer
      {
      private:
         LabyrinthOfLore::Entity::Base* entity;
         LabyrinthOfLore::Shader::ClampedColor* clamped_color_shader;

      public:
         EntityPickingRenderer(LabyrinthOfLore::Entity::Base* entity=nullptr, LabyrinthOfLore::Shader::ClampedColor* clamped_color_shader=nullptr);
         ~EntityPickingRenderer();


      void render();
      };
   }
}



