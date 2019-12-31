
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <LabyrinthOfLore/Entity/Cleanup.hpp>

TEST(LabyrinthOfLore_Entity_CleanupTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Entity::Cleanup cleanup;
}

TEST(LabyrinthOfLore_Entity_CleanupTest, cleanup__removes_the_entities_from_the_list_of_entities_without_blowing_up)
{
   LabyrinthOfLore::Entity::Cleanup cleanup;
   std::string expected_error_message = "Cannot cleanup in Entity/Cleanup with a nullptr all_entities";
   ASSERT_THROW_WITH_MESSAGE(cleanup.cleanup(), std::runtime_error, expected_error_message);
}

TEST(LabyrinthOfLore_Entity_CleanupTest, cleanup__with_valid_arguments__can_be_executed_without_blowing_up)
{
   std::vector<LabyrinthOfLore::Entity::Base*> all_entities;

   LabyrinthOfLore::Entity::Cleanup cleanup(&all_entities);
   ASSERT_EQ(0, cleanup.cleanup());
}

TEST(LabyrinthOfLore_Entity_CleanupTest, cleanup__with_valid_arguments__removes_the_entities_from_the_list_of_entities_without_blowing_up)
{
   std::vector<LabyrinthOfLore::Entity::Base*> all_entities;

   all_entities.push_back(new LabyrinthOfLore::Entity::Base);
   all_entities.push_back(new LabyrinthOfLore::Entity::Base);
   all_entities.push_back(new LabyrinthOfLore::Entity::Base);
   all_entities.push_back(new LabyrinthOfLore::Entity::Base);
   all_entities.push_back(new LabyrinthOfLore::Entity::Base);

   all_entities[1]->set(LabyrinthOfLore::Entity::Cleanup::get_CLEANUP_FLAG());
   all_entities[3]->set(LabyrinthOfLore::Entity::Cleanup::get_CLEANUP_FLAG());
   all_entities[4]->set(LabyrinthOfLore::Entity::Cleanup::get_CLEANUP_FLAG());

   std::vector<LabyrinthOfLore::Entity::Base*> expected_result_entities = {
      all_entities[0],
      all_entities[2],
   };

   LabyrinthOfLore::Entity::Cleanup cleanup(&all_entities);
   ASSERT_EQ(3, cleanup.cleanup());

   ASSERT_EQ(2, all_entities.size());
   ASSERT_EQ(expected_result_entities, all_entities);
}

