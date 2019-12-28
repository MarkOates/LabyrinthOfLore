

#include <LabyrinthOfLore/WorldMap/Zone.hpp>



namespace LabyrinthOfLore
{
namespace WorldMap
{


Zone::Zone()
   : x1(0.0f)
   , y1(0.0f)
   , z1(0.0f)
   , x2(1.0f)
   , y2(1.0f)
   , z2(1.0f)
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
return true;

}
} // namespace WorldMap
} // namespace LabyrinthOfLore


