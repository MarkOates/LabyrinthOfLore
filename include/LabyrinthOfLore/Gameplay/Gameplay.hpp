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
      public:
         void run();
      };
   } // namespace Gameplay
} // namespace LabyrinthOfLore



