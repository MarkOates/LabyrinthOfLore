

#include <LabyrinthOfLore/Entity/ThingDefinition.hpp>
#include <sstream>


namespace LabyrinthOfLore
{
namespace Entity
{


ThingDefinition::ThingDefinition(std::string article, std::string name, Tileo::TileAtlas* tile_atlas, int tile_atlas_index_id, int weight, int health, std::string mood)
   : article(article)
   , name(name)
   , tile_atlas(tile_atlas)
   , tile_atlas_index_id(tile_atlas_index_id)
   , weight(weight)
   , health(health)
   , mood(mood)
{
}


ThingDefinition::~ThingDefinition()
{
}


std::string ThingDefinition::get_article()
{
   return article;
}


std::string ThingDefinition::get_name()
{
   return name;
}


Tileo::TileAtlas* ThingDefinition::get_tile_atlas()
{
   return tile_atlas;
}


int ThingDefinition::get_tile_atlas_index_id()
{
   return tile_atlas_index_id;
}


int ThingDefinition::get_weight()
{
   return weight;
}


int ThingDefinition::get_health()
{
   return health;
}


std::string ThingDefinition::get_mood()
{
   return mood;
}


std::string ThingDefinition::infer_decorated_name()
{
std::stringstream result;
if (!article.empty()) result << article << " ";
if (!name.empty()) result << name << " ";

std::string result_str = result.str();
if (result_str.size() > 0 && result_str[result_str.size()-1] == ' ') result_str.pop_back();

return result_str;

}
} // namespace Entity
} // namespace LabyrinthOfLore


