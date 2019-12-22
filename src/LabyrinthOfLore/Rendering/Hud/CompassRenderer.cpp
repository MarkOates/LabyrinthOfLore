

#include <LabyrinthOfLore/Rendering/Hud/CompassRenderer.hpp>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>


namespace LabyrinthOfLore
{
namespace Rendering
{
namespace Hud
{


CompassRenderer::CompassRenderer(ALLEGRO_FONT* font, LabyrinthOfLore::Hud::Compass* compass, allegro_flare::placement3d place)
   : font(font)
   , compass(compass)
   , place(place)
{
}


CompassRenderer::~CompassRenderer()
{
}


void CompassRenderer::render()
{
if (!font) throw std::runtime_error("Cannot draw Compass with a nullptr font");
if (!compass) throw std::runtime_error("Cannot draw Compass with a nullptr compass");

place.start_transform();

al_draw_filled_rounded_rectangle(0, 0, place.size.x, place.size.y, 6, 6, al_color_name("red"));
al_draw_text(font, al_color_name("white"), 0, 0, 0, " - compass - ");

place.restore_transform();
return;

}
} // namespace Hud
} // namespace Rendering
} // namespace LabyrinthOfLore


