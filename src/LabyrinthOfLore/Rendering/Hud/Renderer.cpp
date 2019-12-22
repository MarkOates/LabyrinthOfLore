

#include <LabyrinthOfLore/Rendering/Hud/Renderer.hpp>
#include <LabyrinthOfLore/Rendering/Hud/MessageScrollRenderer.hpp>
#include <LabyrinthOfLore/Rendering/Hud/CommandPanelRenderer.hpp>
#include <stdexcept>
#include <allegro5/allegro_color.h>
#include <allegro_flare/placement3d.h>


namespace LabyrinthOfLore
{
namespace Rendering
{
namespace Hud
{


Renderer::Renderer(ALLEGRO_BITMAP* render_surface, AllegroFlare::FontBin* font_bin, LabyrinthOfLore::Hud::MessageScroll* message_scroll, LabyrinthOfLore::Hud::CommandPanel* command_panel, LabyrinthOfLore::Rendering::MousePointer* mouse_pointer)
   : render_surface(render_surface)
   , font_bin(font_bin)
   , message_scroll(message_scroll)
   , command_panel(command_panel)
   , mouse_pointer(mouse_pointer)
{
}


Renderer::~Renderer()
{
}


void Renderer::render_message_scroll()
{
ALLEGRO_FONT *message_scroll_font = font_bin->operator[]("gameovercre1.ttf -12");
allegro_flare::placement3d message_scroll_placement{0, 0, 0};
message_scroll_placement.size = AllegroFlare::vec3d(300, 100, 0);
message_scroll_placement.scale = AllegroFlare::vec3d(2.0, 2.0, 2.0);
message_scroll_placement.position = AllegroFlare::vec3d(al_get_bitmap_width(render_surface)/2, al_get_bitmap_height(render_surface) - 200, 0);
LabyrinthOfLore::Rendering::Hud::MessageScrollRenderer message_scroll_renderer(message_scroll_font, message_scroll, message_scroll_placement);
message_scroll_renderer.render();
return;

}

void Renderer::render_command_panel()
{
ALLEGRO_FONT *font = font_bin->operator[]("gameovercre1.ttf -12");
allegro_flare::placement3d placement{0, 0, 0};
placement.size = AllegroFlare::vec3d(300, 100, 0);
placement.scale = AllegroFlare::vec3d(2.0, 2.0, 2.0);
placement.position = AllegroFlare::vec3d(al_get_bitmap_width(render_surface)/2, al_get_bitmap_height(render_surface) - 200, 0);

LabyrinthOfLore::Rendering::Hud::CommandPanelRenderer command_panel_renderer(font, command_panel, placement);
command_panel_renderer.render();
return;

}

void Renderer::render()
{
if (!render_surface) throw std::runtime_error("cannot render HudRenderer with a nullptr render_surface");
if (!font_bin) throw std::runtime_error("cannot render HudRenderer with a nullptr font_bin");

al_set_target_bitmap(render_surface);
ALLEGRO_TRANSFORM transform;
al_identity_transform(&transform);
al_use_transform(&transform);

render_message_scroll();
render_command_panel();

if (mouse_pointer) mouse_pointer->render();

return;

}
} // namespace Hud
} // namespace Rendering
} // namespace LabyrinthOfLore


