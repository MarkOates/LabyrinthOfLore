

#include <LabyrinthOfLore/Rendering/Camera.hpp>
#include <allegro5/allegro.h>
#include <allegro_flare/placement3d.h>


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

al_set_render_state(ALLEGRO_DEPTH_TEST, 1);
al_set_render_state(ALLEGRO_WRITE_MASK, ALLEGRO_MASK_DEPTH | ALLEGRO_MASK_RGBA);
al_clear_depth_buffer(1);

ALLEGRO_TRANSFORM transform;
allegro_flare::placement3d camera_view(0, 0, 2);
camera_view.build_reverse_transform(&transform);

float aspect_ratio = (float)al_get_bitmap_height(surface) / al_get_bitmap_width(surface);
al_perspective_transform(&transform, -1, aspect_ratio, 1, 1, -aspect_ratio, 100);
al_use_projection_transform(&transform);

return;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


