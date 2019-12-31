

#include <LabyrinthOfLore/Rendering/Hud/CommandPanelRenderer.hpp>
#include <vector>
#include <LabyrinthOfLore/Hud/CommandPanelModeEnum.hpp>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>


namespace LabyrinthOfLore
{
namespace Rendering
{
namespace Hud
{


CommandPanelRenderer::CommandPanelRenderer(ALLEGRO_FONT* font, LabyrinthOfLore::Hud::CommandPanel* command_panel, allegro_flare::placement3d place)
   : font(font)
   , command_panel(command_panel)
   , place(place)
{
}


CommandPanelRenderer::~CommandPanelRenderer()
{
}


void CommandPanelRenderer::render()
{
if (!font) throw std::runtime_error("Cannot draw CommandPanelRenderer with a nullptr font");
if (!command_panel) throw std::runtime_error("Cannot draw CommandPanelRenderer with a nullptr command_panel");

place.start_transform();

//al_draw_filled_rounded_rectangle(0, 0, place.size.x, place.size.y, 6, 6, al_color_name("red"));
//for (unsigned i=0; i<)
//{
//}

std::vector<std::pair<std::string, LabyrinthOfLore::Hud::command_mode_t>> modes_for_display = {
   { "[T]alk", LabyrinthOfLore::Hud::COMMAND_MODE_TALK, },
   { "[P]ickup", LabyrinthOfLore::Hud::COMMAND_MODE_PICKUP, },
   { "[L]look", LabyrinthOfLore::Hud::COMMAND_MODE_LOOK, },
   { "Attac[k]", LabyrinthOfLore::Hud::COMMAND_MODE_ATTACK, },
   { "[U]se", LabyrinthOfLore::Hud::COMMAND_MODE_USE, },
};

float top_bottom_padding = 30.0f;
float center_y = place.size.y/2;
float full_height = (place.size.y - top_bottom_padding);
float vertical_element_spacing = full_height / modes_for_display.size();

int i = 0;
for (auto &mode_for_display : modes_for_display)
{
   i++;
   al_draw_text(font, al_color_name("white"), place.size.x/2, vertical_element_spacing * i, ALLEGRO_ALIGN_CENTRE, mode_for_display.first.c_str());
}

place.restore_transform();
return;

}
} // namespace Hud
} // namespace Rendering
} // namespace LabyrinthOfLore


