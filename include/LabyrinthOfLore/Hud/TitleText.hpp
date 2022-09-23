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

      protected:


      public:
         TitleText();
         ~TitleText();

         std::string get_above_text() const;
         std::string get_headline_text() const;
         float get_time_changed_at() const;
         void set(std::string above_text="", std::string headline_text="", float time_now=0.0f);
      };
   }
}



