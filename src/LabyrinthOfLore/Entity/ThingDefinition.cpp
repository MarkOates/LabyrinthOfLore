

#include <LabyrinthOfLore/Entity/ThingDefinition.hpp>

#include <sstream>


namespace LabyrinthOfLore
{
namespace Entity
{


ThingDefinition::ThingDefinition(thing_type_t type, std::string article, std::string name, Tileo::TileAtlas* tile_atlas, int tile_atlas_index_id, int weight, int health, std::string mood, std::string condition)
   : type(type)
   , article(article)
   , name(name)
   , tile_atlas(tile_atlas)
   , tile_atlas_index_id(tile_atlas_index_id)
   , weight(weight)
   , health(health)
   , mood(mood)
   , condition(condition)
{
}


ThingDefinition::~ThingDefinition()
{
}


void ThingDefinition::set_health(int health)
{
   this->health = health;
}


void ThingDefinition::set_mood(std::string mood)
{
   this->mood = mood;
}


void ThingDefinition::set_condition(std::string condition)
{
   this->condition = condition;
}


thing_type_t ThingDefinition::get_type() const
{
   return type;
}


std::string ThingDefinition::get_article() const
{
   return article;
}


std::string ThingDefinition::get_name() const
{
   return name;
}


Tileo::TileAtlas* ThingDefinition::get_tile_atlas() const
{
   return tile_atlas;
}


int ThingDefinition::get_tile_atlas_index_id() const
{
   return tile_atlas_index_id;
}


int ThingDefinition::get_weight() const
{
   return weight;
}


int ThingDefinition::get_health() const
{
   return health;
}


std::string ThingDefinition::get_mood() const
{
   return mood;
}


std::string ThingDefinition::get_condition() const
{
   return condition;
}


bool ThingDefinition::infer_is_dead()
{
   return (health <= 0);
}

std::string ThingDefinition::infer_short_decorated_name()
{
   std::stringstream result;
   if (!article.empty()) result << article << " ";
   if (!name.empty()) result << name << " ";

   std::string result_str = result.str();
   if (result_str.size() > 0 && result_str[result_str.size()-1] == ' ') result_str.pop_back();

   return result_str;
}

std::string ThingDefinition::infer_decorated_name()
{
   std::stringstream result;
   if (!article.empty()) result << article << " ";
   if (!mood.empty()) result << mood << " ";
   if (!condition.empty()) result << condition << " ";
   if (!name.empty()) result << name << " ";

   std::string result_str = result.str();
   if (result_str.size() > 0 && result_str[result_str.size()-1] == ' ') result_str.pop_back();

   return result_str;
}


} // namespace Entity
} // namespace LabyrinthOfLore


