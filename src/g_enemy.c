#include "g_local.h"

void create_enemy(){
	gentity_t *enemy = NULL;
	gentity_t *enemy2 = NULL;
	enemy = spawn(enemy);
	if (enemy){
		enemy->pos_x = SCREEN_W;
		enemy->pos_y = SCREEN_H/7;
		enemy->width = 20;
		enemy->height = 20;
		enemy->speed = 3.0;
		enemy->sprite = al_load_bitmap("../art/sprites/enemy1.png");
		enemy->dir_x = -1;
		enemy->dir_y = 0;
		enemy->parent = enemy;
		enemy->next_think = level_time + 500;
		enemy->think = destroy;
		enemy->is_bolt = false;
		enemy->weapon = 0;
		enemy->fire_rate = 50;
		enemy->next_fire = level_time;
		enemy->fire = fire_enemy1;
		enemy->health = 10;
		enemy->damage = 1;
		enemy->lives = 1;
		enemy->score = 1;
		enemy->move = move_enemy1;
		enemy->die = death_enemy;
		enemy->is_enemy = true;
	}
	enemy2 = spawn(enemy2);
	if (enemy2){
		enemy2->pos_x = 0;
		enemy2->pos_y = 0;
		enemy2->width = 30;
		enemy2->height = 30;
		enemy2->speed = 3.0;
		enemy2->sprite = al_load_bitmap("../art/sprites/enemy2.png");
		enemy2->dir_x = 1;
		enemy2->dir_y = 1;
		enemy2->parent = enemy2;
		enemy2->next_think = level_time + 500;
		enemy2->think = destroy;
		enemy2->is_bolt = false;
		enemy2->weapon = 0;
		enemy2->fire_rate = 50;
		enemy2->next_fire = level_time;
		//enemy2->fire = fire_enemy1;
		enemy2->health = 1;
		enemy2->damage = 1;
		enemy2->lives = 1;
		enemy2->score = 1;
		enemy2->move = move;
		enemy2->die = death_enemy;
		enemy2->is_enemy = true;
	}
	spawnenemy_timer = level_time + 100;
}