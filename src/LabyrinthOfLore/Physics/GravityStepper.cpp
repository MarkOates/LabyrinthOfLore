

#include <LabyrinthOfLore/Physics/GravityStepper.hpp>



namespace LabyrinthOfLore
{
namespace Physics
{


GravityStepper::GravityStepper(std::vector<LabyrinthOfLore::Entity::Base*> entities)
   : entities(entities)
   , gravity(0.0f, 0.0f, -0.003f)
{
}


GravityStepper::~GravityStepper()
{
}


void GravityStepper::process_step()
{
for (auto &entity : entities)
{
   entity->get_velocity_ref().position += gravity;
}

}
} // namespace Physics
} // namespace LabyrinthOfLore


