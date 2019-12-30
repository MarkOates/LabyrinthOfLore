

#include <LabyrinthOfLore/Rendering/Hud/MessageScrollRenderer.hpp>
#include <AllegroFlare/Useful.hpp>
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


float MessageScrollRenderer::message_display_length_sec = 7.0f;


int MessageScrollRenderer::__dirty_total_line_count = 0;


MessageScrollRenderer::MessageScrollRenderer(ALLEGRO_FONT* font, LabyrinthOfLore::Hud::MessageScroll* message_scroll, allegro_flare::placement3d place)
   : font(font)
   , message_scroll(message_scroll)
   , place(place)
{
}


MessageScrollRenderer::~MessageScrollRenderer()
{
}


float MessageScrollRenderer::smoothstep(float edge0, float edge1, float x)
{
// Scale, bias and saturate x to 0..1 range
x = AllegroFlare::clamp((x - edge0) / (edge1 - edge0), 0.0f, 1.0f);
// Evaluate polynomial
return x * x * (3 - 2 * x);

}

bool MessageScrollRenderer::multiline_draw_callback(int line_num, const char* line, int size, void* extra)
{
//this functions callback signature:
//bool (*cb)(int line_num, const char *line, int size, void *extra)

__dirty_total_line_count++;

ALLEGRO_FONT *font = (ALLEGRO_FONT *)extra;
al_draw_text(font, al_color_name("gray"), 0, __dirty_total_line_count * al_get_font_line_height(font), 0, line);
return true;

}

void MessageScrollRenderer::render()
{
if (!font) throw std::runtime_error("Cannot draw MessageScrollRenderer with a nullptr font");
if (!message_scroll) throw std::runtime_error("Cannot draw MessageScrollRenderer with a nullptr message_scroll");

place.start_transform();

//al_draw_filled_rounded_rectangle(0, 0, place.size.x, place.size.y, 6, 6, al_color_name("red"));
std::vector<std::pair<float, std::string>> last_3_messages = message_scroll->get_last_3_messages();

float time_now = al_get_time();

__dirty_total_line_count = 0;
for (unsigned i=0; i<last_3_messages.size(); i++)
{
   std::pair<float, std::string> this_message = last_3_messages[i];
   float message_time = this_message.first;
   if (time_now >= (message_time + message_display_length_sec)) break;

   std::string message_text = this_message.second;

   al_do_multiline_text(font, place.size.x, message_text.c_str(), LabyrinthOfLore::Rendering::Hud::MessageScrollRenderer::multiline_draw_callback, font);
}

place.restore_transform();
return;

}
} // namespace Hud
} // namespace Rendering
} // namespace LabyrinthOfLore


