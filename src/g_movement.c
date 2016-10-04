#include "g_local.h"


void move(gentity_t *ent){
	ent->pos_y = ent->pos_y + (ent->dir_y * ent->speed);
	ent->pos_x = ent->pos_x + (ent->dir_x * ent->speed);
	if (ent->flags & FL_BOUNCE){
		if ((ent->pos_y >= SCREEN_H - ent->height) || (ent->pos_y <= ent->height)){
			ent->dir_y *= -1;
		}
		if ((ent->pos_x >= SCREEN_W - ent->width) || (ent->pos_x <= ent->width)){
			ent->dir_x *= -1;
		}
	}
	
}

void move_enemy1(gentity_t *ent){
	if(ent->pos_x >= player->pos_x - 30 && ent->pos_x <= player->pos_x + 30){
		ent->dir_x = 0;
		ent->dir_y = 1;
	}
	move(ent);
}

void move_enemy2(gentity_t *ent){
	if(ent->pos_x <= SCREEN_W/2){
		if (ent->dir_x == 1)
			ent->dir_y -= 1/ent->pos_x;
		else
			ent->dir_y += 1/ent->pos_x;
	}
	else{
		if (ent->dir_x == 1)
			ent->dir_y += 1/ent->pos_x;
		else
			ent->dir_y -= 1/ent->pos_x;
	}
	move(ent);
}

void move_boss1(gentity_t *ent){
	if (ent->pos_y <= SCREEN_H/2 && ent->pos_y > SCREEN_H/4 && ent->count == 0){
		ent->dir_x = 1;
		ent->dir_y = 0;
		ent->count++;
	}
	if ((ent->pos_x >= SCREEN_W - 2*ent->width) || (ent->pos_x <= 2*ent->width)){
			ent->dir_x *= -1;
	}
	move(ent);
}