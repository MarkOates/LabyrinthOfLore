#pragma once


#include <LabyrinthOfLore/Shader/ClampedColor.hpp>


namespace LabyrinthOfLoreGame
{
   class Classic
   {
   private:
      bool initialized;
      LabyrinthOfLore::Shader::ClampedColor clamped_color_shader;

   public:
      Classic();
      ~Classic();


      LabyrinthOfLore::Shader::ClampedColor &get_clamped_color_shader_ref();
   void initialize();
   };
}



