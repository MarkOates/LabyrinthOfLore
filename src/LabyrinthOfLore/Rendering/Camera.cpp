

#include <LabyrinthOfLore/Rendering/Camera.hpp>
#include <AllegroFlare/Useful.hpp>
#include <allegro5/allegro.h>
#include <allegro_flare/placement3d.h>


namespace LabyrinthOfLore
{
namespace Rendering
{


Camera::Camera(AllegroFlare::vec3d position, float yaw, float pitch)
   : position(position)
   , yaw(yaw)
   , pitch(pitch)
{
}


Camera::~Camera()
{
}


void Camera::build_custom_reverse_transform(allegro_flare::placement3d* placement, ALLEGRO_TRANSFORM* transform)
{
al_identity_transform(transform);

// translate
al_translate_transform_3d(transform, -placement->position.x, -placement->position.y, -placement->position.z);

// rotate
al_rotate_transform_3d(transform, 0, -1, 0, placement->rotation.y * AllegroFlare::TAU);
al_rotate_transform_3d(transform, -1, 0, 0, placement->rotation.x * AllegroFlare::TAU);
// al_rotate_transform_3d(transform, 0, 0, -1, placement->rotation.z * AllegroFlare::TAU);

// offset for alignment and anchors
//al_translate_transform_3d(transform, -placement->anchor.x, -placement->anchor.y, -placement->anchor.z);
//al_scale_transform_3d(transform, 1.0/placement->scale.x, 1.0/placement->scale.y, 1.0/placement->scale.z);
//al_translate_transform_3d(transform, placement->align.x*placement->size.x, placement->align.y*placement->size.y, placement->align.z*placement->size.z);

}

void Camera::start_projection(ALLEGRO_BITMAP* surface)
{
if (!surface) throw std::runtime_error("[Camera::start_projection] error: cannot set the projection on nullptr surface");

al_set_render_state(ALLEGRO_DEPTH_TEST, 1);
al_set_render_state(ALLEGRO_WRITE_MASK, ALLEGRO_MASK_DEPTH | ALLEGRO_MASK_RGBA);
al_clear_depth_buffer(1);

ALLEGRO_TRANSFORM transform;
allegro_flare::placement3d camera_view(AllegroFlare::vec3d(position.x, position.z, position.y));
//camera_view.rotation = AllegroFlare::vec3d(yaw, 0, 0);
camera_view.rotation = AllegroFlare::vec3d(pitch, -yaw, 0);
build_custom_reverse_transform(&camera_view, &transform);

float aspect_ratio = (float)al_get_bitmap_height(surface) / al_get_bitmap_width(surface);
al_perspective_transform(&transform, -1, aspect_ratio, 1, 1, -aspect_ratio, 100);
al_use_projection_transform(&transform);

return;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


