

#include <LabyrinthOfLore/Entity/Base.hpp>



namespace LabyrinthOfLore
{
namespace Entity
{


Base::Base(ALLEGRO_BITMAP* bitmap, allegro_flare::placement3d placement, allegro_flare::placement3d velocity)
   : bitmap(bitmap)
   , placement(placement)
   , velocity(velocity)
{
}


Base::~Base()
{
}


void Base::set_bitmap(ALLEGRO_BITMAP* bitmap)
{
   this->bitmap = bitmap;
}


ALLEGRO_BITMAP* Base::get_bitmap()
{
   return bitmap;
}


allegro_flare::placement3d &Base::get_placement_ref()
{
   return placement;
}


std::string Base::run()
{
return "Hello World!";
}
} // namespace Entity
} // namespace LabyrinthOfLore


