

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
return LabyrinthOfLore::Rendering::TileTypeDictionary({
   { 1, LabyrinthOfLore::Rendering::TileTypeDefinition(tile_num+1, tile_num+1, tile_num) },
   { 2, LabyrinthOfLore::Rendering::TileTypeDefinition(tile_num+1, tile_num+2, tile_num) },
});

}
} // namespace LabyrinthOfLoreGame


