

#include <LabyrinthOfLore/Entity/Base.hpp>



namespace LabyrinthOfLore
{
namespace Entity
{


Base::Base(allegro_flare::placement3d placement, allegro_flare::placement3d velocity)
   : placement(placement)
   , velocity(velocity)
{
}


Base::~Base()
{
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


