
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Entity/Selector.hpp>

TEST(LabyrinthOfLore_Entity_SelectorTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Entity::Selector selector;
}

TEST(LabyrinthOfLore_Entity_SelectorTest, select_within_level__can_be_called_wihtout_blowing_up)
{
   LabyrinthOfLore::Entity::Selector selector;
   selector.select_within_level();
   SUCCEED();
}

//TEST(LabyrinthOfLore_Entity_SelectorTest, select_within_level__returns_entities_that_only_exist_in_a_level)
//{
   //LabyrinthOfLore::Entity::Selector selector;
   //selector.select_all_within_level();
      //SUCCEED();
//}

