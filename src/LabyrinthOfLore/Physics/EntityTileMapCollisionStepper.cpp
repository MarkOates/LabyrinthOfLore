

#include <LabyrinthOfLore/Physics/EntityTileMapCollisionStepper.hpp>



namespace LabyrinthOfLore
{
namespace Physics
{


LabyrinthOfLore::WorldMap::TileMap EntityTileMapCollisionStepper::dummy_tile_map = {};


EntityTileMapCollisionStepper::EntityTileMapCollisionStepper(LabyrinthOfLore::WorldMap::TileMap& tile_map, std::vector<LabyrinthOfLore::Entity::Base*> entities)
   : tile_map(tile_map)
   , entities(entities)
{
}


EntityTileMapCollisionStepper::~EntityTileMapCollisionStepper()
{
}


LabyrinthOfLore::WorldMap::TileMap& EntityTileMapCollisionStepper::get_dummy_tile_map()
{
return dummy_tile_map;
}

void EntityTileMapCollisionStepper::process_step()
{
for (auto &entity : entities)
{
   AllegroFlare::vec2d player_xy = AllegroFlare::vec2d(
        entity->get_velocity_ref().position.x,
        entity->get_velocity_ref().position.y
     );
   AllegroFlare::vec2d x_y_movement_normalized = player_xy.normalized();
   float player_xy_magnitude = player_xy.get_magnitude();

   double dirX = x_y_movement_normalized.x;
   double dirY = x_y_movement_normalized.y; // normal
   double dirZ = entity->get_velocity_ref().position.z;
   double moveSpeed = player_xy_magnitude;
   double posX = entity->get_placement_ref().position.x;
   double posY = entity->get_placement_ref().position.y;
   double posZ = entity->get_placement_ref().position.z;
   int worldMap[100][100] = { 0 };

   if(tile_map.get_tile(int(posX + dirX * moveSpeed), int(posY)).get_height() <= posZ) posX += dirX * moveSpeed;
   if(tile_map.get_tile(int(posX), int(posY + dirY * moveSpeed)).get_height() <= posZ) posY += dirY * moveSpeed;
   posZ += dirZ;

   entity->get_placement_ref().position.x = posX;
   entity->get_placement_ref().position.y = posY;
   entity->get_placement_ref().position.z = posZ;
}

return;

}
} // namespace Physics
} // namespace LabyrinthOfLore


