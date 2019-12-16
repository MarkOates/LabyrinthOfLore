#pragma once


#include <LabyrinthOfLore/Shader/Base.hpp>
#include <string>


namespace LabyrinthOfLore
{
   namespace Shader
   {
      class FlatColor : private LabyrinthOfLore::Shader::Base
      {
      private:
         bool initialized;

      public:
         FlatColor();
         ~FlatColor();


      void initialize();
      void activate();
      static std::string obtain_vertex_source();
      static std::string obtain_fragment_source();
      };
   }
}



