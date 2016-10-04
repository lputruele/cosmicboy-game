#include "g_local.h"

void create_blaster(float posx, float posy, float dirx){
	gentity_t *enemy = NULL;
	enemy = spawn(enemy);
	if (enemy){
		enemy->pos_x = posx;
		enemy->pos_y = posy;
		enemy->width = 25;
		enemy->height = 50;
		enemy->speed = 3.0;
		enemy->sprite = al_load_bitmap("../art/sprites/enemy1.png");
		enemy->dir_x = dirx;
		enemy->dir_y = 0;
		enemy->parent = enemy;
		enemy->next_think = level_time + 1000;
		enemy->think = destroy;
		enemy->is_bolt = false;
		enemy->fire_rate = 100;
		enemy->next_fire = level_time;
		enemy->fire = fire_enemy1;
		enemy->health = 10;
		enemy->damage = 1;
		enemy->lives = 1;
		enemy->score = 1;
		enemy->move = move;
		enemy->die = death_enemy;
		enemy->is_enemy = true;
	}
}
void create_melee(float posx, float posy, float dirx){
	gentity_t *enemy = NULL;
	enemy = spawn(enemy);
	if (enemy){
		enemy->pos_x = posx;
		enemy->pos_y = posy;
		enemy->width = 23;
		enemy->height = 55;
		enemy->speed = 6.0;
		enemy->sprite = al_load_bitmap("../art/sprites/enemy2.png");
		enemy->dir_x = dirx;
		enemy->dir_y = 0.3;
		enemy->parent = enemy;
		enemy->next_think = level_time + 1000;
		enemy->think = destroy;
		enemy->is_bolt = false;
		enemy->fire_rate = 50;
		enemy->next_fire = level_time;
		//enemy->fire = fire_enemy1;
		enemy->health = 1;
		enemy->damage = 1;
		enemy->lives = 1;
		enemy->score = 1;
		enemy->move = move_enemy1;
		enemy->die = death_enemy;
		enemy->is_enemy = true;
	}
}

void create_fighter(float posx, float posy, float dirx){
	gentity_t *enemy = NULL;
	enemy = spawn(enemy);
	if (enemy){
		enemy->pos_x = posx;
		enemy->pos_y = posy;
		enemy->width = 37;
		enemy->height = 60;
		enemy->speed = 4.0;
		enemy->sprite = al_load_bitmap("../art/sprites/enemy3.png");
		enemy->dir_x = dirx;
		enemy->dir_y = 1;
		enemy->parent = enemy;
		enemy->next_think = level_time + 1000;
		enemy->think = destroy;
		enemy->is_bolt = false;
		enemy->fire_rate = 50;
		enemy->next_fire = level_time;
		enemy->fire = fire_enemy2;
		enemy->health = 1;
		enemy->damage = 1;
		enemy->lives = 1;
		enemy->score = 1;
		enemy->move = move;
		enemy->die = death_enemy;
		enemy->is_enemy = true;
	}
}

void create_laserguy(float posx, float posy, float dirx){
	gentity_t *enemy = NULL;
	enemy = spawn(enemy);
	if (enemy){
		enemy->pos_x = posx;
		enemy->pos_y = posy;
		enemy->width = 50;
		enemy->height = 70;
		enemy->speed = 4.0;
		enemy->sprite = al_load_bitmap("../art/sprites/enemy12.png");
		enemy->dir_x = dirx;
		enemy->dir_y = 0;
		enemy->parent = enemy;
		enemy->next_think = level_time + 1000;
		enemy->think = destroy;
		enemy->is_bolt = false;
		enemy->fire_rate = 10;
		enemy->next_fire = level_time;
		enemy->fire = fire_enemy3;
		enemy->health = 20;
		enemy->damage = 1;
		enemy->lives = 1;
		enemy->score = 1;
		enemy->move = move_enemy2;
		enemy->die = death_enemy;
		enemy->is_enemy = true;
	}
}

void create_plasmamissile(float posx, float posy, float dirx){
	gentity_t *enemy = NULL;
	enemy = spawn(enemy);
	if (enemy){
		enemy->pos_x = posx;
		enemy->pos_y = posy;
		enemy->width = 65;
		enemy->height = 240;
		enemy->speed = 4.0;
		enemy->sprite = al_load_bitmap("../art/sprites/enemy13.png");
		enemy->dir_x = dirx;
		enemy->dir_y = 0.2;
		enemy->parent = enemy;
		enemy->next_think = level_time + 800;
		enemy->think = death_plasmamissile;
		enemy->is_bolt = false;
		enemy->fire_rate = 50;
		enemy->next_fire = level_time;
		//enemy->fire = fire_enemy2;
		enemy->health = 300;
		enemy->damage = 1;
		enemy->lives = 1;
		enemy->score = 1;
		enemy->move = move;
		enemy->die = death_plasmamissile;
		enemy->is_enemy = true;
	}
}
void blaster_squad(){
	int r = rand() % 4;
	float posx,posy,dirx;
	int i;
	switch (r){
		case 0:
			posx = SCREEN_W;
			posy = SCREEN_H/9;
			dirx = -1;
			break;
		case 1:
			posx = 0;
			posy = SCREEN_H/9;
			dirx = 1;
			break;
		case 2:
			posx = 0;
			posy = SCREEN_H/6;
			dirx = 1;
			break;
		case 3:
			posx = SCREEN_W;
			posy = SCREEN_H/6;
			dirx = -1;
			break;
		default:
			break;
	}
	for (i=0; i<5; i++){
		create_blaster(posx-80*i*dirx, posy+50*(5-i), dirx);
	}
	spawnenemy_timer = level_time + 150;
}

void melee_squad(){
	int r = rand() % 4;
	float posx,posy,dirx;
	int i;
	switch (r){
		case 0:
			posx = SCREEN_W*0.8;
			posy = -100;
			dirx = -1;
			break;
		case 1:
			posx = SCREEN_W/8;
			posy = -100;
			dirx = 1;
			break;
		case 2:
			posx = SCREEN_W/8;
			posy = -100;
			dirx = 1;
			break;
		case 3:
			posx = SCREEN_W*0.8;
			posy = -100;
			dirx = -1;
			break;
		default:
			break;
	}
	for (i=0; i<5; i++){
		create_melee(posx-80*i*dirx, posy+50*(5-i), dirx);
	}
	spawnenemy_timer = level_time + 150;
}

void fighter_squad(){
	int r = rand() % 2;
	float posx,posy,dirx;
	switch (r){
		case 0:
			posx = SCREEN_W*0.3;
			posy = -100;
			dirx = 0;
			break;
		case 1:
			posx = SCREEN_W*0.7;
			posy = -100;
			dirx = 0;
			break;
		default:
			break;
	}
	create_fighter(posx, posy, dirx);
	create_fighter(posx - 100, posy - 50, dirx);
	create_fighter(posx + 100, posy - 50, dirx);
	spawnenemy_timer = level_time + 100;
}

void laserguy_squad(){
	create_laserguy(-50, SCREEN_H * 0.6, 1);
	create_laserguy(SCREEN_W + 50, SCREEN_H * 0.6, -1);
	spawnenemy_timer = level_time + 100;
}

void plasmamissile_squad(){
	int r = rand() % 2;
	float posx,posy,dirx;
	switch (r){
		case 0:
			posx = SCREEN_W*0.3;
			posy = -100;
			dirx = 0;
			break;
		case 1:
			posx = SCREEN_W*0.7;
			posy = -100;
			dirx = 0;
			break;
		default:
			break;
	}
	create_plasmamissile(posx, posy, dirx);
	spawnenemy_timer = level_time + 200;
}

void activate_bounce(gentity_t *ent){
	ent->flags |= FL_BOUNCE;
}

void add_speed(gentity_t *ent){
	ent->speed += 0.1;
}

void boss1(){
	gentity_t *boss = NULL;
	boss = spawn(boss);
	if (boss){
		boss->pos_x = SCREEN_W/2;
		boss->pos_y = 0;
		boss->width = 110;
		boss->height = 210;
		boss->speed = 1.0;
		boss->sprite = al_load_bitmap("../art/sprites/boss2.png");
		boss->dir_x = 0;
		boss->dir_y = 1;
		boss->parent = boss;
		boss->next_think = level_time + 100;
		//boss->think = activate_bounce;
		boss->is_bolt = false;
		boss->fire_rate = 25;
		boss->next_fire = level_time;
		boss->fire = fire_boss1;
		boss->health = 500;
		boss->damage = 1;
		boss->lives = 1;
		boss->score = 1;
		boss->move = move_boss1;
		boss->die = death_boss;
		//boss->pain = add_speed;
		boss->is_enemy = true;
		boss->count = 0;
	}
}

void boss2(){
	gentity_t *boss = NULL;
	boss = spawn(boss);
	if (boss){
		boss->pos_x = SCREEN_W/2;
		boss->pos_y = 0;
		boss->width = 150;
		boss->height = 150;
		boss->speed = 1.0;
		boss->sprite = al_load_bitmap("../art/sprites/boss1.png");
		boss->dir_x = 0;
		boss->dir_y = 1;
		boss->parent = boss;
		boss->next_think = level_time + 100;
		//boss->think = activate_bounce;
		boss->is_bolt = false;
		boss->fire_rate = 25;
		boss->next_fire = level_time;
		boss->fire = fire_boss1;
		boss->health = 500;
		boss->damage = 1;
		boss->lives = 1;
		boss->score = 1;
		boss->move = move_boss1;
		boss->die = death_boss;
		//boss->pain = add_speed;
		boss->is_enemy = true;
		boss->count = 0;
	}
}

void boss3(){
	gentity_t *boss = NULL;
	boss = spawn(boss);
	if (boss){
		boss->pos_x = SCREEN_W/2;
		boss->pos_y = 0;
		boss->width = 150;
		boss->height = 150;
		boss->speed = 1.0;
		boss->sprite = al_load_bitmap("../art/sprites/boss3.png");
		boss->dir_x = 0;
		boss->dir_y = 1;
		boss->parent = boss;
		boss->next_think = level_time + 100;
		//boss->think = activate_bounce;
		boss->is_bolt = false;
		boss->fire_rate = 25;
		boss->next_fire = level_time;
		boss->fire = fire_boss1;
		boss->health = 500;
		boss->damage = 1;
		boss->lives = 1;
		boss->score = 1;
		boss->move = move_boss1;
		boss->die = death_boss;
		//boss->pain = add_speed;
		boss->is_enemy = true;
		boss->count = 0;
	}
}

void boss_fight(int stage){
	switch (stage){
		case 1:
			boss1();
			destroy_sound();
    		boss_music();
			break;
		default:
			boss_activated = false;
			break;
	}
}