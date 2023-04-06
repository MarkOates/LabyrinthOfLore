#define ALLEGRO_UNSTABLE


#include <allegro5/allegro.h>


#include <LabyrinthOfLore/Entity/Base.hpp>
#include <LabyrinthOfLore/Entity/Selector.hpp>
#include <LabyrinthOfLore/WorldMap/Tile.hpp>
#include <LabyrinthOfLore/WorldMap/TileMapLoader.hpp>
#include <LabyrinthOfLore/WorldMap/Level.hpp>
#include <LabyrinthOfLore/WorldMap/Door.hpp>
#include <LabyrinthOfLore/Rendering/SceneRenderer.hpp>
#include <LabyrinthOfLore/Rendering/TileMapMesh.hpp>
#include <LabyrinthOfLore/Rendering/TileMapWaterMesh.hpp>
#include <LabyrinthOfLore/Physics/GravityStepper.hpp>
#include <LabyrinthOfLore/Physics/EntityTileMapCollisionStepper.hpp>
#include <LabyrinthOfLore/Rendering/PickingBufferRenderer.hpp>
#include <LabyrinthOfLore/Rendering/MousePointer.hpp>
#include <LabyrinthOfLore/Rendering/SpritesBillboarder.hpp>
#include <LabyrinthOfLore/Rendering/TileTypeDefinition.hpp>
#include <LabyrinthOfLore/Rendering/TileTypeDictionary.hpp>
#include <LabyrinthOfLore/Rendering/Hud/Renderer.hpp>
//#include <LabyrinthOfLore/Rendering/Hud/MessageScrollRenderer.hpp>
//#include <LabyrinthOfLore/Rendering/Hud/CommandPanelRenderer.hpp>
#include <LabyrinthOfLore/Hud/MessageScroll.hpp>
#include <LabyrinthOfLore/Hud/CommandPanel.hpp>
#include <LabyrinthOfLore/Hud/VitalityAndManaBar.hpp>
#include <LabyrinthOfLore/Hud/CharacterPanel.hpp>
#include <LabyrinthOfLore/Hud/MapButton.hpp>
#include <LabyrinthOfLore/Hud/RuneShelf.hpp>
#include <LabyrinthOfLore/Hud/Compass.hpp>
#include <LabyrinthOfLore/Hud/RotateCharacterPanelButton.hpp>
#include <LabyrinthOfLore/Hud/CommandsHintPane.hpp>
#include <LabyrinthOfLore/Hud/CurrentSpells.hpp>
#include <LabyrinthOfLore/Hud/ViewFrame.hpp>
#include <LabyrinthOfLore/Hud/TitleText.hpp>
#include <Tileo/TileIndexInfo.hpp>
#include <Tileo/TileAtlas.hpp>
#include <AllegroFlare/FontBin.hpp>
#include <AllegroFlare/BitmapBin.hpp>
#include <AllegroFlare/PickingBuffer.hpp>
#include <AllegroFlare/Random.hpp>
#include <allegro_flare/placement2d.h>
#include <AllegroFlare/Useful.hpp>
#include <allegro5/allegro_ttf.h>
#include <cmath>
#include <LabyrinthOfLore/WorldMap/MultiBitmapFilenameToWorldBuilder.hpp>
#include <LabyrinthOfLore/WorldMap/BitmapFilenameToWorldBuilder.hpp>
#include <LabyrinthOfLore/Entity/ThingDefinition.hpp>
#include <LabyrinthOfLore/Entity/ThingDictionary.hpp>
#include <LabyrinthOfLore/Hud/CommandPanelModeEnum.hpp>
#include <LabyrinthOfLore/WorldMap/TileTypeEnum.hpp>
#include <LabyrinthOfLore/Entity/Cleanup.hpp>
//#include <algorithm> // for std::max
#include <LabyrinthOfLoreGame/ThingDefinitionFactory.hpp>
#include <LabyrinthOfLoreGame/Interactions.hpp>
#include <LabyrinthOfLoreGame/Classic.hpp>
#include <LabyrinthOfLoreGame/LevelIdentifiers.hpp>
#include <AllegroFlare/Inventory.hpp>


namespace LabyrinthOfLore
{
   namespace Gameplay
   {
      class Gameplay
      {
      private:
         AllegroFlare::BitmapBin *bitmap_bin;
         AllegroFlare::FontBin *font_bin;
         LabyrinthOfLoreGame::ThingDefinitionFactory thing_definition_factory; // yet to be used
         AllegroFlare::Inventory player_inventory;
         LabyrinthOfLore::Hud::MessageScroll message_scroll;
         LabyrinthOfLore::Hud::CommandPanel command_panel;
         LabyrinthOfLore::Hud::VitalityAndManaBar vitality_and_mana_bar;
         LabyrinthOfLore::Hud::CharacterPanel character_panel;
         LabyrinthOfLore::Hud::MapButton map_button;
         LabyrinthOfLore::Hud::RuneShelf rune_shelf;
         LabyrinthOfLore::Hud::Compass compass;
         LabyrinthOfLore::Hud::RotateCharacterPanelButton rotate_character_panel_button;
         LabyrinthOfLore::Hud::CommandsHintPane commands_hint_pane;
         LabyrinthOfLore::Hud::CurrentSpells current_spells;
         LabyrinthOfLore::Hud::ViewFrame veiw_frame;
         LabyrinthOfLore::Hud::TitleText title_text;
         LabyrinthOfLore::WorldMap::TileMap current_tile_map;
         LabyrinthOfLore::Rendering::TileMapMesh current_tile_map_mesh;
         LabyrinthOfLore::Rendering::TileMapWaterMesh current_tile_map_water_mesh;
         LabyrinthOfLoreGame::Classic classic_game; // This may become LabyrinthOfLore::Games::Base*
         LabyrinthOfLore::Rendering::Camera camera;
         ALLEGRO_BITMAP *buffer_buffer;
         ALLEGRO_BITMAP *scene_rendering_surface;
         LabyrinthOfLore::Entity::Base* player_entity;
         float player_yaw;
         float player_camera_ascent;
         float player_pitch;
         float player_turning;
         float max_player_turning_speed;
         float player_movement_magnitude;
         int player_mouse_x;
         int player_mouse_y;
         bool initialized;

      public:
         Gameplay();

         void set_bitmap_bin(AllegroFlare::BitmapBin *bitmap_bin);
         void set_font_bin(AllegroFlare::FontBin *font_bin);
         
         void initialize(ALLEGRO_DISPLAY* _display);
         void start_game();
         void run();

         void process_mouse_axes_event(ALLEGRO_EVENT &this_event);
         void process_mouse_button_down_event(ALLEGRO_EVENT &this_event);
         void process_key_char_event(ALLEGRO_EVENT &this_event, bool &shutdown_program_flag);
         void process_key_up_event(ALLEGRO_EVENT &this_event);
         void process_timer_event(ALLEGRO_EVENT &this_event, ALLEGRO_DISPLAY* _display);
      };
   } // namespace Gameplay
} // namespace LabyrinthOfLore



