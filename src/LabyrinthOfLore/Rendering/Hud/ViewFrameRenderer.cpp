

#include <LabyrinthOfLore/Rendering/Hud/ViewFrameRenderer.hpp>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>


namespace LabyrinthOfLore
{
namespace Rendering
{
namespace Hud
{


ViewFrameRenderer::ViewFrameRenderer(ALLEGRO_FONT* font, LabyrinthOfLore::Hud::ViewFrame* view_frame, allegro_flare::placement3d place)
   : font(font)
   , view_frame(view_frame)
   , place(place)
{
}


ViewFrameRenderer::~ViewFrameRenderer()
{
}


void ViewFrameRenderer::render()
{
if (!font) throw std::runtime_error("Cannot draw ViewFrame with a nullptr font");
if (!view_frame) throw std::runtime_error("Cannot draw ViewFrame with a nullptr view_frame");

place.start_transform();

al_draw_rounded_rectangle(0, 0, place.size.x, place.size.y, 6, 6, al_color_name("red"), 3.0);
al_draw_text(font, al_color_name("white"), 0, 0, 0, " - view frame - ");

place.restore_transform();
return;

}
} // namespace Hud
} // namespace Rendering
} // namespace LabyrinthOfLore


