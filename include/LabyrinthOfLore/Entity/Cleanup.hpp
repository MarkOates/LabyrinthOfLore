#pragma once


#include <LabyrinthOfLore/Entity/Base.hpp>
#include <string>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Entity
   {
      class Cleanup
      {
      private:
         std::vector<LabyrinthOfLore::Entity::Base*>* all_entities;
         static std::string CLEANUP_FLAG;

      protected:


      public:
         Cleanup(std::vector<LabyrinthOfLore::Entity::Base*>* all_entities=nullptr);
         ~Cleanup();

         static std::string get_CLEANUP_FLAG();
         int cleanup();
      };
   }
}



