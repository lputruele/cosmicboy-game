/*
---------------------------------------------------------------
COSMIC BOY

This script has functions to manipulate the graphic aspect of 
the game.
Used by main and level scripts.
---------------------------------------------------------------
*/

#include "g_local.h"

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
  //al_get_display_mode(al_get_num_display_modes() - 1, &disp_data);
  al_get_display_mode(1, &disp_data);
  al_set_new_display_flags(ALLEGRO_FULLSCREEN);
  SCREEN_W = disp_data.width;
  SCREEN_H = disp_data.height;
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
    al_init_primitives_addon();
    al_register_event_source(events, al_get_keyboard_event_source());
    al_register_event_source(events, al_get_timer_event_source(timer));
	
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
    al_start_timer(timer);

    orange = al_map_rgb(255, 210, 0);
    black = al_map_rgb(0, 0, 0);
    red = al_map_rgb(184, 22, 22);
    green = al_map_rgb(10, 180, 10);
    return 0;
}

int destroy_screen(){
	al_destroy_display(display);
  al_destroy_event_queue(events);
  al_destroy_timer(timer);
  return 0;
}

void draw_entity(gentity_t *ent){
  if (ent && ent->inuse && ent->sprite){
    if (ent->hit){
      if (ent->is_enemy)
        al_draw_tinted_bitmap(ent->sprite, al_map_rgba_f(1, 0, 0, 1), ent->pos_x - ent->width/2,ent->pos_y,0);
      ent->hit = false;
    }
    else
      al_draw_bitmap(ent->sprite,ent->pos_x - ent->width/2,ent->pos_y,0);
  }
}

void draw_entities(){
  int i;
  gentity_t *ent;
  for (i=0;i<num_entities;i++){
    ent = g_entities[i];
    draw_entity(ent);
    //draw position
    //al_draw_rectangle(ent->pos_x, ent->pos_y, ent->pos_x, ent->pos_y, green, 5);
    //draw collider
    //al_draw_rectangle(ent->pos_x, ent->pos_y, ent->pos_x + ent->width, ent->pos_y + ent->height, red, 1);
  }
}

void erase_entity(gentity_t *ent){
  if (ent && ent->inuse && ent->sprite)
	   al_destroy_bitmap(ent->sprite);
}

void level_background(){
  switch (stage){
    case 1:
        background = al_load_bitmap("../art/sprites/space.png");
        break;
    case 2:
        background = al_load_bitmap("../art/sprites/space2.png");
        break;
    case 3:
        background = al_load_bitmap("../art/sprites/space3.png");
        break;
    case 4:
        background = al_load_bitmap("../art/sprites/space4.png");
        break;
    default:
        background = al_load_bitmap("../art/sprites/space.png");
        break;
  }
}

