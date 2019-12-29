

#include <LabyrinthOfLore/Rendering/Hud/TitleTextRenderer.hpp>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>


namespace LabyrinthOfLore
{
namespace Rendering
{
namespace Hud
{


TitleTextRenderer::TitleTextRenderer(ALLEGRO_FONT* font, LabyrinthOfLore::Hud::TitleText* title_text, allegro_flare::placement3d place)
   : font(font)
   , title_text(title_text)
   , place(place)
{
}


TitleTextRenderer::~TitleTextRenderer()
{
}


void TitleTextRenderer::render()
{
if (!font) throw std::runtime_error("Cannot draw TitleText with a nullptr font");
if (!title_text) throw std::runtime_error("Cannot draw TitleText with a nullptr title_text");

place.start_transform();

//al_draw_rounded_rectangle(0, 0, place.size.x, place.size.y, 6, 6, al_color_name("red"), 3.0);
al_draw_text(font, al_color_name("white"), place.size.x/2, place.size.y/2 - 10, ALLEGRO_ALIGN_CENTER, title_text->get_above_text().c_str());
al_draw_text(font, al_color_name("white"), place.size.x/2, place.size.y/2 + 10, ALLEGRO_ALIGN_CENTER, title_text->get_headline_text().c_str());

place.restore_transform();
return;

}
} // namespace Hud
} // namespace Rendering
} // namespace LabyrinthOfLore


