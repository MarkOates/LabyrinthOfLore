

#include <LabyrinthOfLore/Entity/ThingDefinition.hpp>



namespace LabyrinthOfLore
{
namespace Entity
{


ThingDefinition::ThingDefinition()
   : article("an")
   , name("unnamed thing")
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


std::string ThingDefinition::decorated_name()
{
return article + " " + name;

}
} // namespace Entity
} // namespace LabyrinthOfLore


