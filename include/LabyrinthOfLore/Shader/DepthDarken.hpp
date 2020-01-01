#pragma once


#include <LabyrinthOfLore/Shader/Base.hpp>
#include <string>


namespace LabyrinthOfLore
{
   namespace Shader
   {
      class DepthDarken : private LabyrinthOfLore::Shader::Base
      {
      private:
         int torch_type;
         bool initialized;

      public:
         DepthDarken();
         ~DepthDarken();


      void initialize();
      void set_torch_type(int type=0);
      void set_torch_on();
      void set_torch_off();
      void activate();
      void deactivate();
      static std::string obtain_vertex_source();
      static std::string obtain_fragment_source();
      };
   }
}



