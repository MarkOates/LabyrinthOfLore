

#include <LabyrinthOfLore/Entity/Base.hpp>



namespace LabyrinthOfLore
{
namespace Entity
{


Base::Base(ALLEGRO_BITMAP* bitmap, AllegroFlare::Model3D* model, std::string identifier_for_level_within, allegro_flare::placement3d placement, allegro_flare::placement3d velocity, bool billboard_at_camera)
   : AllegroFlare::ElementID({})
   , bitmap(bitmap)
   , model(model)
   , identifier_for_level_within(identifier_for_level_within)
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


void Base::set_identifier_for_level_within(std::string identifier_for_level_within)
{
   this->identifier_for_level_within = identifier_for_level_within;
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


std::string Base::get_identifier_for_level_within()
{
   return identifier_for_level_within;
}


bool Base::get_billboard_at_camera()
{
   return billboard_at_camera;
}


allegro_flare::placement3d &Base::get_placement_ref()
{
   return placement;
}


allegro_flare::placement3d &Base::get_velocity_ref()
{
   return velocity;
}


} // namespace Entity
} // namespace LabyrinthOfLore


