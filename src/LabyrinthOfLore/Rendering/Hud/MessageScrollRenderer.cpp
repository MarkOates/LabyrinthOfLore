

#include <LabyrinthOfLore/Rendering/Hud/MessageScrollRenderer.hpp>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>


namespace LabyrinthOfLore
{
namespace Rendering
{
namespace Hud
{


MessageScrollRenderer::MessageScrollRenderer(ALLEGRO_FONT* font, LabyrinthOfLore::Hud::MessageScroll* message_scroll, allegro_flare::placement3d place)
   : font(font)
   , message_scroll(message_scroll)
   , place(place)
{
}


MessageScrollRenderer::~MessageScrollRenderer()
{
}


void MessageScrollRenderer::render()
{
if (!font) throw std::runtime_error("Cannot draw MessageScrollRenderer with a nullptr font");
if (!message_scroll) throw std::runtime_error("Cannot draw MessageScrollRenderer with a nullptr message_scroll");

place.start_transform();

//al_draw_filled_rounded_rectangle(0, 0, place.size.x, place.size.y, 6, 6, al_color_name("red"));
al_draw_multiline_text(font, al_color_name("gray"), 0, 0, place.size.x, al_get_font_line_height(font), 0, message_scroll->get_text().c_str());

place.restore_transform();
return;

}
} // namespace Hud
} // namespace Rendering
} // namespace LabyrinthOfLore


