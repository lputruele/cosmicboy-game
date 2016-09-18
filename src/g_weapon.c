#include "g_local.h"


void fire_gun(gentity_t *ent){
	gentity_t *bolt = NULL;
	bolt = spawn_bullet(ent->pos_x + ent->width/2, ent->pos_y, ent);
	if (bolt){
		ent->next_fire = level_time + ent->fire_rate;
		al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}

void fire_bouncegun(gentity_t *ent){
	gentity_t *bolt = NULL;
	gentity_t *bolt2 = NULL;
	bolt = spawn_bounceball(ent->pos_x + ent->width/2, ent->pos_y, ent);
	bolt2 = spawn_bounceball(ent->pos_x + ent->width/2, ent->pos_y, ent);
	if (bolt && bolt2){
		bolt->dir_x = 0.2;
		bolt->dir_y = -1;
		bolt2->dir_x = -0.2;
		bolt2->dir_y = -1;
		ent->next_fire = level_time + ent->fire_rate;
		al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}

void fire_rocket(gentity_t *ent){
	gentity_t *bolt = NULL;
	bolt = spawn_rocket(ent->pos_x + ent->width/2, ent->pos_y, ent);
	if (bolt){
		ent->next_fire = level_time + ent->fire_rate;
		al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}

void fire_shotgun(gentity_t *ent){
	gentity_t *bolt = NULL;
	gentity_t *bolt2 = NULL;
	gentity_t *bolt3 = NULL;
	bolt = spawn_bullet(ent->pos_x + ent->width/2, ent->pos_y, ent);
	bolt2 = spawn_bullet(ent->pos_x - ent->width/2, ent->pos_y, ent);
	bolt3 = spawn_bullet(ent->pos_x + 1.5*ent->width, ent->pos_y, ent);
	if (bolt && bolt2 && bolt3){
		ent->next_fire = level_time + ent->fire_rate;
		al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}

void fire_machinegun(gentity_t *ent){
	gentity_t *bolt = NULL;
	bolt = spawn_bullet(ent->pos_x + ent->width/2, ent->pos_y, ent);
	if (bolt){
		ent->next_fire = level_time + ent->fire_rate;
		al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}

void fire_lasergun(gentity_t *ent){
	gentity_t *bolt = NULL;
	bolt = spawn_laser(ent->pos_x + ent->width/2, ent->pos_y-240, ent);
	if (bolt){
		ent->next_fire = level_time + ent->fire_rate;
		al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}

void fire_enemy1(gentity_t *ent){
	gentity_t *bolt = NULL;
	bolt = spawn_enemy_bullet(ent->pos_x + ent->width/2, ent->pos_y, ent);
	if (bolt){
		ent->next_fire = level_time + ent->fire_rate;
		al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}

void fire_enemy2(gentity_t *ent){
	gentity_t *bolt = NULL;
	gentity_t *bolt2 = NULL;
	bolt = spawn_enemy_bullet(ent->pos_x + ent->width/2, ent->pos_y, ent);
	bolt2 = spawn_enemy_bullet(ent->pos_x + ent->width/2+40, ent->pos_y, ent);
	if (bolt && bolt2){
		ent->next_fire = level_time + ent->fire_rate;
		al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}