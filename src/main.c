/*
---------------------------------------------------------------
COSMIC BOY

This is the main game script, it consists of a loop that draws
a frame and updates the system state.
---------------------------------------------------------------
*/

#include "g_local.h"

int main()
{
	doexit = 0;
	//initialization
    init_screen();
	init_controls();
    init_sound();

    main_menu();
    init_level();
    init_player();

    //main loop
    while (!doexit)
    {
		ALLEGRO_EVENT ev;

		al_wait_for_event(events, &ev);
		if(ev.type == ALLEGRO_EVENT_TIMER) {
        	redraw = true;
        }
      	else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
        	key_down(ev);
      	}
      	else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
        	key_up(ev);
        }
        if (!game_paused){
    		if(!game_over && redraw && al_is_event_queue_empty(events)) {
    			redraw = false;
                pressed_keys();
    			al_clear_to_color(al_map_rgb(0,0,0));
                al_draw_bitmap(background,0,0 - (level_time/2) % 2000,0);
                update_entities();
                draw_entities();
                hud();
    			al_flip_display();
            }
            if (game_over){
                game_over_screen();
            }
            level_time++;
        }
    }

    //finalization
    destroy_level();
    destroy_sound();
    destroy_screen();

    return 0;
}