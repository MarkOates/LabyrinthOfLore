

#include <LabyrinthOfLore/Rendering/Hud/CommandsHintPaneRenderer.hpp>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>


namespace LabyrinthOfLore
{
namespace Rendering
{
namespace Hud
{


CommandsHintPaneRenderer::CommandsHintPaneRenderer(ALLEGRO_FONT* font, LabyrinthOfLore::Hud::CommandsHintPane* commands_hint_pane, allegro_flare::placement3d place)
   : font(font)
   , commands_hint_pane(commands_hint_pane)
   , place(place)
{
}


CommandsHintPaneRenderer::~CommandsHintPaneRenderer()
{
}


void CommandsHintPaneRenderer::render()
{
   if (!font) throw std::runtime_error("Cannot draw CommandsHintPane with a nullptr font");
   if (!commands_hint_pane) throw std::runtime_error("Cannot draw CommandsHintPane with a nullptr commands_hint_pane");

   place.start_transform();

   al_draw_filled_rounded_rectangle(0, 0, place.size.x, place.size.y, 6, 6, al_color_name("red"));
   al_draw_text(font, al_color_name("white"), 0, 0, 0, " - commands hint pane - ");

   place.restore_transform();
   return;
}
} // namespace Hud
} // namespace Rendering
} // namespace LabyrinthOfLore


