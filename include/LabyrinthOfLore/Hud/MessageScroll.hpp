#pragma once


#include <string>
#include <tuple>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Hud
   {
      class MessageScroll
      {
      private:
         std::string text;
         std::vector<std::tuple<float, std::string, int>> messages;

      protected:


      public:
         MessageScroll(std::string text="Hello, brave soul. Adventure awaits you.");
         ~MessageScroll();

         std::string get_text() const;
         std::string get_last_message_text();
         std::vector<std::tuple<float, std::string, int>> get_messages_ref();
         std::vector<std::tuple<float, std::string, int>> get_last_3_messages();
         void append_text(std::string text_to_append="");
         void append_message(float time_of_message=0.0f, std::string text_to_append="");
         void append_character_dialog(float time_of_message=0.0f, std::string text_to_append="");
         void clear_text();
      };
   }
}



