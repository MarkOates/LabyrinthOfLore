

#include <LabyrinthOfLore/Entity/ThingDictionary.hpp>



namespace LabyrinthOfLore
{
namespace Entity
{


ThingDictionary::ThingDictionary(std::map<int, LabyrinthOfLore::Entity::ThingDefinition> definitions)
   : definitions(definitions)
{
}


ThingDictionary::~ThingDictionary()
{
}


LabyrinthOfLore::Entity::ThingDefinition ThingDictionary::find_definition(int tile_type)
{
if (definitions.find(tile_type) == definitions.end()) return LabyrinthOfLore::Entity::ThingDefinition();
return definitions[tile_type];

}
} // namespace Entity
} // namespace LabyrinthOfLore


