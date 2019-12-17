

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
//bool player_pressing_w_or_up = false;
//bool player_pressing_s_or_down = false;
//bool player_pressing_a = false;
//bool player_pressing_d = false;


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
  double posX = 0;
  double posY = 0;
  double posZ = 0;
  int worldMap[100][100] = { 0 };

  //move forward if no wall in front of you
  //if (player_pressing_w_or_up)
  //{
     //posX += dirX * moveSpeed;
     //posY += dirY * moveSpeed;
     if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
     if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
     posZ += dirZ;
  //}
  //move backwards if no wall behind you
  //if (player_pressing_s_or_down)
  //{
     //if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
     //if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
  //}

  // strafing
  //if (player_pressing_a)
  //{
     //float dirX2 = -dirY;
     //float dirY2 = dirX;
     //if(worldMap[int(posX + dirX2 * moveSpeed)][int(posY)] == false) posX += dirX2 * moveSpeed;
     //if(worldMap[int(posX)][int(posY + dirY2 * moveSpeed)] == false) posY += dirY2 * moveSpeed;
  //}
  //move backwards if no wall behind you
  //if (player_pressing_d)
  //{
     //float dirX2 = -dirY;
     //float dirY2 = dirX;
     //if(worldMap[int(posX - dirX2 * moveSpeed)][int(posY)] == false) posX -= dirX2 * moveSpeed;
     //if(worldMap[int(posX)][int(posY - dirY2 * moveSpeed)] == false) posY -= dirY2 * moveSpeed;
  //}

  entity->get_placement_ref().position.x = posX;
  entity->get_placement_ref().position.y = posY;
  entity->get_placement_ref().position.z = posZ;
}

return;

}
} // namespace Physics
} // namespace LabyrinthOfLore


