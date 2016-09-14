#include "g_local.h"
#include <allegro_image.h>
#include <stdio.h>

int init_player(){
	player = NULL;
	player = spawn(player);
	//player = malloc(sizeof(*player));
	player->pos_x = SCREEN_W/2 - SCREEN_W*0.09;
	player->pos_y = SCREEN_H/2 + SCREEN_H*0.25;
	player->width = 45;
	player->height = 25;
	player->speed = 6.0;
	player->sprite = al_load_bitmap("../sprites/player.png");
	player->weapon = 0;
	player->fire_rate = 30;
	player->next_shoot = level_time;
	player->fire = shoot;
	player->parent = player;
	player->is_bolt = false;
	player->next_think = level_time + 80;
	player->think = create_enemy;
	return 0;
}

int destroy_player(){
	al_destroy_bitmap(player->sprite);
	free(player);
	return 0;
}

void shoot(gentity_t *ent){
	gentity_t *bolt = NULL;
	bolt = spawn(bolt);
	if (bolt){
		switch(ent->weapon){
		case 0: //machinegun
			bolt->pos_x = ent->pos_x+32;
			bolt->pos_y = ent->pos_y;
			bolt->width = 15;
			bolt->height = 15;
			bolt->speed = 3.0;
			bolt->sprite = al_load_bitmap("../sprites/machinegun.png");
			bolt->dir_x = bolt->pos_x;
			bolt->dir_y = bolt->pos_y-300;
			bolt->parent = ent;
			bolt->next_think = level_time + 500;
			bolt->think = free_entity;
			bolt->is_bolt = true;
			break;
		default:
			break;
		}
		ent->next_shoot = level_time + ent->fire_rate;
	}
}

void create_enemy(gentity_t *ent){
	gentity_t *enemy = NULL;
	enemy = spawn(enemy);
	if (enemy){
		enemy->pos_x = SCREEN_W;
		enemy->pos_y = SCREEN_H/7;
		enemy->width = 20;
		enemy->height = 20;
		enemy->speed = 3.0;
		enemy->sprite = al_load_bitmap("../sprites/enemy1.png");
		enemy->dir_x = enemy->pos_x-300;
		enemy->dir_y = enemy->pos_y;
		enemy->parent = enemy;
		enemy->next_think = level_time + 500;
		enemy->think = free_entity;
		enemy->is_bolt = false;
		enemy->weapon = 0;
		enemy->fire_rate = 50;
		enemy->next_shoot = level_time;
		enemy->fire = shoot;
	}
	ent->next_think = level_time + 80;
}