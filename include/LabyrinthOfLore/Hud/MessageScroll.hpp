#pragma once


#include <string>
#include <utility>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Hud
   {
      class MessageScroll
      {
      private:
         std::string text;
         std::vector<std::pair<float, std::string>> messages;

      public:
         MessageScroll(std::string text="Hello, brave soul. Adventure awaits you.");
         ~MessageScroll();


         std::string get_text();
      std::vector<std::pair<float, std::string>> get_last_3_messages();
      void append_text(std::string text_to_append="");
      void clear_text();
      };
   }
}



