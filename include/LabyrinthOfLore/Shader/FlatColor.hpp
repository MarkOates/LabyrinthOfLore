#pragma once


#include <LabyrinthOfLore/Shader/Base.hpp>
#include <allegro5/allegro.h>
#include <string>


namespace LabyrinthOfLore
{
   namespace Shader
   {
      class FlatColor : private LabyrinthOfLore::Shader::Base
      {
      private:
         bool initialized;
         static std::string obtain_vertex_source();
         static std::string obtain_fragment_source();

      protected:


      public:
         FlatColor();
         ~FlatColor();

         void initialize();
         void activate();
         void set_flat_color(ALLEGRO_COLOR flat_color={});
      };
   }
}



