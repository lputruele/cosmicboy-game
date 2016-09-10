#include "g_local.h"
#include <allegro_image.h>

int init_player(){
	player = malloc(sizeof(*player));
	player->pos_x = SCREEN_W/2 - SCREEN_W*0.09;
	player->pos_y = SCREEN_H/2 + SCREEN_H*0.25;
	player->width = 74;
	player->height = 74;
	player->speed = 10.0;
	player->sprite = al_load_bitmap("sprites/player.png");
	if(!player->sprite) {
      fprintf(stderr, "failed to load image!\n");
      al_destroy_display(display);
      return -1;
    }
	return 0;
}

int destroy_player(){
	al_destroy_bitmap(player->sprite);
	free(player);
	return 0;
}