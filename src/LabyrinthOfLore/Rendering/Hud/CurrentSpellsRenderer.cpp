

#include <LabyrinthOfLore/Rendering/Hud/CurrentSpellsRenderer.hpp>

#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>


namespace LabyrinthOfLore
{
namespace Rendering
{
namespace Hud
{


CurrentSpellsRenderer::CurrentSpellsRenderer(ALLEGRO_FONT* font, LabyrinthOfLore::Hud::CurrentSpells* current_spells, allegro_flare::placement3d place)
   : font(font)
   , current_spells(current_spells)
   , place(place)
{
}


CurrentSpellsRenderer::~CurrentSpellsRenderer()
{
}


void CurrentSpellsRenderer::render()
{
   if (!font) throw std::runtime_error("Cannot draw CurrentSpells with a nullptr font");
   if (!current_spells) throw std::runtime_error("Cannot draw CurrentSpells with a nullptr current_spells");

   place.start_transform();

   al_draw_filled_rounded_rectangle(0, 0, place.size.x, place.size.y, 6, 6, al_color_name("red"));
   al_draw_text(font, al_color_name("white"), 0, 0, 0, " - current spells - ");

   place.restore_transform();
   return;
}


} // namespace Hud
} // namespace Rendering
} // namespace LabyrinthOfLore


