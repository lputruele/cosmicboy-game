#include "g_local.h"

void create_blaster(float posx, float posy, float dirx){
	gentity_t *enemy = NULL;
	enemy = spawn(enemy);
	if (enemy){
		enemy->pos_x = posx;
		enemy->pos_y = posy;
		enemy->width = 20;
		enemy->height = 20;
		enemy->speed = 3.0;
		enemy->sprite = al_load_bitmap("../art/sprites/enemy1.png");
		enemy->dir_x = dirx;
		enemy->dir_y = 0;
		enemy->parent = enemy;
		enemy->next_think = level_time + 1000;
		enemy->think = destroy;
		enemy->is_bolt = false;
		enemy->weapon = 0;
		enemy->fire_rate = 100;
		enemy->next_fire = level_time;
		enemy->fire = fire_enemy1;
		enemy->health = 10;
		enemy->damage = 1;
		enemy->lives = 1;
		enemy->score = 1;
		enemy->move = move;
		enemy->die = death_enemy;
		enemy->is_enemy = true;
	}
}
void create_melee(float posx, float posy, float dirx){
	gentity_t *enemy = NULL;
	enemy = spawn(enemy);
	if (enemy){
		enemy->pos_x = posx;
		enemy->pos_y = posy;
		enemy->width = 30;
		enemy->height = 30;
		enemy->speed = 6.0;
		enemy->sprite = al_load_bitmap("../art/sprites/enemy2.png");
		enemy->dir_x = dirx;
		enemy->dir_y = 0.3;
		enemy->parent = enemy;
		enemy->next_think = level_time + 1000;
		enemy->think = destroy;
		enemy->is_bolt = false;
		enemy->weapon = 0;
		enemy->fire_rate = 50;
		enemy->next_fire = level_time;
		//enemy->fire = fire_enemy1;
		enemy->health = 1;
		enemy->damage = 1;
		enemy->lives = 1;
		enemy->score = 1;
		enemy->move = move_enemy1;
		enemy->die = death_enemy;
		enemy->is_enemy = true;
	}
}

void blaster_squad(){
	int r = rand() % 4;
	float posx,posy,dirx;
	int i;
	switch (r){
		case 0:
			posx = SCREEN_W;
			posy = SCREEN_H/9;
			dirx = -1;
			break;
		case 1:
			posx = 0;
			posy = SCREEN_H/9;
			dirx = 1;
			break;
		case 2:
			posx = 0;
			posy = SCREEN_H/6;
			dirx = 1;
			break;
		case 3:
			posx = SCREEN_W;
			posy = SCREEN_H/6;
			dirx = -1;
			break;
		default:
			break;
	}
	for (i=0; i<5; i++){
		create_blaster(posx-80*i*dirx, posy+50*(5-i), dirx);
	}
	spawnenemy_timer = level_time + 200;
}

void melee_squad(){
	int r = rand() % 4;
	float posx,posy,dirx;
	int i;
	switch (r){
		case 0:
			posx = SCREEN_W*0.8;
			posy = -100;
			dirx = -1;
			break;
		case 1:
			posx = SCREEN_W/8;
			posy = -100;
			dirx = 1;
			break;
		case 2:
			posx = SCREEN_W/8;
			posy = -100;
			dirx = 1;
			break;
		case 3:
			posx = SCREEN_W*0.8;
			posy = -100;
			dirx = -1;
			break;
		default:
			break;
	}
	for (i=0; i<5; i++){
		create_melee(posx-80*i*dirx, posy+50*(5-i), dirx);
	}
	spawnenemy_timer = level_time + 200;
}
