

#include <LabyrinthOfLore/Entity/Selector.hpp>



namespace LabyrinthOfLore
{
namespace Entity
{


Selector::Selector(std::vector<LabyrinthOfLore::Entity::Base*> all_entities)
   : all_entities(all_entities)
{
}


Selector::~Selector()
{
}


std::vector<LabyrinthOfLore::Entity::Base*> Selector::select_within_level(std::string level_identifier)
{
   std::vector<LabyrinthOfLore::Entity::Base*> result;

   for (auto &entity : all_entities)
   {
      if (entity->get_identifier_for_level_within() == level_identifier) result.push_back(entity);
   }

   return result;
}
} // namespace Entity
} // namespace LabyrinthOfLore


