

#include <LabyrinthOfLore/WorldMap/Zone.hpp>



namespace LabyrinthOfLore
{
namespace WorldMap
{


Zone::Zone(float x1, float y1, float z1, float x2, float y2, float z2)
   : x1(x1)
   , y1(y1)
   , z1(z1)
   , x2(x2)
   , y2(y2)
   , z2(z2)
{
}


Zone::~Zone()
{
}


float Zone::get_x1()
{
   return x1;
}


float Zone::get_y1()
{
   return y1;
}


float Zone::get_z1()
{
   return z1;
}


float Zone::get_x2()
{
   return x2;
}


float Zone::get_y2()
{
   return y2;
}


float Zone::get_z2()
{
   return z2;
}


bool Zone::collides(AllegroFlare::vec3d point)
{
if (point.x > x2) return false;
if (point.x < x1) return false;
if (point.y > y2) return false;
if (point.y < y1) return false;
if (point.z > z2) return false;
if (point.z < z1) return false;
return true;

}
} // namespace WorldMap
} // namespace LabyrinthOfLore


