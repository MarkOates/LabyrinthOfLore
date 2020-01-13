#pragma once


#include <LabyrinthOfLore/Shader/ClampedColor.hpp>
#include <LabyrinthOfLore/Shader/DepthDarken.hpp>


namespace LabyrinthOfLoreGame
{
   class Classic
   {
   private:
      bool initialized;
      LabyrinthOfLore::Shader::ClampedColor clamped_color_shader;
      LabyrinthOfLore::Shader::DepthDarken depth_darken_shader;

   public:
      Classic();
      ~Classic();


      LabyrinthOfLore::Shader::ClampedColor &get_clamped_color_shader_ref();
      LabyrinthOfLore::Shader::DepthDarken &get_depth_darken_shader_ref();
   void initialize();
   };
}


