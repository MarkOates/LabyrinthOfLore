

#include <LabyrinthOfLore/Rendering/Hud/MapButtonRenderer.hpp>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>


namespace LabyrinthOfLore
{
namespace Rendering
{
namespace Hud
{


MapButtonRenderer::MapButtonRenderer(ALLEGRO_FONT* font, LabyrinthOfLore::Hud::MapButton* map_button, allegro_flare::placement3d place)
   : font(font)
   , map_button(map_button)
   , place(place)
{
}


MapButtonRenderer::~MapButtonRenderer()
{
}


void MapButtonRenderer::render()
{
   if (!font) throw std::runtime_error("Cannot draw MapButton with a nullptr font");
   if (!map_button) throw std::runtime_error("Cannot draw MapButton with a nullptr map_button");

   place.start_transform();

   al_draw_filled_rounded_rectangle(0, 0, place.size.x, place.size.y, 6, 6, al_color_name("red"));
   al_draw_text(font, al_color_name("white"), 0, 0, 0, " - map button - ");

   place.restore_transform();
   return;
}
} // namespace Hud
} // namespace Rendering
} // namespace LabyrinthOfLore


