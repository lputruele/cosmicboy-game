#include <stdio.h>
#include <allegro.h>
#include <allegro_primitives.h>
#include <allegro_image.h>
#include "g_local.h"

int main()
{
	doexit = 0;
	//initialization
    init_screen();
	init_player();
	init_controls();

    //main loop
    while (!doexit)
    {
		ALLEGRO_EVENT ev;

		al_wait_for_event(events, &ev);
		if(ev.type == ALLEGRO_EVENT_TIMER) {
			pressed_keys();
        	redraw = true;
        }
      	else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
        	key_down(ev);
      	}
      	else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
        	key_up(ev);
        }
		if(redraw && al_is_event_queue_empty(events)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0,0,0));
			draw_entity(player);
			al_flip_display();
        }
    }

    //finalization
    destroy_screen();
    destroy_player();
    return 0;
}