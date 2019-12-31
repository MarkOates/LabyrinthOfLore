

#include <LabyrinthOfLore/Hud/CommandPanel.hpp>



namespace LabyrinthOfLore
{
namespace Hud
{


CommandPanel::CommandPanel()
   : mode(COMMAND_MODE_NONE)
{
}


CommandPanel::~CommandPanel()
{
}


LabyrinthOfLore::Hud::command_mode_t CommandPanel::get_mode()
{
   return mode;
}


std::string CommandPanel::run()
{
return "Hello World!";
}
} // namespace Hud
} // namespace LabyrinthOfLore


