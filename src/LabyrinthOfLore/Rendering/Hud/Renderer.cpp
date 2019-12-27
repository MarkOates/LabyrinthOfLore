

#include <LabyrinthOfLore/Rendering/Hud/Renderer.hpp>
#include <LabyrinthOfLore/Rendering/Hud/MessageScrollRenderer.hpp>
#include <LabyrinthOfLore/Rendering/Hud/CommandPanelRenderer.hpp>
#include <LabyrinthOfLore/Rendering/Hud/VitalityAndManaBarRenderer.hpp>
#include <LabyrinthOfLore/Rendering/Hud/CharacterPanelRenderer.hpp>
#include <LabyrinthOfLore/Rendering/Hud/MapButtonRenderer.hpp>
#include <LabyrinthOfLore/Rendering/Hud/RuneShelfRenderer.hpp>
#include <LabyrinthOfLore/Rendering/Hud/CompassRenderer.hpp>
#include <LabyrinthOfLore/Rendering/Hud/RotateCharacterPanelButtonRenderer.hpp>
#include <LabyrinthOfLore/Rendering/Hud/CommandsHintPaneRenderer.hpp>
#include <LabyrinthOfLore/Rendering/Hud/CurrentSpellsRenderer.hpp>
#include <LabyrinthOfLore/Rendering/Hud/ViewFrameRenderer.hpp>
#include <LabyrinthOfLore/Rendering/Hud/TitleTextRenderer.hpp>
#include <stdexcept>
#include <allegro5/allegro_color.h>
#include <allegro_flare/placement3d.h>


namespace LabyrinthOfLore
{
namespace Rendering
{
namespace Hud
{


Renderer::Renderer(ALLEGRO_BITMAP* render_surface, AllegroFlare::FontBin* font_bin, LabyrinthOfLore::Hud::MessageScroll* message_scroll, LabyrinthOfLore::Hud::CommandPanel* command_panel, LabyrinthOfLore::Hud::VitalityAndManaBar* vitality_and_mana_bar, LabyrinthOfLore::Hud::CharacterPanel* character_panel, LabyrinthOfLore::Hud::MapButton* map_button, LabyrinthOfLore::Hud::RuneShelf* rune_shelf, LabyrinthOfLore::Hud::Compass* compass, LabyrinthOfLore::Hud::RotateCharacterPanelButton* rotate_character_panel_button, LabyrinthOfLore::Hud::CommandsHintPane* commands_hint_pane, LabyrinthOfLore::Hud::CurrentSpells* current_spells, LabyrinthOfLore::Hud::ViewFrame* view_frame, LabyrinthOfLore::Hud::TitleText* title_text, LabyrinthOfLore::Rendering::MousePointer* mouse_pointer)
   : render_surface(render_surface)
   , font_bin(font_bin)
   , message_scroll(message_scroll)
   , command_panel(command_panel)
   , vitality_and_mana_bar(vitality_and_mana_bar)
   , character_panel(character_panel)
   , map_button(map_button)
   , rune_shelf(rune_shelf)
   , compass(compass)
   , rotate_character_panel_button(rotate_character_panel_button)
   , commands_hint_pane(commands_hint_pane)
   , current_spells(current_spells)
   , view_frame(view_frame)
   , title_text(title_text)
   , mouse_pointer(mouse_pointer)
{
}


Renderer::~Renderer()
{
}


ALLEGRO_FONT* Renderer::get_basic_lettering_font()
{
return font_bin->operator[]("Commodore_Rounded_v1.2.ttf -14");
}

void Renderer::render_message_scroll()
{
ALLEGRO_FONT *font = get_basic_lettering_font();
allegro_flare::placement3d placement{0, 0, 0};
placement.size = AllegroFlare::vec3d(450, 80, 0);
placement.scale = AllegroFlare::vec3d(2.0, 2.0, 2.0);
placement.position = AllegroFlare::vec3d(al_get_bitmap_width(render_surface)/2, al_get_bitmap_height(render_surface) - 150, 0);
LabyrinthOfLore::Rendering::Hud::MessageScrollRenderer message_scroll_renderer(font, message_scroll, placement);
message_scroll_renderer.render();
return;

}

void Renderer::render_command_panel()
{
ALLEGRO_FONT *font = font_bin->operator[]("gameovercre1.ttf -12");
allegro_flare::placement3d placement{0, 0, 0};
placement.align = AllegroFlare::vec3d(0.5, 0.5, 0);
placement.size = AllegroFlare::vec3d(130, 200, 0);
//placement.rotation = AllegroFlare::vec3d(0, 0, 0);
placement.scale = AllegroFlare::vec3d(2.0, 2.0, 2.0);
placement.position = AllegroFlare::vec3d(300, al_get_bitmap_height(render_surface)/3, 0);

LabyrinthOfLore::Rendering::Hud::CommandPanelRenderer command_panel_renderer(font, command_panel, placement);
command_panel_renderer.render();
return;

}

void Renderer::render_vitality_and_mana_bar()
{
ALLEGRO_FONT *font = font_bin->operator[]("gameovercre1.ttf -12");
allegro_flare::placement3d placement{0, 0, 0};
placement.size = AllegroFlare::vec3d(200, 20, 0);
placement.scale = AllegroFlare::vec3d(2.0, 2.0, 2.0);
placement.position = AllegroFlare::vec3d(al_get_bitmap_width(render_surface)/2, al_get_bitmap_height(render_surface) - 200 - 80, 0);

LabyrinthOfLore::Rendering::Hud::VitalityAndManaBarRenderer vitality_and_mana_bar_renderer(font, vitality_and_mana_bar, placement);
vitality_and_mana_bar_renderer.render();
return;

}

void Renderer::render_character_panel()
{
ALLEGRO_FONT *font = font_bin->operator[]("gameovercre1.ttf -12");
allegro_flare::placement3d placement{0, 0, 0};
placement.align = AllegroFlare::vec3d(0.5, 0.5, 0);
placement.size = AllegroFlare::vec3d(130, 200, 0);
placement.scale = AllegroFlare::vec3d(2.0, 2.0, 2.0);
placement.position = AllegroFlare::vec3d(al_get_bitmap_width(render_surface) - 300, al_get_bitmap_height(render_surface)/3, 0);

LabyrinthOfLore::Rendering::Hud::CharacterPanelRenderer renderer(font, character_panel, placement);
renderer.render();
return;

}

void Renderer::render_map_button()
{
ALLEGRO_FONT *font = font_bin->operator[]("gameovercre1.ttf -12");
allegro_flare::placement3d placement{0, 0, 0};
placement.align = AllegroFlare::vec3d(0.5, 0.5, 0);
placement.size = AllegroFlare::vec3d(80, 50, 0);
placement.scale = AllegroFlare::vec3d(2.0, 2.0, 2.0);
placement.position = AllegroFlare::vec3d(300, al_get_bitmap_height(render_surface) - 170, 0);

LabyrinthOfLore::Rendering::Hud::MapButtonRenderer renderer(font, map_button, placement);
renderer.render();
return;

}

void Renderer::render_rune_shelf()
{
ALLEGRO_FONT *font = font_bin->operator[]("gameovercre1.ttf -12");
allegro_flare::placement3d placement{0, 0, 0};
placement.align = AllegroFlare::vec3d(0.5, 0.5, 0);
placement.size = AllegroFlare::vec3d(80, 80, 0);
placement.scale = AllegroFlare::vec3d(2.0, 2.0, 2.0);
placement.position = AllegroFlare::vec3d(al_get_bitmap_width(render_surface) - 300, al_get_bitmap_height(render_surface) - 170, 0);

LabyrinthOfLore::Rendering::Hud::RuneShelfRenderer renderer(font, rune_shelf, placement);
renderer.render();
return;

}

void Renderer::render_compass()
{
ALLEGRO_FONT *font = font_bin->operator[]("gameovercre1.ttf -12");
allegro_flare::placement3d placement{0, 0, 0};
placement.align = AllegroFlare::vec3d(0.5, 0.5, 0);
placement.size = AllegroFlare::vec3d(90, 50, 0);
placement.scale = AllegroFlare::vec3d(2.0, 2.0, 2.0);
placement.position = AllegroFlare::vec3d(300, al_get_bitmap_height(render_surface) - 300, 0);


LabyrinthOfLore::Rendering::Hud::CompassRenderer renderer(font, compass, placement);
renderer.render();
return;

}

void Renderer::render_rotate_character_panel_button()
{
ALLEGRO_FONT *font = font_bin->operator[]("gameovercre1.ttf -12");
allegro_flare::placement3d placement{0, 0, 0};
placement.align = AllegroFlare::vec3d(0.5, 0.5, 0);
placement.size = AllegroFlare::vec3d(40, 20, 0);
placement.scale = AllegroFlare::vec3d(2.0, 2.0, 2.0);
placement.position = AllegroFlare::vec3d(al_get_bitmap_width(render_surface) - 300, al_get_bitmap_height(render_surface) - 370, 0);

LabyrinthOfLore::Rendering::Hud::RotateCharacterPanelButtonRenderer renderer(font, rotate_character_panel_button, placement);
renderer.render();
return;

}

void Renderer::render_commands_hint_pane()
{
ALLEGRO_FONT *font = font_bin->operator[]("gameovercre1.ttf -12");
allegro_flare::placement3d placement{0, 0, 0};
placement.align = AllegroFlare::vec3d(0.5, 0.5, 0);
placement.size = AllegroFlare::vec3d(30, 100, 0);
placement.scale = AllegroFlare::vec3d(2.0, 2.0, 2.0);
placement.position = AllegroFlare::vec3d(al_get_bitmap_width(render_surface) - 600, al_get_bitmap_height(render_surface)/3*2, 0);

LabyrinthOfLore::Rendering::Hud::CommandsHintPaneRenderer renderer(font, commands_hint_pane, placement);
renderer.render();
return;

}

void Renderer::render_current_spells()
{
ALLEGRO_FONT *font = font_bin->operator[]("gameovercre1.ttf -12");
allegro_flare::placement3d placement{0, 0, 0};
placement.align = AllegroFlare::vec3d(0.5, 0.5, 0);
placement.size = AllegroFlare::vec3d(40, 30, 0);
placement.scale = AllegroFlare::vec3d(2.0, 2.0, 2.0);
placement.position = AllegroFlare::vec3d(470, al_get_bitmap_height(render_surface) - 420, 0);

LabyrinthOfLore::Rendering::Hud::CurrentSpellsRenderer renderer(font, current_spells, placement);
renderer.render();
return;

}

void Renderer::render_view_frame()
{
ALLEGRO_FONT *font = font_bin->operator[]("gameovercre1.ttf -12");
allegro_flare::placement3d placement{0, 0, 0};
placement.align = AllegroFlare::vec3d(0.5, 0.5, 0);
placement.size = AllegroFlare::vec3d(al_get_bitmap_width(render_surface)/2-100, al_get_bitmap_height(render_surface)/2-100, 0);
placement.scale = AllegroFlare::vec3d(2.0, 2.0, 2.0);
placement.position = AllegroFlare::vec3d(al_get_bitmap_width(render_surface)/2, al_get_bitmap_height(render_surface)/2 - 80, 0);

LabyrinthOfLore::Rendering::Hud::ViewFrameRenderer renderer(font, view_frame, placement);
renderer.render();
return;

}

void Renderer::render_title_text()
{
ALLEGRO_FONT *font = font_bin->operator[]("gameovercre1.ttf -12");
allegro_flare::placement3d placement{0, 0, 0};
placement.align = AllegroFlare::vec3d(0.5, 0.5, 0);
placement.size = AllegroFlare::vec3d(400, 100, 0);
placement.scale = AllegroFlare::vec3d(2.0, 2.0, 2.0);
placement.position = AllegroFlare::vec3d(al_get_bitmap_width(render_surface)/2, al_get_bitmap_height(render_surface)/5*2, 0);

LabyrinthOfLore::Rendering::Hud::TitleTextRenderer renderer(font, title_text, placement);
renderer.render();
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
//render_command_panel();
//render_vitality_and_mana_bar();
//render_character_panel();
//render_map_button();
//render_rune_shelf();
//render_compass();
//render_rotate_character_panel_button();
//render_commands_hint_pane();
//render_current_spells();
//render_view_frame();
//render_title_text();

if (mouse_pointer) mouse_pointer->render();

return;

}
} // namespace Hud
} // namespace Rendering
} // namespace LabyrinthOfLore


