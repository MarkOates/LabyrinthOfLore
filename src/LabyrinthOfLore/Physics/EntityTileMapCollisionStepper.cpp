

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
bool player_pressing_w_or_up = false;
bool player_pressing_s_or_down = false;
bool player_pressing_a = false;
bool player_pressing_d = false;

double dirX = 0;
double dirY = 1; // normal
double moveSpeed;
double posX = 0;
double posY = 0;
int worldMap[100][100] = { 0 };

//move forward if no wall in front of you
if (player_pressing_w_or_up)
{
   if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
   if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
}
//move backwards if no wall behind you
if (player_pressing_s_or_down)
{
   if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
   if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
}

// strafing
if (player_pressing_a)
{
   float dirX2 = -dirY;
   float dirY2 = dirX;
   if(worldMap[int(posX + dirX2 * moveSpeed)][int(posY)] == false) posX += dirX2 * moveSpeed;
   if(worldMap[int(posX)][int(posY + dirY2 * moveSpeed)] == false) posY += dirY2 * moveSpeed;
}
//move backwards if no wall behind you
if (player_pressing_d)
{
   float dirX2 = -dirY;
   float dirY2 = dirX;
   if(worldMap[int(posX - dirX2 * moveSpeed)][int(posY)] == false) posX -= dirX2 * moveSpeed;
   if(worldMap[int(posX)][int(posY - dirY2 * moveSpeed)] == false) posY -= dirY2 * moveSpeed;
}

return;

}
} // namespace Physics
} // namespace LabyrinthOfLore


