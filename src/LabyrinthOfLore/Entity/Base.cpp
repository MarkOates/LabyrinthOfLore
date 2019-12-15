

#include <LabyrinthOfLore/Entity/Base.hpp>



namespace LabyrinthOfLore
{
namespace Entity
{


Base::Base(ALLEGRO_BITMAP* bitmap, AllegroFlare::Model3D* model, allegro_flare::placement3d placement, allegro_flare::placement3d velocity, bool billboard_at_camera)
   : bitmap(bitmap)
   , model(model)
   , placement(placement)
   , velocity(velocity)
   , billboard_at_camera(billboard_at_camera)
{
}


Base::~Base()
{
}


void Base::set_bitmap(ALLEGRO_BITMAP* bitmap)
{
   this->bitmap = bitmap;
}


void Base::set_model(AllegroFlare::Model3D* model)
{
   this->model = model;
}


void Base::set_billboard_at_camera(bool billboard_at_camera)
{
   this->billboard_at_camera = billboard_at_camera;
}


ALLEGRO_BITMAP* Base::get_bitmap()
{
   return bitmap;
}


AllegroFlare::Model3D* Base::get_model()
{
   return model;
}


bool Base::get_billboard_at_camera()
{
   return billboard_at_camera;
}


allegro_flare::placement3d &Base::get_placement_ref()
{
   return placement;
}


} // namespace Entity
} // namespace LabyrinthOfLore


