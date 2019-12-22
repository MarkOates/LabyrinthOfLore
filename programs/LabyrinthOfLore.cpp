#define ALLEGRO_UNSTABLE


#include <allegro5/allegro.h>


#include <LabyrinthOfLore/Entity/Base.hpp>
#include <LabyrinthOfLore/WorldMap/Tile.hpp>
#include <LabyrinthOfLore/WorldMap/TileMapLoader.hpp>
#include <LabyrinthOfLore/Rendering/SceneRenderer.hpp>
#include <LabyrinthOfLore/Rendering/TileMapMesh.hpp>
#include <LabyrinthOfLore/Physics/GravityStepper.hpp>
#include <LabyrinthOfLore/Physics/EntityTileMapCollisionStepper.hpp>
#include <LabyrinthOfLore/Rendering/PickingBufferRenderer.hpp>
#include <LabyrinthOfLore/Rendering/MousePointer.hpp>
#include <LabyrinthOfLore/Rendering/SpritesBillboarder.hpp>
#include <LabyrinthOfLore/Rendering/Hud/Renderer.hpp>
//#include <LabyrinthOfLore/Rendering/Hud/MessageScrollRenderer.hpp>
//#include <LabyrinthOfLore/Rendering/Hud/CommandPanelRenderer.hpp>
#include <LabyrinthOfLore/Hud/MessageScroll.hpp>
#include <LabyrinthOfLore/Hud/CommandPanel.hpp>
#include <AllegroFlare/FontBin.hpp>
#include <AllegroFlare/BitmapBin.hpp>
#include <AllegroFlare/PickingBuffer.hpp>
#include <AllegroFlare/Random.hpp>
#include <allegro_flare/placement2d.h>
#include <AllegroFlare/Useful.hpp>
#include <cmath>

using AllegroFlare::radians_to_degrees;
using AllegroFlare::Random;


std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> construct_tile_map_data = {
   { { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+0.25 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+0.50 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+0.75 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+1.0 }, { 0, 1.0+5.0 }, { 0, 5.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+1.25 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+1.50 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+1.75 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+2.0 }, { 0, 1.0+5.0 }, { 0, 5.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+2.25 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+2.50 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+2.75 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+3.0 }, { 0, 1.0+5.0 }, { 0, 5.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+3.25 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+3.50 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+3.75 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0+4.0 }, { 0, 1.0+5.0 }, { 0, 5.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 5.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 6.0 }, { 0, 1.0 }, { 0, 6.0 }, { 0, 6.0 }, { 2, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 },  { 0, 1.0 },     { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 0, 1.0 }, { 1, 10.0 }, },
   { { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, { 1, 10.0 }, },
};


bool active = true;

int main(int argc, char **argv)
{
   if (active)
   {
      al_init();
      al_init_font_addon();
      al_init_image_addon();
      al_init_primitives_addon();

      ALLEGRO_PATH *resource_path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
      al_change_directory(al_path_cstr(resource_path, ALLEGRO_NATIVE_PATH_SEP));
      al_destroy_path(resource_path);

      // set a few options and flags
      al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 2, ALLEGRO_SUGGEST);
      al_set_new_display_option(ALLEGRO_DEPTH_SIZE, 32, ALLEGRO_SUGGEST);
      al_set_new_display_option(ALLEGRO_SAMPLES, 16, ALLEGRO_SUGGEST);
      al_set_new_display_flags(ALLEGRO_RESIZABLE | ALLEGRO_OPENGL | ALLEGRO_PROGRAMMABLE_PIPELINE);


      float resolution_scale = 1;


      ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);


      std::vector<LabyrinthOfLore::Entity::Base*> entities = {};
      LabyrinthOfLore::Rendering::Camera camera({0, 0, 0}, 0.0, 0.0);

      //

      LabyrinthOfLore::WorldMap::TileMap tile_map = LabyrinthOfLore::WorldMap::TileMapLoader(construct_tile_map_data).build_tile_map();

      //

      ALLEGRO_BITMAP *tile_mesh_texture = al_load_bitmap("data/bitmaps/wall-tile-01-3x.png");
      if (!tile_mesh_texture) throw std::runtime_error("could not load tile_mesh_texture");

      ALLEGRO_BITMAP *billboarding_tester_sprite = al_load_bitmap("data/bitmaps/billboarding_tester_sprite.png");
      if (!billboarding_tester_sprite) throw std::runtime_error("could not load billboarding_tester_sprite.png");

      //

      LabyrinthOfLore::Entity::Base* camera_entity = new LabyrinthOfLore::Entity::Base;
      camera_entity->get_placement_ref().position = AllegroFlare::vec3d(1.5, 1.5, 1.01);

      entities.push_back(camera_entity);


      Random random;

      for (int y=1; y<3; y++)
      {
         for (int x=1; x<3; x++)
         {
            LabyrinthOfLore::Entity::Base* entity = new LabyrinthOfLore::Entity::Base;
            entity->set_billboard_at_camera(true);
            entity->set_bitmap(billboarding_tester_sprite);
            entity->get_placement_ref().size = AllegroFlare::vec3d(al_get_bitmap_width(billboarding_tester_sprite), al_get_bitmap_height(billboarding_tester_sprite), 0.0);
            entity->get_placement_ref().scale = AllegroFlare::vec3d(0.005, 0.005, 0.005);
            entity->get_placement_ref().align = AllegroFlare::vec3d(0.5, 1.0, 0.0);
            entity->get_placement_ref().position = AllegroFlare::vec3d(x + 0.5, y + 0.5, 1.01);
            entity->get_placement_ref().rotation = AllegroFlare::vec3d(0, random.get_random_float(-1, 1), 0);
            //entity->get_placement_ref().rotation = AllegroFlare::vec3d(random.get_random_float(-1, 1), random.get_random_float(-1, 1), random.get_random_float(-1, 1));

            entities.push_back(entity);

            std::cout << "entity made " << std::endl;
         }
      }


      //

      AllegroFlare::FontBin font_bin;
      font_bin.set_path("data/fonts");
      font_bin.operator[]("gameovercre1.ttf -12");

      AllegroFlare::BitmapBin bitmap_bin;
      bitmap_bin.set_path("data/bitmaps");

      //

      LabyrinthOfLore::Rendering::TileMapMesh tile_map_mesh(tile_map, tile_mesh_texture);
      tile_map_mesh.build();

      AllegroFlare::PickingBuffer picking_buffer(al_get_display_width(display)/resolution_scale, al_get_display_height(display)/resolution_scale, 32);
      picking_buffer.initialize();

      LabyrinthOfLore::Shader::ClampedColor clamped_color_shader;
      clamped_color_shader.initialize();

      LabyrinthOfLore::Shader::DepthDarken depth_darken_shader;
      depth_darken_shader.initialize();


      //

      int previous_depth = al_get_new_bitmap_depth();
      int previous_samples = al_get_new_bitmap_samples();
      ALLEGRO_STATE previous_state;
      al_store_state(&previous_state, ALLEGRO_STATE_BITMAP);

      al_set_new_bitmap_depth(32);
      al_set_new_bitmap_samples(0);
      //ALLEGRO_BITMAP *bmp = al_create_bitmap(w, h);

      ALLEGRO_BITMAP *buffer_buffer = al_create_bitmap(al_get_display_width(display)/resolution_scale, al_get_display_height(display)/resolution_scale);
      //ALLEGRO_BITMAP *buffer_buffer = al_get_backbuffer(display);

      al_restore_state(&previous_state);
      al_set_new_bitmap_depth(previous_depth);
      al_set_new_bitmap_samples(previous_samples);


      ALLEGRO_BITMAP *scene_rendering_surface = al_create_sub_bitmap(buffer_buffer, 0, 0, al_get_bitmap_width(buffer_buffer), al_get_bitmap_height(buffer_buffer));
      if (!scene_rendering_surface) throw std::runtime_error("could not create scene_rendering_surface");

      ALLEGRO_BITMAP *hud_rendering_surface = al_create_sub_bitmap(buffer_buffer, 0, 0, al_get_bitmap_width(buffer_buffer), al_get_bitmap_height(buffer_buffer));
      if (!hud_rendering_surface) throw std::runtime_error("could not create hud_rendering_surface");


      //

      bool shutdown_program = false;

      ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

      al_install_keyboard();
      al_register_event_source(event_queue, al_get_keyboard_event_source());

      al_install_mouse();
      al_register_event_source(event_queue, al_get_mouse_event_source());

      ALLEGRO_TIMER *primary_timer = al_create_timer(1.0/60.0);
      al_register_event_source(event_queue, al_get_timer_event_source(primary_timer));
      al_start_timer(primary_timer);

      //

      float player_yaw = 0.5;
      float player_pitch = 0.0;
      float player_turning = 0.0;
      float max_player_turning_speed = 0.0023;
      float player_movement_magnitude = 0.0;

      int player_mouse_x = 0;
      int player_mouse_y = 0;

      camera_entity->get_velocity_ref().position = {0.0, 0.0, 0};
      camera_entity->get_placement_ref().position = {2.5, 2.5, 0.0};
      //camera_entity->get_placement_ref().rotation = {2.5, 2.5, 0.0};

      //

      LabyrinthOfLore::Hud::MessageScroll message_scroll;
      LabyrinthOfLore::Hud::CommandPanel command_panel;

      //

      while(!shutdown_program)
      {
         ALLEGRO_EVENT this_event, next_event;
         al_wait_for_event(event_queue, &this_event);

         switch(this_event.type)
         {
         case ALLEGRO_EVENT_DISPLAY_CLOSE:
            shutdown_program = true;
            break;
         case ALLEGRO_EVENT_MOUSE_AXES:
            player_mouse_x = this_event.mouse.x;
            player_mouse_y = this_event.mouse.y;
            break;
         case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            {
               player_mouse_x = this_event.mouse.x;
               player_mouse_y = this_event.mouse.y;
               int picked_id = picking_buffer.get_id(player_mouse_x/resolution_scale, player_mouse_y/resolution_scale);
               std::cout << "Picked ID: " << picked_id << std::endl;
               break;
            }
         case ALLEGRO_EVENT_KEY_DOWN:
            if (this_event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) shutdown_program = true;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_A) player_turning = -max_player_turning_speed;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_W) player_movement_magnitude = 0.022;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_D) player_turning = max_player_turning_speed;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_S) player_movement_magnitude = -0.022;
            break;
         case ALLEGRO_EVENT_KEY_UP:
            if (this_event.keyboard.keycode == ALLEGRO_KEY_A) player_turning = 0.0;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_W) player_movement_magnitude = 0.0;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_D) player_turning = 0.0;
            if (this_event.keyboard.keycode == ALLEGRO_KEY_S) player_movement_magnitude = 0.0;
            break;
         case ALLEGRO_EVENT_TIMER:
            {
               player_yaw += player_turning;

               AllegroFlare::vec2d view_vector_2d = AllegroFlare::vec2d::polar_coords((player_yaw + 0.25) * ALLEGRO_PI*2, player_movement_magnitude);
               camera_entity->get_velocity_ref().position.x = view_vector_2d.x; //view_vector_2d.x;
               camera_entity->get_velocity_ref().position.y = view_vector_2d.y; //view_vector_2d.y;

               LabyrinthOfLore::Physics::GravityStepper gravity_stepper(entities);
               gravity_stepper.process_step();

               LabyrinthOfLore::Physics::EntityTileMapCollisionStepper entity_tile_map_collision_stepper(tile_map, entities);
               entity_tile_map_collision_stepper.process_step();

               camera.get_position_ref() = camera_entity->get_placement_ref().position + AllegroFlare::vec3d(0, 0, 0.65);//{5, 20, 2.01 + 0.5};
               camera.get_yaw_ref() = player_yaw + 0.5;// + sin(al_get_time()) * 0.02;
               camera.get_pitch_ref() = player_pitch - 0.02;;// + sin((al_get_time()+2.345)*0.8534) * 0.02;

               //

               LabyrinthOfLore::Rendering::SpritesBillboarder sprites_billboarder(camera, entities);
               sprites_billboarder.process();

               //

               LabyrinthOfLore::Rendering::SceneRenderer scene_renderer(scene_rendering_surface, &camera, tile_map_mesh, entities, &depth_darken_shader);
               scene_renderer.render();

               //

               al_clear_depth_buffer(1);
               al_set_render_state(ALLEGRO_DEPTH_TEST, 1);
               LabyrinthOfLore::Rendering::PickingBufferRenderer picking_buffer_renderer(&picking_buffer, &camera, tile_map_mesh, entities, &clamped_color_shader);
               picking_buffer_renderer.render();

               //

               al_set_target_bitmap(al_get_backbuffer(display));
               al_set_render_state(ALLEGRO_DEPTH_TEST, 0);
               al_draw_scaled_bitmap(buffer_buffer, 0, 0, al_get_bitmap_width(buffer_buffer), al_get_bitmap_height(buffer_buffer), 0, 0, al_get_display_width(display), al_get_display_height(display), 0);
               //al_draw_scaled_bitmap(picking_buffer.get_surface_render(), 0, 0, al_get_bitmap_width(buffer_buffer), al_get_bitmap_height(buffer_buffer), 0, 0, al_get_display_width(display), al_get_display_height(display), 0);

               //

               LabyrinthOfLore::Rendering::MousePointer mouse_pointer(player_mouse_x, player_mouse_y);
               LabyrinthOfLore::Rendering::Hud::Renderer hud_renderer(al_get_backbuffer(display), &font_bin, &message_scroll, &command_panel, &mouse_pointer);
               hud_renderer.render();

               al_flip_display();
            }
            while (al_peek_next_event(event_queue, &next_event)
                  && next_event.type == ALLEGRO_EVENT_TIMER
                  && next_event.timer.source == this_event.timer.source)
               al_drop_next_event(event_queue);
         }
      }

      al_save_bitmap("tmp/buffer_buffer.png", buffer_buffer);
      //al_save_bitmap("tmp/scene.png", scene_rendering_surface);
      //al_save_bitmap("tmp/picking.png", picking_buffer.get_surface_render());
   }

   return 0;
}


