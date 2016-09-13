#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "g_local.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
//#include <pthread.h>
//#include <semaphore.h>

int main()
{
	doexit = 0;
	//initialization
    init_screen();
    init_level();
	init_player();
	init_controls();

    main_menu();

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
            update_entities();
            draw_entities();
			draw_entity(player);
			al_flip_display();
        }
        level_time++;
    }

    //finalization
    destroy_screen();
    destroy_player();
    return 0;
}