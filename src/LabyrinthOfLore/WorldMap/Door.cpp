

#include <LabyrinthOfLore/WorldMap/Door.hpp>




namespace LabyrinthOfLore
{
namespace WorldMap
{


Door::Door(std::string level_identifier, float spawn_x, float spawn_y, float spawn_z, float spawn_facing_yaw)
   : level_identifier(level_identifier)
   , spawn_x(spawn_x)
   , spawn_y(spawn_y)
   , spawn_z(spawn_z)
   , spawn_facing_yaw(spawn_facing_yaw)
{
}


Door::~Door()
{
}


std::string Door::get_level_identifier() const
{
   return level_identifier;
}


float Door::get_spawn_x() const
{
   return spawn_x;
}


float Door::get_spawn_y() const
{
   return spawn_y;
}


float Door::get_spawn_z() const
{
   return spawn_z;
}


float Door::get_spawn_facing_yaw() const
{
   return spawn_facing_yaw;
}




} // namespace WorldMap
} // namespace LabyrinthOfLore


