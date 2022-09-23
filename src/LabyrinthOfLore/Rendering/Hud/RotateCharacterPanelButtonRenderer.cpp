

#include <LabyrinthOfLore/Rendering/Hud/RotateCharacterPanelButtonRenderer.hpp>

#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>


namespace LabyrinthOfLore
{
namespace Rendering
{
namespace Hud
{


RotateCharacterPanelButtonRenderer::RotateCharacterPanelButtonRenderer(ALLEGRO_FONT* font, LabyrinthOfLore::Hud::RotateCharacterPanelButton* rotate_character_panel_button, allegro_flare::placement3d place)
   : font(font)
   , rotate_character_panel_button(rotate_character_panel_button)
   , place(place)
{
}


RotateCharacterPanelButtonRenderer::~RotateCharacterPanelButtonRenderer()
{
}


void RotateCharacterPanelButtonRenderer::render()
{
   if (!font) throw std::runtime_error("Cannot draw RotateCharacterPanelButtonRenderer with a nullptr font");
   if (!rotate_character_panel_button) throw std::runtime_error("Cannot draw RotateCharacterPanelButtonRenderer with a nullptr rotate_character_panel_button");

   place.start_transform();

   al_draw_filled_rounded_rectangle(0, 0, place.size.x, place.size.y, 6, 6, al_color_name("red"));
   al_draw_text(font, al_color_name("white"), 0, 0, 0, " - rotate character panel button - ");

   place.restore_transform();
   return;
}


} // namespace Hud
} // namespace Rendering
} // namespace LabyrinthOfLore


