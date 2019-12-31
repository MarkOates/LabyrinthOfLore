

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


ALLEGRO_COLOR MessageScrollRenderer::__dirty_this_text_color = {};


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
std::string text_at_line_start = line;
std::string text_to_draw_in_this_line = text_at_line_start.substr(0, size);
al_draw_text(font, __dirty_this_text_color, 0, __dirty_total_line_count * al_get_font_line_height(font), 0, text_to_draw_in_this_line.c_str());
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
   if (time_now >= (message_time + message_display_length_sec + 4.0)) break;

   float message_age = time_now - message_time;
  __dirty_this_text_color = al_color_name("gray");

   std::string message_text = this_message.second;
   float opacity = 1.0;
   opacity *= (message_age <= message_display_length_sec/2) ? smoothstep(0.0, 0.2, message_age) : smoothstep(message_display_length_sec, message_display_length_sec-1.0, message_age);

   __dirty_this_text_color.r *= opacity;
   __dirty_this_text_color.g *= opacity;
   __dirty_this_text_color.b *= opacity;
   __dirty_this_text_color.a *= opacity;

   al_do_multiline_text(font, place.size.x, message_text.c_str(), LabyrinthOfLore::Rendering::Hud::MessageScrollRenderer::multiline_draw_callback, font);
}

place.restore_transform();
return;

}
} // namespace Hud
} // namespace Rendering
} // namespace LabyrinthOfLore


