/*
---------------------------------------------------------------
COSMIC BOY

This script has functions for the animations.
Used by death script.
---------------------------------------------------------------
*/
#include "g_local.h"

void explosion_anim(gentity_t *ent){
	switch (ent->count){
		case 0:
			ent->sprite = al_load_bitmap("../art/sprites/explosion1.png");
			ent->count++;
			break;
		case 1:
			ent->sprite = al_load_bitmap("../art/sprites/explosion2.png");
			ent->count++;
			break;
		case 2:
			ent->sprite = al_load_bitmap("../art/sprites/explosion3.png");
			ent->count++;
			break;
		case 3:
			ent->sprite = al_load_bitmap("../art/sprites/explosion4.png");
			ent->count++;
			break;
		case 4:
			ent->sprite = al_load_bitmap("../art/sprites/explosion3.png");
			ent->think = destroy;
			break;
		default:
			break;
	}
	ent->next_think = level_time + 3;
}

void explosion_small_anim(gentity_t *ent){
	switch (ent->count){
		case 0:
			ent->sprite = al_load_bitmap("../art/sprites/explosion1.png");
			ent->count++;
			break;
		case 1:
			ent->sprite = al_load_bitmap("../art/sprites/explosion2.png");
			ent->think = destroy;
			break;
		default:
			break;
	}
	ent->next_think = level_time + 3;
}

void explosion_plasma_anim(gentity_t *ent){
	switch (ent->count){
		case 0:
			ent->sprite = al_load_bitmap("../art/sprites/plasma_explosion1.png");
			ent->count++;
			break;
		case 1:
			ent->sprite = al_load_bitmap("../art/sprites/plasma_explosion2.png");
			ent->count++;
			break;
		case 2:
			ent->sprite = al_load_bitmap("../art/sprites/plasma_explosion3.png");
			ent->count++;
			break;
		case 3:
			ent->sprite = al_load_bitmap("../art/sprites/plasma_explosion4.png");
			ent->count++;
			break;
		case 4:
			ent->sprite = al_load_bitmap("../art/sprites/plasma_explosion3.png");
			ent->think = destroy;
			break;
		default:
			break;
	}
	ent->next_think = level_time + 5;
}