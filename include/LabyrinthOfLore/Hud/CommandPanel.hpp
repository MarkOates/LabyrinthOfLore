#pragma once


#include <LabyrinthOfLore/Hud/CommandPanelModeEnum.hpp>
#include <string>


namespace LabyrinthOfLore
{
   namespace Hud
   {
      class CommandPanel
      {
      private:
         LabyrinthOfLore::Hud::command_mode_t current_mode;

      public:
         CommandPanel();
         ~CommandPanel();

         void set_current_mode(LabyrinthOfLore::Hud::command_mode_t current_mode);

         LabyrinthOfLore::Hud::command_mode_t get_current_mode();
      std::string run();
      };
   }
}



