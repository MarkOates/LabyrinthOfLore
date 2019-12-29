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

      public:
         TitleText();
         ~TitleText();

         void set_above_text(std::string above_text);
         void set_headline_text(std::string headline_text);

         std::string get_above_text();
         std::string get_headline_text();
      };
   }
}



