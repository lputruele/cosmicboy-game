#include "g_local.h"

void create_enemy(){
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
		enemy->move = move_left;
		enemy->die = death_enemy;
	}
	spawnenemy_timer = level_time + 100;
}