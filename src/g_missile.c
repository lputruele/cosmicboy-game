#include "g_local.h"

gentity_t *spawn_bullet(float x, float y, gentity_t *parent){
	gentity_t *bolt = NULL;
	bolt = spawn(bolt);
	if (bolt){
		bolt->pos_x = x;
		bolt->pos_y = y;
		bolt->width = 15;
		bolt->height = 15;
		bolt->speed = 5.0;
		bolt->sprite = al_load_bitmap("../art/sprites/machinegun.png");
		bolt->dir_x = 0;
		bolt->dir_y = -1;
		bolt->next_think = level_time + 500;
		bolt->think = destroy;
		bolt->is_bolt = true;
		bolt->damage = 10;
		bolt->health = 0;
		bolt->lives = 0;
		bolt->move = move;
		bolt->die = destroy;
		bolt->parent = parent;
		return bolt;
	}
	return NULL;
}

gentity_t *spawn_enemy_bullet(float x, float y, gentity_t *parent){
	gentity_t *bolt = NULL;
	bolt = spawn(bolt);
	if (bolt){
		bolt->pos_x = x;
		bolt->pos_y = y;
		bolt->width = 10;
		bolt->height = 10;
		bolt->speed = 6.0;
		bolt->sprite = al_load_bitmap("../art/sprites/enemy_missile1.png");
		bolt->dir_x = 0;
		bolt->dir_y = 1;
		bolt->parent = parent;
		bolt->next_think = level_time + 500;
		bolt->think = destroy;
		bolt->is_bolt = true;
		bolt->damage = 10;
		bolt->health = 0;
		bolt->lives = 0;
		bolt->move = move;
		bolt->die = destroy;
		return bolt;
	}
	return NULL;
}

gentity_t *spawn_bounceball(float x, float y, gentity_t *parent){
	gentity_t *bolt = NULL;
	bolt = spawn(bolt);
	if (bolt){
		bolt->pos_x = x;
		bolt->pos_y = y;
		bolt->width = 15;
		bolt->height = 15;
		bolt->speed = 7.0;
		bolt->sprite = al_load_bitmap("../art/sprites/bouncegun.png");
		bolt->dir_x = 0.2;
		bolt->dir_y = -1;
		bolt->parent = parent;
		bolt->next_think = level_time + 300;
		bolt->think = destroy;
		bolt->is_bolt = true;
		bolt->damage = 10;
		bolt->health = 1;
		bolt->lives = 0;
		bolt->move = move;
		bolt->die = destroy;
		bolt->flags |= FL_BOUNCE;
		return bolt;
	}
	return NULL;
}

gentity_t *spawn_rocket(float x, float y, gentity_t *parent){
	gentity_t *bolt = NULL;
	bolt = spawn(bolt);
	if (bolt){
		bolt->pos_x = x;
		bolt->pos_y = y;
		bolt->width = 25;
		bolt->height = 35;
		bolt->speed = 3.0;
		bolt->sprite = al_load_bitmap("../art/sprites/rocket.png");
		bolt->dir_x = 0;
		bolt->dir_y = -1;
		bolt->parent = parent;
		bolt->next_think = level_time + 500;
		bolt->think = destroy;
		bolt->is_bolt = true;
		bolt->damage = 30;
		bolt->health = 0;
		bolt->lives = 0;
		bolt->move = move;
		bolt->die = death_rocket;
		return bolt;
	}
	return NULL;
}

gentity_t *spawn_laser(float x, float y, gentity_t *parent){
	gentity_t *bolt = NULL;
	bolt = spawn(bolt);
	if (bolt){
		bolt->pos_x = x;
		bolt->pos_y = y;
		bolt->width = 25;
		bolt->height = 200;
		bolt->speed = 0.0;
		bolt->sprite = al_load_bitmap("../art/sprites/laser.png");
		bolt->dir_x = 0;
		bolt->dir_y = -1;
		bolt->parent = parent;
		bolt->next_think = level_time + 10;
		bolt->think = destroy;
		bolt->is_bolt = true;
		bolt->damage = 30;
		bolt->health = 900;
		bolt->lives = 0;
		bolt->move = move;
		bolt->die = destroy;
		return bolt;
	}
	return NULL;
}