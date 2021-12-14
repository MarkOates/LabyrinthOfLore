

#include <LabyrinthOfLore/Rendering/TileTypeDictionary.hpp>



namespace LabyrinthOfLore
{
namespace Rendering
{


TileTypeDictionary::TileTypeDictionary(std::map<int, LabyrinthOfLore::Rendering::TileTypeDefinition> definitions)
   : definitions(definitions)
{
}


TileTypeDictionary::~TileTypeDictionary()
{
}


LabyrinthOfLore::Rendering::TileTypeDefinition TileTypeDictionary::find_definition(int tile_type)
{
   if (definitions.find(tile_type) == definitions.end()) return LabyrinthOfLore::Rendering::TileTypeDefinition();
   return definitions[tile_type];
}
} // namespace Rendering
} // namespace LabyrinthOfLore


