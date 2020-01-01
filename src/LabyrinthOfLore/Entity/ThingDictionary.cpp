

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


std::map<int, LabyrinthOfLore::Entity::ThingDefinition> &ThingDictionary::get_definitions_ref()
{
   return definitions;
}


int ThingDictionary::size()
{
return definitions.size();
}

int ThingDictionary::create_new_definition(LabyrinthOfLore::Entity::ThingDefinition thing)
{
if (definitions.empty()) return 1;
int largest_thing_id = definitions.rbegin()->first;
int new_thing_id = largest_thing_id++;
definitions[new_thing_id] = thing;
return new_thing_id;

}

LabyrinthOfLore::Entity::ThingDefinition ThingDictionary::find_definition(int tile_type)
{
if (definitions.find(tile_type) == definitions.end()) return LabyrinthOfLore::Entity::ThingDefinition();
return definitions[tile_type];

}

LabyrinthOfLore::Entity::ThingDefinition& ThingDictionary::find_definition_ref(int tile_type)
{
if (definitions.find(tile_type) == definitions.end()) throw std::runtime_error("cannot find_definition_ref in the ThingDictionary. It doesn't exist.");
return definitions[tile_type];

}
} // namespace Entity
} // namespace LabyrinthOfLore


