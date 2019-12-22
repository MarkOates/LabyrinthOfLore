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

         void set_text(std::string text);

         std::string get_text();
      };
   }
}



