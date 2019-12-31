

#include <LabyrinthOfLore/Rendering/Hud/CommandPanelRenderer.hpp>
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
al_draw_text(font, al_color_name("white"), 0, 0, 0, " - command panel - ");

place.restore_transform();
return;

}
} // namespace Hud
} // namespace Rendering
} // namespace LabyrinthOfLore


