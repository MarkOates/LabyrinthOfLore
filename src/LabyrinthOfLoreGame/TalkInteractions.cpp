

#include <LabyrinthOfLoreGame/TalkInteractions.hpp>



namespace LabyrinthOfLoreGame
{


TalkInteractions::TalkInteractions()
   : all_entities(nullptr)
   , entity(nullptr)
   , thing_dictionary(nullptr)
   , message_scroll(nullptr)
   , character_panel(nullptr)
   , player_inventory(nullptr)
{
}


TalkInteractions::~TalkInteractions()
{
}


std::string TalkInteractions::run()
{
return "Hello World!";
}
} // namespace LabyrinthOfLoreGame


