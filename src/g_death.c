#include "g_local.h"

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
		al_play_sample(explosion_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
	if (ent->lives <= 0)
		destroy(ent);
	else 
		revive();
}

void death_enemy (gentity_t *ent){
	gentity_t *explosion = NULL;
	gentity_t *wp_crate = NULL;
	int r;
	score += ent->score;
	explosion = spawn(explosion);
	if (explosion){
		explosion->pos_x = ent->pos_x;
		explosion->pos_y = ent->pos_y;
		explosion->next_think = level_time + 3;
		explosion->think = explosion_small_anim;
		explosion->health = 300;
		explosion->die = destroy;
		al_play_sample(explosion_sound, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
	r = rand() % 10;
	if(r==9){
		wp_crate = spawn(wp_crate); //enemies may drop weapon crates
		if (wp_crate){
			wp_crate->pos_x = ent->pos_x;
			wp_crate->pos_y = ent->pos_y;
			wp_crate->next_think = level_time + 1000;
			wp_crate->think = destroy;
			wp_crate->move = move_rightdown;
			wp_crate->width = 25;
			wp_crate->height = 25;
			wp_crate->speed = 3.0;
			wp_crate->health = 300;
			wp_crate->sprite = al_load_bitmap("../art/sprites/crate_machinegun.png");
			wp_crate->flags |= FL_BOUNCE;
			wp_crate->die = destroy;
			wp_crate->weapon = 1;
		}
	}
	destroy(ent);
}