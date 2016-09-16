#include "g_local.h"

void fire_gun(gentity_t *ent){
	gentity_t *bolt = NULL;
	bolt = spawn(bolt);
	if (bolt){
		bolt->pos_x = ent->pos_x + ent->width/2;
		bolt->pos_y = ent->pos_y;
		bolt->width = 15;
		bolt->height = 15;
		bolt->speed = 5.0;
		bolt->sprite = al_load_bitmap("../sprites/machinegun.png");
		bolt->dir_x = bolt->pos_x;
		bolt->dir_y = bolt->pos_y-300;
		bolt->parent = ent;
		bolt->next_think = level_time + 500;
		bolt->think = destroy;
		bolt->is_bolt = true;
		bolt->damage = 10;
		bolt->health = 0;
		bolt->lives = 0;
		bolt->move = move_up;
		bolt->die = destroy;
		//bolt->flags = 0x00000000;
		ent->next_fire = level_time + ent->fire_rate;
	}
}

void fire_machinegun(gentity_t *ent){
	gentity_t *bolt = NULL;
	bolt = spawn(bolt);
	if (bolt){
		bolt->pos_x = ent->pos_x + ent->width/2;
		bolt->pos_y = ent->pos_y;
		bolt->width = 15;
		bolt->height = 15;
		bolt->speed = 5.0;
		bolt->sprite = al_load_bitmap("../sprites/machinegun.png");
		bolt->dir_x = bolt->pos_x;
		bolt->dir_y = bolt->pos_y-300;
		bolt->parent = ent;
		bolt->next_think = level_time + 300;
		bolt->think = destroy;
		bolt->is_bolt = true;
		bolt->damage = 10;
		bolt->health = 0;
		bolt->lives = 0;
		bolt->move = move_up;
		bolt->die = destroy;
		//bolt->flags = 0x00000000;
		ent->next_fire = level_time + ent->fire_rate;
	}
}

void fire_enemy1(gentity_t *ent){
	gentity_t *bolt = NULL;
	bolt = spawn(bolt);
	if (bolt){
		bolt->pos_x = ent->pos_x + ent->width/2;
		bolt->pos_y = ent->pos_y;
		bolt->width = 10;
		bolt->height = 10;
		bolt->speed = 3.0;
		bolt->sprite = al_load_bitmap("../sprites/enemy_missile1.png");
		bolt->dir_x = bolt->pos_x;
		bolt->dir_y = bolt->pos_y-300;
		bolt->parent = ent;
		bolt->next_think = level_time + 500;
		bolt->think = destroy;
		bolt->is_bolt = true;
		bolt->damage = 10;
		bolt->health = 0;
		bolt->lives = 0;
		bolt->move = move_down;
		bolt->die = destroy;
		//bolt->flags = 0x00000000;
		ent->next_fire = level_time + ent->fire_rate;
	}
}