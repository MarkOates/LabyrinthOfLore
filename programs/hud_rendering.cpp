#define ALLEGRO_UNSTABLE


#include <allegro5/allegro.h>


#include <LabyrinthOfLore/Rendering/Hud/Renderer.hpp>
#include <LabyrinthOfLore/Rendering/Hud/MessageScrollRenderer.hpp>
#include <LabyrinthOfLore/Hud/MessageScroll.hpp>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_color.h>
#include <AllegroFlare/FontBin.hpp>
#include <AllegroFlare/BitmapBin.hpp>

bool active = true;

int main(int argc, char **argv)
{
   if (active)
   {
      al_init();
      al_init_font_addon();
      al_init_ttf_addon();
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


      //

      AllegroFlare::FontBin font_bin;
      font_bin.set_path("data/fonts");
      font_bin.operator[]("gameovercre1.ttf -12");

      AllegroFlare::BitmapBin bitmap_bin;
      bitmap_bin.set_path("data/bitmaps");

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

      int player_mouse_x = 0;
      int player_mouse_y = 0;

      //

      LabyrinthOfLore::Hud::MessageScroll message_scroll;

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
            break;
         case ALLEGRO_EVENT_KEY_DOWN:
            if (this_event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) shutdown_program = true;
            break;
         case ALLEGRO_EVENT_KEY_UP:
            break;
         case ALLEGRO_EVENT_TIMER:
            {
               //

               al_clear_depth_buffer(1);
               al_clear_to_color(al_color_name("black"));
               al_set_render_state(ALLEGRO_DEPTH_TEST, 1);

               //

               al_set_target_bitmap(al_get_backbuffer(display));
               al_set_render_state(ALLEGRO_DEPTH_TEST, 0);
               al_draw_scaled_bitmap(buffer_buffer, 0, 0, al_get_bitmap_width(buffer_buffer), al_get_bitmap_height(buffer_buffer), 0, 0, al_get_display_width(display), al_get_display_height(display), 0);
               //al_draw_scaled_bitmap(picking_buffer.get_surface_render(), 0, 0, al_get_bitmap_width(buffer_buffer), al_get_bitmap_height(buffer_buffer), 0, 0, al_get_display_width(display), al_get_display_height(display), 0);

               //

               LabyrinthOfLore::Rendering::MousePointer mouse_pointer(player_mouse_x, player_mouse_y);
               LabyrinthOfLore::Rendering::Hud::Renderer hud_renderer(al_get_backbuffer(display), &font_bin, &message_scroll, &mouse_pointer);
               hud_renderer.render();

               al_draw_scaled_bitmap(buffer_buffer, 0, 0, al_get_bitmap_width(buffer_buffer), al_get_bitmap_height(buffer_buffer), 0, 0, al_get_display_width(display), al_get_display_height(display), 0);
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


