#include "g_local.h"

void move_down(gentity_t *ent){
	ent->pos_y = ent->pos_y + ent->speed;
	if ((ent->flags & FL_BOUNCE) && (ent->pos_y >= SCREEN_H)){
		ent->move = move_up;
	}
}

void move_up(gentity_t *ent){
	ent->pos_y = ent->pos_y - ent->speed;
	if ((ent->flags & FL_BOUNCE) && (ent->pos_y <= 0)){
		ent->move = move_down;
	}
}

void move_right(gentity_t *ent){
	ent->pos_x = ent->pos_x + ent->speed;
	if ((ent->flags & FL_BOUNCE) && (ent->pos_x >= SCREEN_W)){
		ent->move = move_left;
	}
}

void move_left(gentity_t *ent){
	ent->pos_x = ent->pos_x - ent->speed;
	if ((ent->flags & FL_BOUNCE) && (ent->pos_x <= 0)){
		ent->move = move_right;
	}
}

void move_rightdown(gentity_t *ent){
	ent->pos_x = ent->pos_x + ent->speed;
	ent->pos_y = ent->pos_y + ent->speed;
	if ((ent->flags & FL_BOUNCE) && (ent->pos_x >= SCREEN_W || ent->pos_y >= SCREEN_H)){
		ent->move = move_leftdown;
	}
}

void move_leftdown(gentity_t *ent){
	ent->pos_x = ent->pos_x - ent->speed;
	ent->pos_y = ent->pos_y + ent->speed;
	if ((ent->flags & FL_BOUNCE) && (ent->pos_x <= 0 || ent->pos_y >= SCREEN_H)){
		ent->move = move_leftup;
	}
}

void move_rightup(gentity_t *ent){
	ent->pos_x = ent->pos_x + ent->speed;
	ent->pos_y = ent->pos_y - ent->speed;
	if ((ent->flags & FL_BOUNCE) && (ent->pos_x >= SCREEN_W || ent->pos_y <= 0)){
		ent->move = move_rightdown;
	}
}

void move_leftup(gentity_t *ent){
	ent->pos_x = ent->pos_x - ent->speed;
	ent->pos_y = ent->pos_y - ent->speed;
	if ((ent->flags & FL_BOUNCE) && (ent->pos_x <= 0 || ent->pos_y <= 0)){
		ent->move = move_rightup;
	}
}