#pragma once


#include <string>


namespace LabyrinthOfLore
{
   namespace Entity
   {
      class ThingDefinition
      {
      private:
         std::string article;
         std::string name;

      public:
         ThingDefinition();
         ~ThingDefinition();


         std::string get_article();
         std::string get_name();
      std::string decorated_name();
      };
   }
}



