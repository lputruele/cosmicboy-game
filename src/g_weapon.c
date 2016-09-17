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
		bolt->sprite = al_load_bitmap("../art/sprites/machinegun.png");
		bolt->dir_x = 0;
		bolt->dir_y = -1;
		bolt->parent = ent;
		bolt->next_think = level_time + 500;
		bolt->think = destroy;
		bolt->is_bolt = true;
		bolt->damage = 10;
		bolt->health = 0;
		bolt->lives = 0;
		bolt->move = move;
		bolt->die = destroy;
		//bolt->flags = 0x00000000;
		ent->next_fire = level_time + ent->fire_rate;
		al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}

void fire_rocket(gentity_t *ent){
	gentity_t *bolt = NULL;
	bolt = spawn(bolt);
	if (bolt){
		bolt->pos_x = ent->pos_x + ent->width/2;
		bolt->pos_y = ent->pos_y;
		bolt->width = 25;
		bolt->height = 35;
		bolt->speed = 3.0;
		bolt->sprite = al_load_bitmap("../art/sprites/rocket.png");
		bolt->dir_x = 0;
		bolt->dir_y = -1;
		bolt->parent = ent;
		bolt->next_think = level_time + 500;
		bolt->think = destroy;
		bolt->is_bolt = true;
		bolt->damage = 30;
		bolt->health = 0;
		bolt->lives = 0;
		bolt->move = move;
		bolt->die = death_rocket;
		//bolt->flags = 0x00000000;
		ent->next_fire = level_time + ent->fire_rate;
		al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}

void fire_shotgun(gentity_t *ent){
	gentity_t *bolt = NULL;
	gentity_t *bolt2 = NULL;
	gentity_t *bolt3 = NULL;
	bolt = spawn(bolt);
	bolt2 = spawn(bolt2);
	bolt3 = spawn(bolt3);
	if (bolt && bolt2 && bolt3){
		bolt->pos_x = ent->pos_x + ent->width/2;
		bolt->pos_y = ent->pos_y;
		bolt->width = 15;
		bolt->height = 15;
		bolt->speed = 5.0;
		bolt->sprite = al_load_bitmap("../art/sprites/machinegun.png");
		bolt->dir_x = 0;
		bolt->dir_y = -1;
		bolt->parent = ent;
		bolt->next_think = level_time + 500;
		bolt->think = destroy;
		bolt->is_bolt = true;
		bolt->damage = 10;
		bolt->health = 0;
		bolt->lives = 0;
		bolt->move = move;
		bolt->die = destroy;
		//bolt->flags = 0x00000000;
		bolt2->pos_x = ent->pos_x - ent->width/2;
		bolt2->pos_y = ent->pos_y;
		bolt2->width = 15;
		bolt2->height = 15;
		bolt2->speed = 5.0;
		bolt2->sprite = al_load_bitmap("../art/sprites/machinegun.png");
		bolt2->dir_x = 0;
		bolt2->dir_y = -1;
		bolt2->parent = ent;
		bolt2->next_think = level_time + 500;
		bolt2->think = destroy;
		bolt2->is_bolt = true;
		bolt2->damage = 10;
		bolt2->health = 0;
		bolt2->lives = 0;
		bolt2->move = move;
		bolt2->die = destroy;
		//bolt->flags = 0x00000000;
		bolt3->pos_x = ent->pos_x + 1.5*ent->width;
		bolt3->pos_y = ent->pos_y;
		bolt3->width = 15;
		bolt3->height = 15;
		bolt3->speed = 5.0;
		bolt3->sprite = al_load_bitmap("../art/sprites/machinegun.png");
		bolt3->dir_x = 0;
		bolt3->dir_y = -1;
		bolt3->parent = ent;
		bolt3->next_think = level_time + 500;
		bolt3->think = destroy;
		bolt3->is_bolt = true;
		bolt3->damage = 10;
		bolt3->health = 0;
		bolt3->lives = 0;
		bolt3->move = move;
		bolt3->die = destroy;
		//bolt->flags = 0x00000000;
		ent->next_fire = level_time + ent->fire_rate;
		al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
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
		bolt->sprite = al_load_bitmap("../art/sprites/machinegun.png");
		bolt->dir_x = 0;
		bolt->dir_y = -1;
		bolt->parent = ent;
		bolt->next_think = level_time + 300;
		bolt->think = destroy;
		bolt->is_bolt = true;
		bolt->damage = 10;
		bolt->health = 0;
		bolt->lives = 0;
		bolt->move = move;
		bolt->die = destroy;
		//bolt->flags = 0x00000000;
		ent->next_fire = level_time + ent->fire_rate;
		al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
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
		bolt->speed = 6.0;
		bolt->sprite = al_load_bitmap("../art/sprites/enemy_missile1.png");
		bolt->dir_x = 0;
		bolt->dir_y = 1;
		bolt->parent = ent;
		bolt->next_think = level_time + 500;
		bolt->think = destroy;
		bolt->is_bolt = true;
		bolt->damage = 10;
		bolt->health = 0;
		bolt->lives = 0;
		bolt->move = move;
		bolt->die = destroy;
		//bolt->flags = 0x00000000;
		ent->next_fire = level_time + ent->fire_rate;
		al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}