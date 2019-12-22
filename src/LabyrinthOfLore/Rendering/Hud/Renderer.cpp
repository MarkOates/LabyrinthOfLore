

#include <LabyrinthOfLore/Rendering/Hud/Renderer.hpp>
#include <stdexcept>


namespace LabyrinthOfLore
{
namespace Rendering
{
namespace Hud
{


Renderer::Renderer(ALLEGRO_BITMAP* render_surface, LabyrinthOfLore::Rendering::MousePointer* mouse_pointer)
   : render_surface(render_surface)
   , mouse_pointer(mouse_pointer)
{
}


Renderer::~Renderer()
{
}


void Renderer::render()
{
if (!render_surface) throw std::runtime_error("cannot render HudRenderer with a nullptr render_surface");

al_set_target_bitmap(render_surface);

if (mouse_pointer) mouse_pointer->render();

return;

}
} // namespace Hud
} // namespace Rendering
} // namespace LabyrinthOfLore


