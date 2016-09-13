#include "g_local.h"
#include <allegro_image.h>
#include <stdio.h>

int init_player(){
	player = malloc(sizeof(*player));
	player->pos_x = SCREEN_W/2 - SCREEN_W*0.09;
	player->pos_y = SCREEN_H/2 + SCREEN_H*0.25;
	player->width = 74;
	player->height = 74;
	player->speed = 6.0;
	player->sprite = al_load_bitmap("../sprites/player.png");
	player->weapon = 0;
	player->fire_rate = 20;
	player->next_shoot = level_time;
	return 0;
}

int destroy_player(){
	al_destroy_bitmap(player->sprite);
	free(player);
	return 0;
}

int shoot(){
	gentity_t *missile = NULL;
	if (spawn(&missile)){
		switch(player->weapon){
		case 0: //machinegun
			missile->pos_x = player->pos_x+32;
			missile->pos_y = player->pos_y;
			missile->width = 35;
			missile->height = 35;
			missile->speed = 10.0;
			missile->sprite = al_load_bitmap("../sprites/machinegun.png");
			missile->dir_x = missile->pos_x;
			missile->dir_y = missile->pos_y-300;
			missile->parent = player;
			break;
		default:
			break;
		}
		player->next_shoot = level_time + player->fire_rate;
	}
	return 0;
}