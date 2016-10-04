#include "g_local.h"


void fire_gun(gentity_t *ent){
	gentity_t *bolt = NULL;
	bolt = spawn_bullet(ent->pos_x + ent->width/2, ent->pos_y,0,-1, ent);
	if (bolt){
		ent->next_fire = level_time + ent->fire_rate;
		al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}

void fire_bouncegun(gentity_t *ent){
	gentity_t *bolt = NULL;
	gentity_t *bolt2 = NULL;
	bolt = spawn_bounceball(ent->pos_x + ent->width, ent->pos_y,0.2,-1, ent);
	bolt2 = spawn_bounceball(ent->pos_x , ent->pos_y,-0.2,-1, ent);
	if (bolt && bolt2){
		ent->next_fire = level_time + ent->fire_rate;
		al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}

void fire_rocket(gentity_t *ent){
	gentity_t *bolt = NULL;
	bolt = spawn_rocket(ent->pos_x + ent->width/2, ent->pos_y,0,-1, ent);
	if (bolt){
		ent->next_fire = level_time + ent->fire_rate;
		al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}

void fire_shotgun(gentity_t *ent){
	gentity_t *bolt = NULL;
	gentity_t *bolt2 = NULL;
	gentity_t *bolt3 = NULL;
	bolt = spawn_bullet(ent->pos_x + ent->width/2, ent->pos_y,0,-1, ent);
	bolt2 = spawn_bullet(ent->pos_x - ent->width/2, ent->pos_y,0,-1, ent);
	bolt3 = spawn_bullet(ent->pos_x + 1.5*ent->width, ent->pos_y,0,-1, ent);
	if (bolt && bolt2 && bolt3){
		ent->next_fire = level_time + ent->fire_rate;
		al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}

void fire_machinegun(gentity_t *ent){
	gentity_t *bolt = NULL;
	bolt = spawn_bullet(ent->pos_x + ent->width/2, ent->pos_y,0,-1, ent);
	if (bolt){
		ent->next_fire = level_time + ent->fire_rate;
		al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}

void fire_lasergun(gentity_t *ent){
	gentity_t *bolt = NULL;
	bolt = spawn_laser(ent->pos_x + ent->width/2, ent->pos_y-240,0,-1, ent);
	if (bolt){
		ent->next_fire = level_time + ent->fire_rate;
		al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}

void fire_enemy1(gentity_t *ent){
	gentity_t *bolt = NULL;
	bolt = spawn_enemy_bullet(ent->pos_x + ent->width/2, ent->pos_y,0,1, ent);
	if (bolt){
		ent->next_fire = level_time + ent->fire_rate;
		al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}

void fire_enemy2(gentity_t *ent){
	gentity_t *bolt = NULL;
	gentity_t *bolt2 = NULL;
	bolt = spawn_enemy_bullet(ent->pos_x + ent->width/2, ent->pos_y,0,1, ent);
	bolt2 = spawn_enemy_bullet(ent->pos_x + ent->width/2+40, ent->pos_y,0,1, ent);
	if (bolt && bolt2){
		ent->next_fire = level_time + ent->fire_rate;
		al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
}

void fire_enemy3(gentity_t *ent){
	gentity_t *bolt = NULL;
	if(ent->pos_x >= player->pos_x - 30 && ent->pos_x <= player->pos_x + 30){
		bolt = spawn_enemy_laser(ent->pos_x + ent->width/2, ent->pos_y,0,1, ent);
		if (bolt){
			ent->next_fire = level_time + ent->fire_rate;
			al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
		}
	}
}

void fire_boss1(gentity_t *ent){
	gentity_t *bolt,*bolt2,*bolt3,*bolt4;
	int r;
	bolt = NULL;
	bolt2 = NULL;
	bolt3 = NULL;
	bolt4 = NULL;
	r = rand() % 4;
	switch (r){
		case 0:
			bolt = spawn_enemy_bullet_medium(ent->pos_x + ent->width/2, ent->pos_y,0,-1, ent);
			bolt2 = spawn_enemy_bullet_medium(ent->pos_x + ent->width/2 + 40, ent->pos_y,0,-1, ent);
			if (bolt && bolt2){
				ent->next_fire = level_time + ent->fire_rate;
				al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
			}
			break;
		case 1:
			bolt = spawn_enemy_bullet(ent->pos_x + ent->width/2 - 50, ent->pos_y + ent->height - 60,0,1, ent);
			bolt2 = spawn_enemy_bullet(ent->pos_x + ent->width/2 - 50, ent->pos_y + ent->height - 60,0,-1, ent);
			bolt3 = spawn_enemy_bullet(ent->pos_x + ent->width/2 - 50, ent->pos_y + ent->height - 60,1,0, ent);
			bolt4 = spawn_enemy_bullet(ent->pos_x + ent->width/2 - 50, ent->pos_y + ent->height - 60,-1,0, ent);
			if (bolt && bolt2 && bolt3 && bolt4){
				ent->next_fire = level_time + ent->fire_rate;
				al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
			}
			break;
		case 2:
			bolt = spawn_enemy_bullet(ent->pos_x + ent->width/2 + 50, ent->pos_y + ent->height - 60,0,1, ent);
			bolt2 = spawn_enemy_bullet(ent->pos_x + ent->width/2 + 50, ent->pos_y + ent->height - 60,0,-1, ent);
			bolt3 = spawn_enemy_bullet(ent->pos_x + ent->width/2 + 50, ent->pos_y + ent->height - 60,1,0, ent);
			bolt4 = spawn_enemy_bullet(ent->pos_x + ent->width/2 + 50, ent->pos_y + ent->height - 60,-1,0, ent);
			if (bolt && bolt2 && bolt3 && bolt4){
				ent->next_fire = level_time + ent->fire_rate;
				al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
			}
			break;
		default:
			bolt = spawn_enemy_bullet_medium(ent->pos_x + ent->width/2 - 40, ent->pos_y + ent->height - 50,0,1, ent);
			bolt2 = spawn_enemy_bullet_medium(ent->pos_x + ent->width/2 -20, ent->pos_y + ent->height,0,1, ent);
			bolt3 = spawn_enemy_bullet_medium(ent->pos_x + ent->width/2 + 20, ent->pos_y + ent->height,0,1, ent);
			bolt4 = spawn_enemy_bullet_medium(ent->pos_x + ent->width/2 + 40, ent->pos_y + ent->height - 50,0,1, ent);
			if (bolt && bolt2 && bolt3 && bolt4){
				ent->next_fire = level_time + ent->fire_rate;
				al_play_sample(fire_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
			}
			break;
	}
}