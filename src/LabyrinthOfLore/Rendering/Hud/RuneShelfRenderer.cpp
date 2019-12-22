

#include <LabyrinthOfLore/Rendering/Hud/RuneShelfRenderer.hpp>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>


namespace LabyrinthOfLore
{
namespace Rendering
{
namespace Hud
{


RuneShelfRenderer::RuneShelfRenderer(ALLEGRO_FONT* font, LabyrinthOfLore::Hud::RuneShelf* rune_shelf, allegro_flare::placement3d place)
   : font(font)
   , rune_shelf(rune_shelf)
   , place(place)
{
}


RuneShelfRenderer::~RuneShelfRenderer()
{
}


void RuneShelfRenderer::render()
{
if (!font) throw std::runtime_error("Cannot draw RuneShelfRenderer with a nullptr font");
if (!rune_shelf) throw std::runtime_error("Cannot draw RuneShelfRenderer with a nullptr rune_shelf");

place.start_transform();

al_draw_filled_rounded_rectangle(0, 0, place.size.x, place.size.y, 6, 6, al_color_name("red"));
al_draw_text(font, al_color_name("white"), 0, 0, 0, " - rune shelf - ");

place.restore_transform();
return;

}
} // namespace Hud
} // namespace Rendering
} // namespace LabyrinthOfLore


