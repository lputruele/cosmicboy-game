/*
---------------------------------------------------------------
COSMIC BOY

This script has functions for the player.
Used by main and enemy scripts.
---------------------------------------------------------------
*/

#include "g_local.h"

int init_player(){
	player = NULL;
	player = spawn(player);
	player->pos_x = SCREEN_W/2 - SCREEN_W*0.09;
	player->pos_y = SCREEN_H/2 + SCREEN_H*0.25;
	player->width = 27;
	player->height = 60;
	player->speed = 6.0;
	player->sprite = al_load_bitmap("../art/sprites/player.png");
	player->fire_rate = 30;
	player->next_fire = level_time;
	player->fire = fire_gun;
	player->parent = player;
	player->is_bolt = false;
	player->lives = 3;
	//player->health = 32000; // test
	player->health = 1;
	player->damage = 0;
	player->die = death_player;
	return 0;
}

int destroy_player(){
	al_destroy_bitmap(player->sprite);
	free(player);
	return 0;
}

void revive(){
	player->pos_x = SCREEN_W/2 - SCREEN_W*0.09;
	player->pos_y = SCREEN_H/2 + SCREEN_H*0.25;
	player->width = 27;
	player->height = 60;
	player->speed = 6.0;
	player->fire_rate = 30;
	player->next_fire = level_time;
	player->fire = fire_gun;
	player->health = 1;
	player->flags |= FL_GODMODE;
	player->sprite = al_load_bitmap("../art/sprites/player_god.png");
	god_timer = level_time + 300;
}

void changeWeapon(int weapon){
	switch (weapon){
		case 1:
			player->fire_rate = 15;
			player->fire = fire_machinegun;
			break;
		case 2:
			player->fire_rate = 40;
			player->fire = fire_shotgun;
			break;
		case 3:
			player->fire_rate = 50;
			player->fire = fire_rocket;
			break;
		case 4:
			player->fire_rate = 60;
			player->fire = fire_bouncegun;
			break;
		case 5:
			player->fire_rate = 8;
			player->fire = fire_lasergun;
			break;
		default:
			break;
	}
}

