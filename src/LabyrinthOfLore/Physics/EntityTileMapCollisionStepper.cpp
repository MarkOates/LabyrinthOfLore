

#include <LabyrinthOfLore/Physics/EntityTileMapCollisionStepper.hpp>
#include <cmath>
#include <algorithm>
#include <algorithm>


namespace LabyrinthOfLore
{
namespace Physics
{


LabyrinthOfLore::WorldMap::TileMap EntityTileMapCollisionStepper::dummy_tile_map = {};


float EntityTileMapCollisionStepper::ceiling_height = 100.0f;


float EntityTileMapCollisionStepper::floor_height = 0.0f;


float EntityTileMapCollisionStepper::auto_ascend_threshold = 0.25f;


EntityTileMapCollisionStepper::EntityTileMapCollisionStepper(LabyrinthOfLore::WorldMap::TileMap& tile_map, std::vector<LabyrinthOfLore::Entity::Base*> entities)
   : tile_map(tile_map)
   , entities(entities)
{
}


EntityTileMapCollisionStepper::~EntityTileMapCollisionStepper()
{
}


float EntityTileMapCollisionStepper::get_ceiling_height()
{
   return ceiling_height;
}


float EntityTileMapCollisionStepper::get_floor_height()
{
   return floor_height;
}


float EntityTileMapCollisionStepper::get_auto_ascend_threshold()
{
   return auto_ascend_threshold;
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

   if (fabs(entity->get_velocity_ref().position.x) <= 0.00001 && fabs(entity->get_velocity_ref().position.y) <= 0.00001)
   {
      x_y_movement_normalized = AllegroFlare::vec2d(0, 1);
      player_xy_magnitude = 0.0;
   }

   double dirX = x_y_movement_normalized.x;
   double dirY = x_y_movement_normalized.y; // normal
   double dirZ = entity->get_velocity_ref().position.z;
   double moveSpeed = player_xy_magnitude;
   double posX = entity->get_placement_ref().position.x;
   double posY = entity->get_placement_ref().position.y;
   double posZ = entity->get_placement_ref().position.z;
   int worldMap[100][100] = { 0 };

   if(tile_map.get_tile(int(posX + dirX * moveSpeed), int(posY)).get_height() <= (posZ + get_auto_ascend_threshold()))
   {
      posX += dirX * moveSpeed;
   }
   if(tile_map.get_tile(int(posX), int(posY + dirY * moveSpeed)).get_height() <= (posZ + get_auto_ascend_threshold()))
   {
      posY += dirY * moveSpeed;
   }
   if ((posZ + dirZ) < tile_map.get_tile(int(posX), int(posY)).get_height())
   {
      posZ = tile_map.get_tile(int(posX), int(posY)).get_height() + 0.01f;
      entity->get_velocity_ref().position.z = 0.0f;
   }
   else
   {
      posZ += dirZ;
   }

   entity->get_placement_ref().position.x = posX;
   entity->get_placement_ref().position.y = posY;
   float clamped_ceiling = std::min<float>(get_ceiling_height()-0.01, posZ);
   if (fabs(clamped_ceiling - posZ) > 0.0001f)
   {
      // has been clamped at the ceiling
      entity->get_velocity_ref().position.z = 0.0f;
   }

   float clamped_floor = std::max<float>(get_floor_height()+0.01, clamped_ceiling);
   if (fabs(clamped_floor - posZ) > 0.0001f)
   {
      // has been clamped at the ceiling
      entity->get_velocity_ref().position.z = 0.0f;
   }

   entity->get_placement_ref().position.z = clamped_floor;
}

return;

}
} // namespace Physics
} // namespace LabyrinthOfLore


