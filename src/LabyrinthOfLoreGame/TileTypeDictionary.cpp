

#include <LabyrinthOfLoreGame/TileTypeDictionary.hpp>



namespace LabyrinthOfLoreGame
{


TileTypeDictionary::TileTypeDictionary()
{
}


TileTypeDictionary::~TileTypeDictionary()
{
}


LabyrinthOfLore::Rendering::TileTypeDictionary TileTypeDictionary::build_tile_type_dictionary()
{
int tile_num = 0;
int spawn_point = 4;
return LabyrinthOfLore::Rendering::TileTypeDictionary({
   { 1,           LabyrinthOfLore::Rendering::TileTypeDefinition(tile_num+1, tile_num+1, tile_num) },
   { 2,           LabyrinthOfLore::Rendering::TileTypeDefinition(tile_num+1, tile_num+2, tile_num) },
   { 3,           LabyrinthOfLore::Rendering::TileTypeDefinition(tile_num+1, tile_num+2, tile_num) },
   { spawn_point, LabyrinthOfLore::Rendering::TileTypeDefinition(tile_num+1, tile_num+1, tile_num) }, // spawn point
   
   // doors out
   { number_for_door_no(0), LabyrinthOfLore::Rendering::TileTypeDefinition(tile_num+2, tile_num+2, tile_num) }, // door to level 
   { number_for_door_no(1), LabyrinthOfLore::Rendering::TileTypeDefinition(tile_num+2, tile_num+2, tile_num) },
   { number_for_door_no(2), LabyrinthOfLore::Rendering::TileTypeDefinition(tile_num+2, tile_num+2, tile_num) },
   { number_for_door_no(3), LabyrinthOfLore::Rendering::TileTypeDefinition(tile_num+2, tile_num+2, tile_num) },
   { number_for_door_no(4), LabyrinthOfLore::Rendering::TileTypeDefinition(tile_num+2, tile_num+2, tile_num) },
   { number_for_door_no(5), LabyrinthOfLore::Rendering::TileTypeDefinition(tile_num+2, tile_num+2, tile_num) },
   { number_for_door_no(6), LabyrinthOfLore::Rendering::TileTypeDefinition(tile_num+2, tile_num+2, tile_num) },
});

}

int TileTypeDictionary::number_for_door_no(int door_number)
{
int level_number_doors_start = 20;
return level_number_doors_start + door_number;

}
} // namespace LabyrinthOfLoreGame


