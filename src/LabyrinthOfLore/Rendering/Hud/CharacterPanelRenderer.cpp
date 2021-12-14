

#include <LabyrinthOfLore/Rendering/Hud/CharacterPanelRenderer.hpp>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>


namespace LabyrinthOfLore
{
namespace Rendering
{
namespace Hud
{


CharacterPanelRenderer::CharacterPanelRenderer(ALLEGRO_FONT* font, LabyrinthOfLore::Hud::CharacterPanel* character_panel, allegro_flare::placement3d place)
   : font(font)
   , character_panel(character_panel)
   , place(place)
{
}


CharacterPanelRenderer::~CharacterPanelRenderer()
{
}


void CharacterPanelRenderer::render()
{
   if (!font) throw std::runtime_error("Cannot draw CharacterPanelRenderer with a nullptr font");
   if (!character_panel) throw std::runtime_error("Cannot draw CharacterPanelRenderer with a nullptr character_panel");

   place.start_transform();

   //al_draw_filled_rounded_rectangle(0, 0, place.size.x, place.size.y, 6, 6, al_color_name("red"));
   //al_draw_text(font, al_color_name("white"), 0, 0, 0, " - character panel - ");

   if (character_panel->has_item(2)) // assuming 2 is ring of loft
     al_draw_text(font, al_color_name("white"), 0, 0, 0, " + ring of loft");

   place.restore_transform();
   return;
}
} // namespace Hud
} // namespace Rendering
} // namespace LabyrinthOfLore


