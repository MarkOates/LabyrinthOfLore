#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <LabyrinthOfLore/Hud/CharacterPanel.hpp>
#include <LabyrinthOfLore/Hud/CommandPanel.hpp>
#include <LabyrinthOfLore/Hud/CommandsHintPane.hpp>
#include <LabyrinthOfLore/Hud/Compass.hpp>
#include <LabyrinthOfLore/Hud/CurrentSpells.hpp>
#include <LabyrinthOfLore/Hud/MapButton.hpp>
#include <LabyrinthOfLore/Hud/MessageScroll.hpp>
#include <LabyrinthOfLore/Hud/RotateCharacterPanelButton.hpp>
#include <LabyrinthOfLore/Hud/RuneShelf.hpp>
#include <LabyrinthOfLore/Hud/TitleText.hpp>
#include <LabyrinthOfLore/Hud/ViewFrame.hpp>
#include <LabyrinthOfLore/Hud/VitalityAndManaBar.hpp>
#include <LabyrinthOfLore/Rendering/MousePointer.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      namespace Hud
      {
         class Renderer
         {
         private:
            ALLEGRO_BITMAP* render_surface;
            AllegroFlare::FontBin* font_bin;
            LabyrinthOfLore::Hud::MessageScroll* message_scroll;
            LabyrinthOfLore::Hud::CommandPanel* command_panel;
            LabyrinthOfLore::Hud::VitalityAndManaBar* vitality_and_mana_bar;
            LabyrinthOfLore::Hud::CharacterPanel* character_panel;
            LabyrinthOfLore::Hud::MapButton* map_button;
            LabyrinthOfLore::Hud::RuneShelf* rune_shelf;
            LabyrinthOfLore::Hud::Compass* compass;
            LabyrinthOfLore::Hud::RotateCharacterPanelButton* rotate_character_panel_button;
            LabyrinthOfLore::Hud::CommandsHintPane* commands_hint_pane;
            LabyrinthOfLore::Hud::CurrentSpells* current_spells;
            LabyrinthOfLore::Hud::ViewFrame* view_frame;
            LabyrinthOfLore::Hud::TitleText* title_text;
            LabyrinthOfLore::Rendering::MousePointer* mouse_pointer;

         public:
            Renderer(ALLEGRO_BITMAP* render_surface=nullptr, AllegroFlare::FontBin* font_bin=nullptr, LabyrinthOfLore::Hud::MessageScroll* message_scroll=nullptr, LabyrinthOfLore::Hud::CommandPanel* command_panel=nullptr, LabyrinthOfLore::Hud::VitalityAndManaBar* vitality_and_mana_bar=nullptr, LabyrinthOfLore::Hud::CharacterPanel* character_panel=nullptr, LabyrinthOfLore::Hud::MapButton* map_button=nullptr, LabyrinthOfLore::Hud::RuneShelf* rune_shelf=nullptr, LabyrinthOfLore::Hud::Compass* compass=nullptr, LabyrinthOfLore::Hud::RotateCharacterPanelButton* rotate_character_panel_button=nullptr, LabyrinthOfLore::Hud::CommandsHintPane* commands_hint_pane=nullptr, LabyrinthOfLore::Hud::CurrentSpells* current_spells=nullptr, LabyrinthOfLore::Hud::ViewFrame* view_frame=nullptr, LabyrinthOfLore::Hud::TitleText* title_text=nullptr, LabyrinthOfLore::Rendering::MousePointer* mouse_pointer=nullptr);
            ~Renderer();


         ALLEGRO_FONT* get_basic_lettering_font();
         void render_message_scroll();
         void render_command_panel();
         void render_vitality_and_mana_bar();
         void render_character_panel();
         void render_map_button();
         void render_rune_shelf();
         void render_compass();
         void render_rotate_character_panel_button();
         void render_commands_hint_pane();
         void render_current_spells();
         void render_view_frame();
         void render_title_text();
         void render();
         };
      }
   }
}



