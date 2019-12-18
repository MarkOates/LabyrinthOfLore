

#include <LabyrinthOfLore/Rendering/Camera.hpp>
#include <allegro5/allegro.h>


namespace LabyrinthOfLore
{
namespace Rendering
{


Camera::Camera(AllegroFlare::vec3d position)
   : position(position)
{
}


Camera::~Camera()
{
}


void Camera::start_projection(ALLEGRO_BITMAP* surface)
{
if (!surface) throw std::runtime_error("[Camera::start_projection] error: cannot set the projection on nullptr surface");

return;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


