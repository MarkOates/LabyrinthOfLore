#pragma once


#include <string>


namespace LabyrinthOfLore
{
   namespace Hud
   {
      class MessageScroll
      {
      private:
         std::string text;

      public:
         MessageScroll();
         ~MessageScroll();


         std::string get_text();
      std::string append_text(std::string text_to_append="");
      void clear_text();
      };
   }
}



