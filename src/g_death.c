#include "g_local.h"


void death_rocket (gentity_t *ent){
	gentity_t *explosion = NULL;
	explosion = spawn(explosion);
	if (explosion){
		explosion->pos_x = ent->pos_x;
		explosion->pos_y = ent->pos_y;
		explosion->width = 50;
		explosion->height = 50;
		explosion->next_think = level_time + 3;
		explosion->think = explosion_anim;
		explosion->health = 300;
		explosion->die = destroy;
		explosion->damage = 2;
		explosion->parent = ent;
		al_play_sample(explosion_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
	destroy(ent);
}

void death_plasmamissile (gentity_t *ent){
	gentity_t *explosion = NULL;
	explosion = spawn(explosion);
	if (explosion){
		explosion->pos_x = ent->pos_x-100;
		explosion->pos_y = ent->pos_y;
		explosion->width = 350;
		explosion->height = 350;
		explosion->next_think = level_time + 3;
		explosion->think = explosion_plasma_anim;
		explosion->health = 300;
		explosion->die = destroy;
		explosion->damage = 10;
		explosion->parent = ent;
		al_play_sample(explosion_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
	destroy(ent);
}

void death_player (gentity_t *ent){
	gentity_t *explosion = NULL;
	ent->lives--;
	explosion = spawn(explosion);
	if (explosion){
		explosion->pos_x = ent->pos_x;
		explosion->pos_y = ent->pos_y;
		explosion->next_think = level_time + 3;
		explosion->think = explosion_anim;
		explosion->health = 300;
		explosion->die = destroy;
		explosion->parent = ent;
		al_play_sample(explosion_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
	if (ent->lives <= 0){
		destroy_sound();
		destroy(ent);
	}
	else 
		revive();
}

void spawn_crate (gentity_t *ent){
	int r;
	gentity_t *wp_crate = NULL;
	wp_crate = spawn(wp_crate); //enemies may drop weapon crates
	if (wp_crate){
		wp_crate->pos_x = ent->pos_x;
		wp_crate->pos_y = ent->pos_y;
		wp_crate->dir_x = 1;
		wp_crate->dir_y = 1;
		wp_crate->next_think = level_time + 1000;
		wp_crate->think = destroy;
		wp_crate->move = move;
		wp_crate->width = 30;
		wp_crate->height = 30;
		wp_crate->speed = 3.0;
		wp_crate->health = 300;
		wp_crate->flags |= FL_BOUNCE;
		wp_crate->die = destroy;
		wp_crate->parent = wp_crate;
		r = rand() % 5;
		switch (r){ // probability will be better the later stage we are in
			case 0:
				wp_crate->sprite = al_load_bitmap("../art/sprites/crate_machinegun.png");
				wp_crate->weapon = 1;
				break;
			case 1:
				wp_crate->sprite = al_load_bitmap("../art/sprites/crate_shotgun.png");
				wp_crate->weapon = 2;
				break;
			case 2:
				if (stage > 1){
					wp_crate->sprite = al_load_bitmap("../art/sprites/crate_rocket.png");
					wp_crate->weapon = 3;
				}
				else
					destroy(wp_crate);
				break;
			case 3:
				if (stage > 2){
					wp_crate->sprite = al_load_bitmap("../art/sprites/crate_bouncegun.png");
					wp_crate->weapon = 4;
				}
				else
					destroy(wp_crate);
				break;
			case 4:
				if (stage > 3){
					wp_crate->sprite = al_load_bitmap("../art/sprites/crate_lasergun.png");
					wp_crate->weapon = 5;
				}
				else
					destroy(wp_crate);	
				break;
			default:
				break;
		}	
	}
}

void death_enemy (gentity_t *ent){
	gentity_t *explosion = NULL;
	int r;
	if (!cheat_activated)
		score += ent->score;
	explosion = spawn(explosion);
	if (explosion){
		explosion->pos_x = ent->pos_x;
		explosion->pos_y = ent->pos_y;
		explosion->next_think = level_time + 3;
		explosion->think = explosion_small_anim;
		explosion->health = 300;
		explosion->die = destroy;
		explosion->parent = ent;
		al_play_sample(explosion_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
	r = rand() % 15;
	if(r==9){
		spawn_crate(ent);
	}
	destroy(ent);
}

void death_boss (gentity_t *ent){
	gentity_t *explosion = NULL;
	if (!cheat_activated)
		score += ent->score;
	explosion = spawn(explosion);
	if (explosion){
		explosion->pos_x = ent->pos_x;
		explosion->pos_y = ent->pos_y;
		explosion->next_think = level_time + 3;
		explosion->think = explosion_anim;
		explosion->health = 300;
		explosion->die = destroy;
		explosion->parent = ent;
		al_play_sample(explosion_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
	boss_activated = false;
	stage++;
	player->lives++;
	spawnboss_timer = level_time + 5000;
	stage_screen();
	level_background();
	destroy_sound();
	level_music();
	destroy(ent);
}