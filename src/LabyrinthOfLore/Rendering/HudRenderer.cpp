

#include <LabyrinthOfLore/Rendering/HudRenderer.hpp>
#include <stdexcept>


namespace LabyrinthOfLore
{
namespace Rendering
{


HudRenderer::HudRenderer(ALLEGRO_BITMAP* render_surface, LabyrinthOfLore::Rendering::MousePointer* mouse_pointer)
   : render_surface(render_surface)
   , mouse_pointer(mouse_pointer)
{
}


HudRenderer::~HudRenderer()
{
}


void HudRenderer::render()
{
if (!render_surface) throw std::runtime_error("cannot render HudRenderer with a nullptr render_surface");

al_set_target_bitmap(render_surface);

if (mouse_pointer) mouse_pointer->render();

return;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


