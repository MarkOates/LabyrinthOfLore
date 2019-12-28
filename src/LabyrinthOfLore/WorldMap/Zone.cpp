

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


bool Zone::collides(AllegroFlare::vec3d point)
{
return true;

}
} // namespace WorldMap
} // namespace LabyrinthOfLore


