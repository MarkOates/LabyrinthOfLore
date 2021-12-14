

#include <LabyrinthOfLore/Entity/Cleanup.hpp>



namespace LabyrinthOfLore
{
namespace Entity
{


std::string Cleanup::CLEANUP_FLAG = "destroy_this_item_at_cleanup";


Cleanup::Cleanup(std::vector<LabyrinthOfLore::Entity::Base*>* all_entities)
   : all_entities(all_entities)
{
}


Cleanup::~Cleanup()
{
}


std::string Cleanup::get_CLEANUP_FLAG()
{
   return CLEANUP_FLAG;
}


int Cleanup::cleanup()
{
   if (!all_entities) throw std::runtime_error("Cannot cleanup in Entity/Cleanup with a nullptr all_entities");

   int entities_destroyed = 0;
   for (int i=0; i<all_entities->size(); i++)
   {
       if (all_entities->at(i)->exists(CLEANUP_FLAG))
       {
          delete all_entities->at(i);
          all_entities->erase(all_entities->begin() + i);
          i--;
          entities_destroyed++;
       }
   }

   return entities_destroyed;
}
} // namespace Entity
} // namespace LabyrinthOfLore


