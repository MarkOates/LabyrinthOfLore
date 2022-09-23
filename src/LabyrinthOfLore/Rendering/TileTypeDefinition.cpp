

#include <LabyrinthOfLore/Rendering/TileTypeDefinition.hpp>




namespace LabyrinthOfLore
{
namespace Rendering
{


TileTypeDefinition::TileTypeDefinition(int tile_index_for_front_and_back_texture, int tile_index_for_right_and_left_texture, int tile_index_for_top_texture)
   : tile_index_for_front_and_back_texture(tile_index_for_front_and_back_texture)
   , tile_index_for_right_and_left_texture(tile_index_for_right_and_left_texture)
   , tile_index_for_top_texture(tile_index_for_top_texture)
{
}


TileTypeDefinition::~TileTypeDefinition()
{
}


int TileTypeDefinition::get_tile_index_for_front_and_back_texture() const
{
   return tile_index_for_front_and_back_texture;
}


int TileTypeDefinition::get_tile_index_for_right_and_left_texture() const
{
   return tile_index_for_right_and_left_texture;
}


int TileTypeDefinition::get_tile_index_for_top_texture() const
{
   return tile_index_for_top_texture;
}




} // namespace Rendering
} // namespace LabyrinthOfLore


