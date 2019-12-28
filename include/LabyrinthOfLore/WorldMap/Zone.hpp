#pragma once


#include <AllegroFlare/Vec3D.hpp>


namespace LabyrinthOfLore
{
   namespace WorldMap
   {
      class Zone
      {
      private:
         float x1;
         float y1;
         float z1;
         float x2;
         float y2;
         float z2;

      public:
         Zone();
         ~Zone();


         float get_x1();
         float get_y1();
         float get_z1();
         float get_x2();
         float get_y2();
         float get_z2();
      bool collides(AllegroFlare::vec3d point={});
      };
   }
}



