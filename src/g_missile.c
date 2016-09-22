#include "g_local.h"

gentity_t *spawn_bullet(float posx, float posy, float dirx, float diry, gentity_t *parent){
	gentity_t *bolt = NULL;
	bolt = spawn(bolt);
	if (bolt){
		bolt->pos_x = posx;
		bolt->pos_y = posy;
		bolt->width = 15;
		bolt->height = 15;
		bolt->speed = 5.0;
		bolt->sprite = al_load_bitmap("../art/sprites/bullet.png");
		bolt->dir_x = dirx;
		bolt->dir_y = diry;
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

gentity_t *spawn_enemy_bullet(float posx, float posy, float dirx, float diry, gentity_t *parent){
	gentity_t *bolt = NULL;
	bolt = spawn(bolt);
	if (bolt){
		bolt->pos_x = posx;
		bolt->pos_y = posy;
		bolt->width = 10;
		bolt->height = 10;
		bolt->speed = 6.0;
		bolt->sprite = al_load_bitmap("../art/sprites/enemy_missile.png");
		bolt->dir_x = dirx;
		bolt->dir_y = diry;
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

gentity_t *spawn_enemy_bullet_medium(float posx, float posy, float dirx, float diry, gentity_t *parent){
	gentity_t *bolt = NULL;
	bolt = spawn(bolt);
	if (bolt){
		bolt->pos_x = posx;
		bolt->pos_y = posy;
		bolt->width = 30;
		bolt->height = 30;
		bolt->speed = 3.0;
		bolt->sprite = al_load_bitmap("../art/sprites/enemy_missile_medium.png");
		bolt->dir_x = dirx;
		bolt->dir_y = diry;
		bolt->parent = parent;
		bolt->next_think = level_time + 500;
		bolt->think = destroy;
		bolt->is_bolt = true;
		bolt->damage = 40;
		bolt->health = 0;
		bolt->lives = 0;
		bolt->move = move;
		bolt->die = destroy;
		return bolt;
	}
	return NULL;
}

gentity_t *spawn_enemy_bullet_big(float posx, float posy, float dirx, float diry, gentity_t *parent){
	gentity_t *bolt = NULL;
	bolt = spawn(bolt);
	if (bolt){
		bolt->pos_x = posx;
		bolt->pos_y = posy;
		bolt->width = 80;
		bolt->height = 80;
		bolt->speed = 3.0;
		bolt->sprite = al_load_bitmap("../art/sprites/enemy_missile_big.png");
		bolt->dir_x = dirx;
		bolt->dir_y = diry;
		bolt->parent = parent;
		bolt->next_think = level_time + 500;
		bolt->think = destroy;
		bolt->is_bolt = true;
		bolt->damage = 100;
		bolt->health = 0;
		bolt->lives = 0;
		bolt->move = move;
		bolt->die = destroy;
		return bolt;
	}
	return NULL;
}

gentity_t *spawn_bounceball(float posx, float posy, float dirx, float diry, gentity_t *parent){
	gentity_t *bolt = NULL;
	bolt = spawn(bolt);
	if (bolt){
		bolt->pos_x = posx;
		bolt->pos_y = posy;
		bolt->width = 15;
		bolt->height = 15;
		bolt->speed = 7.0;
		bolt->sprite = al_load_bitmap("../art/sprites/bouncegun.png");
		bolt->dir_x = dirx;
		bolt->dir_y = diry;
		bolt->parent = parent;
		bolt->next_think = level_time + 300;
		bolt->think = destroy;
		bolt->is_bolt = true;
		bolt->damage = 10;
		bolt->health = 0;
		bolt->lives = 0;
		bolt->move = move;
		bolt->die = destroy;
		bolt->flags |= FL_BOUNCE;
		return bolt;
	}
	return NULL;
}

gentity_t *spawn_rocket(float posx, float posy, float dirx, float diry, gentity_t *parent){
	gentity_t *bolt = NULL;
	bolt = spawn(bolt);
	if (bolt){
		bolt->pos_x = posx;
		bolt->pos_y = posy;
		bolt->width = 25;
		bolt->height = 35;
		bolt->speed = 3.0;
		bolt->sprite = al_load_bitmap("../art/sprites/rocket.png");
		bolt->dir_x = dirx;
		bolt->dir_y = diry;
		bolt->parent = parent;
		bolt->next_think = level_time + 500;
		bolt->think = destroy;
		bolt->is_bolt = true;
		bolt->damage = 30;
		bolt->health = 1;
		bolt->lives = 0;
		bolt->move = move;
		bolt->die = death_rocket;
		return bolt;
	}
	return NULL;
}

gentity_t *spawn_laser(float posx, float posy, float dirx, float diry, gentity_t *parent){
	gentity_t *bolt = NULL;
	bolt = spawn(bolt);
	if (bolt){
		bolt->pos_x = posx;
		bolt->pos_y = posy;
		bolt->width = 25;
		bolt->height = 200;
		bolt->speed = 0.0;
		bolt->sprite = al_load_bitmap("../art/sprites/laser.png");
		bolt->dir_x = dirx;
		bolt->dir_y = diry;
		bolt->parent = parent;
		bolt->next_think = level_time + 10;
		bolt->think = destroy;
		bolt->is_bolt = true;
		bolt->damage = 1;
		bolt->health = 900;
		bolt->lives = 0;
		bolt->move = move;
		bolt->die = destroy;
		return bolt;
	}
	return NULL;
}