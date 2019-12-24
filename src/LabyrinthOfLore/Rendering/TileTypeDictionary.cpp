

#include <LabyrinthOfLore/Rendering/TileTypeDictionary.hpp>



namespace LabyrinthOfLore
{
namespace Rendering
{


TileTypeDictionary::TileTypeDictionary(std::vector<LabyrinthOfLore::Rendering::TileTypeDefinition> definitions)
   : definitions(definitions)
{
}


TileTypeDictionary::~TileTypeDictionary()
{
}


LabyrinthOfLore::Rendering::TileTypeDefinition TileTypeDictionary::find_definition(int tile_type)
{
return LabyrinthOfLore::Rendering::TileTypeDefinition();

}
} // namespace Rendering
} // namespace LabyrinthOfLore


