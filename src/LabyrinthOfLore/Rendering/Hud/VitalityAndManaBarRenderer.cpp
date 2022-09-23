

#include <LabyrinthOfLore/Rendering/Hud/VitalityAndManaBarRenderer.hpp>

#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>


namespace LabyrinthOfLore
{
namespace Rendering
{
namespace Hud
{


VitalityAndManaBarRenderer::VitalityAndManaBarRenderer(ALLEGRO_FONT* font, LabyrinthOfLore::Hud::VitalityAndManaBar* vitality_and_mana_bar, allegro_flare::placement3d place)
   : font(font)
   , vitality_and_mana_bar(vitality_and_mana_bar)
   , place(place)
{
}


VitalityAndManaBarRenderer::~VitalityAndManaBarRenderer()
{
}


void VitalityAndManaBarRenderer::render()
{
   if (!font) throw std::runtime_error("Cannot draw VitalityAndManaBar with a nullptr font");
   if (!vitality_and_mana_bar) throw std::runtime_error("Cannot draw VitalityAndManaBar with a nullptr object");

   place.start_transform();

   al_draw_filled_rounded_rectangle(0, 0, place.size.x, place.size.y, 6, 6, al_color_name("brown"));
   al_draw_text(font, al_color_name("white"), 0, 0, 0, " -- vitality and mana bar -- ");

   place.restore_transform();
   return;
}


} // namespace Hud
} // namespace Rendering
} // namespace LabyrinthOfLore


