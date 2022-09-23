#pragma once


#include <string>


namespace LabyrinthOfLore
{
   namespace WorldMap
   {
      class Door
      {
      private:
         std::string level_identifier;
         float spawn_x;
         float spawn_y;
         float spawn_z;
         float spawn_facing_yaw;

      protected:


      public:
         Door(std::string level_identifier="", float spawn_x=0.0f, float spawn_y=0.0f, float spawn_z=0.0f, float spawn_facing_yaw=0.0f);
         ~Door();

         std::string get_level_identifier() const;
         float get_spawn_x() const;
         float get_spawn_y() const;
         float get_spawn_z() const;
         float get_spawn_facing_yaw() const;
      };
   }
}



