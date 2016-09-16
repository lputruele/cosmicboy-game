#include "g_local.h"


void move(gentity_t *ent){
	ent->pos_y = ent->pos_y + (ent->dir_y * ent->speed);
	ent->pos_x = ent->pos_x + (ent->dir_x * ent->speed);
	if (ent->flags & FL_BOUNCE){
		if ((ent->pos_y >= SCREEN_H) || (ent->pos_y <= 0)){
			ent->dir_y *= -1;
		}
		if ((ent->pos_x >= SCREEN_W) || (ent->pos_x <= 0)){
			ent->dir_x *= -1;
		}
	}
	
}

void move_enemy1(gentity_t *ent){
	if(ent->pos_x >= player->pos_x - 30 && ent->pos_x <= player->pos_x + 30){
		ent->dir_x = 0;
		ent->dir_y = 1;
		//ent->move = move;
	}
	move(ent);
}
