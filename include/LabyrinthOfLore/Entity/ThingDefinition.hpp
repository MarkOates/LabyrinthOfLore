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
         ThingDefinition(std::string article="an", std::string name="unnamed thing");
         ~ThingDefinition();


         std::string get_article();
         std::string get_name();
      std::string infer_decorated_name();
      };
   }
}



