#include "g_local.h"
#include <allegro_image.h>

int init_screen(){
	display = NULL;
	events = NULL;
	timer = NULL;
	redraw = true;

	if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
    }
 
 	timer = al_create_timer(1.0 / FPS);
   	if(!timer) {
      fprintf(stderr, "failed to create timer!\n");
      return -1;
   	}

   	if(!al_init_image_addon()) {
      fprintf(stderr, "failed to initialize image addon!\n");
      return -1;
    }

	display = al_create_display(SCREEN_W, SCREEN_H);
	if(!display) {
      fprintf(stderr, "failed to create display!\n");
      return -1;
    }
 
    events = al_create_event_queue();
    if(!events) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_display(display);
      return -1;
    }
    if(!al_install_keyboard()) {
      fprintf(stderr, "failed to initialize the keyboard!\n");
      return -1;
    }
    al_set_new_display_option(ALLEGRO_SINGLE_BUFFER, 1, ALLEGRO_REQUIRE);
    al_set_new_display_flags(ALLEGRO_WINDOWED);
    al_init_primitives_addon();
    al_register_event_source(events, al_get_keyboard_event_source());
    al_register_event_source(events, al_get_timer_event_source(timer));
	
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
    al_start_timer(timer);

    orange = al_map_rgb(255, 210, 0);
    black = al_map_rgb(0, 0, 0);
    red = al_map_rgb(184, 22, 22);
    return 0;
}

int destroy_screen(){
	al_destroy_display(display);
    al_destroy_event_queue(events);
    al_destroy_timer(timer);
    return 0;
}

void draw_entity(gentity_t *ent){
  if (ent && ent->inuse && ent->sprite)
    al_draw_bitmap(ent->sprite,ent->pos_x,ent->pos_y,0);
  //al_flip_display();
}

void draw_entities(){
  int i;
  gentity_t *ent;
  for (i=0;i<num_entities;i++){
    ent = g_entities[i];
    if (ent && ent->inuse && ent->sprite)
      al_draw_bitmap(ent->sprite,ent->pos_x,ent->pos_y,0);
  }
  //al_flip_display();
}

void erase_entity(gentity_t *ent){
  if (ent && ent->inuse && ent->sprite)
	   al_destroy_bitmap(ent->sprite);
}

