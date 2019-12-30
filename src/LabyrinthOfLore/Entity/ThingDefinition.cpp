

#include <LabyrinthOfLore/Entity/ThingDefinition.hpp>
#include <sstream>


namespace LabyrinthOfLore
{
namespace Entity
{


ThingDefinition::ThingDefinition(std::string article, std::string name)
   : article(article)
   , name(name)
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


