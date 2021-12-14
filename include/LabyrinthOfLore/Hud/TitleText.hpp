#pragma once


#include <string>


namespace LabyrinthOfLore
{
   namespace Hud
   {
      class TitleText
      {
      private:
         std::string above_text;
         std::string headline_text;
         float time_changed_at;

      public:
         TitleText();
         ~TitleText();

         std::string get_above_text();
         std::string get_headline_text();
         float get_time_changed_at();
         void set(std::string above_text="", std::string headline_text="", float time_now=0.0f);
      };
   }
}



