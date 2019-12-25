

#include <LabyrinthOfLore/Physics/EntityTileMapCollisionEvent.hpp>



namespace LabyrinthOfLore
{
namespace Physics
{


EntityTileMapCollisionEvent::EntityTileMapCollisionEvent(LabyrinthOfLore::Entity::Base* entity, int tile_type, int tile_x, int tile_y, LabyrinthOfLore::WorldMap::tile_face_t tile_face_collided_with, float force)
   : entity(entity)
   , tile_type(tile_type)
   , tile_x(tile_x)
   , tile_y(tile_y)
   , tile_face_collided_with(tile_face_collided_with)
   , force(force)
{
}


EntityTileMapCollisionEvent::~EntityTileMapCollisionEvent()
{
}


LabyrinthOfLore::Entity::Base* EntityTileMapCollisionEvent::get_entity()
{
   return entity;
}


int EntityTileMapCollisionEvent::get_tile_type()
{
   return tile_type;
}


int EntityTileMapCollisionEvent::get_tile_x()
{
   return tile_x;
}


int EntityTileMapCollisionEvent::get_tile_y()
{
   return tile_y;
}


LabyrinthOfLore::WorldMap::tile_face_t EntityTileMapCollisionEvent::get_tile_face_collided_with()
{
   return tile_face_collided_with;
}


float EntityTileMapCollisionEvent::get_force()
{
   return force;
}


} // namespace Physics
} // namespace LabyrinthOfLore


