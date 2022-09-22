

#include <LabyrinthOfLore/Rendering/MousePointer.hpp>

#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>


namespace LabyrinthOfLore
{
namespace Rendering
{


MousePointer::MousePointer(float x, float y)
   : x(x)
   , y(y)
{
}


MousePointer::~MousePointer()
{
}


void MousePointer::render()
{
   float size = 10;
   al_draw_filled_rectangle(x-size, y-size, x+size, y+size, al_color_name("white"));
}


} // namespace Rendering
} // namespace LabyrinthOfLore


