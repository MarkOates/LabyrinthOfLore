

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
ALLEGRO_KEYBOARD_STATE keyboard_state;
al_get_keyboard_state(&keyboard_state);

//move forward if no wall in front of you
if (al_key_down(&keyboard_state, ALLEGRO_KEY_W) || al_key_down(&keyboard_state, ALLEGRO_KEY_UP))
{
   velocity_y = 1.0;
   if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
   if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
}
//move backwards if no wall behind you
if (al_key_down(&keyboard_state, ALLEGRO_KEY_S) || al_key_down(&keyboard_state, ALLEGRO_KEY_DOWN))
{
   velocity_y = -1.0;
   if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
   if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
}

// strafing
if (al_key_down(&keyboard_state, ALLEGRO_KEY_A))
{
   float dirX2 = -dirY;
   float dirY2 = dirX;
   if(worldMap[int(posX + dirX2 * moveSpeed)][int(posY)] == false) posX += dirX2 * moveSpeed;
   if(worldMap[int(posX)][int(posY + dirY2 * moveSpeed)] == false) posY += dirY2 * moveSpeed;
}
//move backwards if no wall behind you
if (al_key_down(&keyboard_state, ALLEGRO_KEY_D))
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


