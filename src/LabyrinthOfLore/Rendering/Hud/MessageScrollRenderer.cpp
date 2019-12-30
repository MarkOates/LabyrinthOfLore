

#include <LabyrinthOfLore/Rendering/Hud/MessageScrollRenderer.hpp>
#include <vector>
#include <utility>
#include <string>
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


bool MessageScrollRenderer::multiline_draw_callback(int line_num, const char* line, int size, void* extra)
{
//this functions callback signature:
//bool (*cb)(int line_num, const char *line, int size, void *extra)

ALLEGRO_FONT *font = (ALLEGRO_FONT *)extra;
al_draw_text(font, al_color_name("gray"), 0, line_num * 6, 0, line);
return true;

}

void MessageScrollRenderer::render()
{
if (!font) throw std::runtime_error("Cannot draw MessageScrollRenderer with a nullptr font");
if (!message_scroll) throw std::runtime_error("Cannot draw MessageScrollRenderer with a nullptr message_scroll");

place.start_transform();

//al_draw_filled_rounded_rectangle(0, 0, place.size.x, place.size.y, 6, 6, al_color_name("red"));
std::vector<std::pair<float, std::string>> last_3_messages = message_scroll->get_last_3_messages();

//for (unsigned i=0; i<last_3_messages.size(); i++)
//{
   al_do_multiline_text(font, place.size.x, message_scroll->get_text().c_str(), LabyrinthOfLore::Rendering::Hud::MessageScrollRenderer::multiline_draw_callback, font);
//}

place.restore_transform();
return;

}
} // namespace Hud
} // namespace Rendering
} // namespace LabyrinthOfLore


