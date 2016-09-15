#include "g_local.h"

int init_level(){
	num_entities = 0;
	level_time = 0;
	game_over = false;
	score = 0;
	god_timer = level_time;
	spawnenemy_timer = level_time;
	memset (g_entities, 0, sizeof(*g_entities));
	return 0;
}

//Ocupies a slot of the entities array
gentity_t *spawn(gentity_t *ent){
	int i;
	if (num_entities < MAX_ENTITIES){
		for (i=0;i<=num_entities;i++){ //go until num_entities+1 to ensure a free position
			if (!g_entities[i]){
				ent = malloc(sizeof(*ent));
				memset (ent, 0, sizeof(*ent));
				g_entities[i] = ent;
				g_entities[i]->inuse = true;
				num_entities++;
				break;	
			}
			if (!g_entities[i]->inuse){
				ent = g_entities[i];
				memset (ent, 0, sizeof(*ent));
				g_entities[i] = ent;
				g_entities[i]->inuse = true;
				break;	
			}
		}
		return ent;
	}
	return 0;
}

//Free a slot in the entities array
void destroy(gentity_t *ent){
	//memset (ent, 0, sizeof(*ent));
	ent->inuse = false;
	erase_entity(ent);
	if (ent == player)
		game_over = true;
}

void explosion_anim(gentity_t *ent){
	switch (ent->count){
		case 0:
			ent->sprite = al_load_bitmap("../sprites/explosion1.png");
			ent->count++;
			break;
		case 1:
			ent->sprite = al_load_bitmap("../sprites/explosion2.png");
			ent->count++;
			break;
		case 2:
			ent->sprite = al_load_bitmap("../sprites/explosion3.png");
			ent->count++;
			break;
		case 3:
			ent->sprite = al_load_bitmap("../sprites/explosion4.png");
			ent->count++;
			break;
		case 4:
			ent->sprite = al_load_bitmap("../sprites/explosion3.png");
			ent->think = destroy;
			break;
		default:
			break;
	}
	ent->next_think = level_time + 3;
}
void die (gentity_t *ent){
	gentity_t *explosion = NULL;
	ent->lives--;
	if (ent->score) //add score if enemy dies
		score += ent->score;
	if (!ent->is_bolt){
		explosion = spawn(explosion);
		if (explosion){
			explosion->pos_x = ent->pos_x;
			explosion->pos_y = ent->pos_y;
			explosion->next_think = level_time + 3;
			explosion->think = explosion_anim;
		}
	}
	if (ent->lives <= 0)
		destroy(ent);
	else //is player
		revive();
}

void damage(gentity_t *this, gentity_t *other){
	if (!this->flags & FL_GODMODE)
		this->health -= other->damage;
	if (!other->flags & FL_GODMODE)
		other->health -= this->damage;
	if (this->health <= 0)
		die(this);
	if (other->health <= 0)
		die(other);
}

//Check collision of one entity with all other entities
void check_collide(gentity_t *ent){
	int j;
	gentity_t *other;
	for (j=0;j<num_entities;j++){
    	other = g_entities[j];
    	if (other && other->inuse &&
    		other != ent &&
    		other->parent != ent &&
    		ent->parent != other &&
    		//other->pos_x == ent->pos_x
    		((other->pos_x >= ent->pos_x &&
    		other->pos_x <= ent->pos_x + ent->width &&
    		other->pos_y >= ent->pos_y &&
    		other->pos_y <= ent->pos_y + ent->height) ||
    		(ent->pos_x >= other->pos_x &&
    		ent->pos_x <= other->pos_x + other->width &&
    		ent->pos_y >= other->pos_y &&
    		ent->pos_y <= other->pos_y + other->height)
    		)){
    		damage(ent,other);
    		break;
    	}
    }
}

//Updates the state of the level 
void update_entities(){
	int i;
	gentity_t *ent;
	for (i=0;i<num_entities;i++){
		ent = g_entities[i];
		if (ent && ent->inuse){
            //move
            if (ent->is_bolt && ent->parent == player)
            	ent->pos_y = ent->pos_y - ent->speed;
            else if (ent->is_bolt && ent->parent != player) //is an enemy bolt
            	ent->pos_y = ent->pos_y + ent->speed;
            else if (ent != player)//is an enemy
            	ent->pos_x = ent->pos_x - ent->speed;
            //collide
         	check_collide(ent);
         	//fire
         	if (ent != player && ent->next_shoot && ent->next_shoot < level_time && ent->fire)
                ent->fire(ent);
            //think
            if (ent->next_think && ent->next_think < level_time && ent->think)
                ent->think(ent);
            //check timers
            if (player->flags & FL_GODMODE && level_time > god_timer){
            	player->flags ^= FL_GODMODE;
            	player->sprite = al_load_bitmap("../sprites/player.png");
            }
            //create enemies
            if (level_time > spawnenemy_timer){
            	create_enemy();
            }
        }
	}
}

void create_enemy(){
	gentity_t *enemy = NULL;
	enemy = spawn(enemy);
	if (enemy){
		enemy->pos_x = SCREEN_W;
		enemy->pos_y = SCREEN_H/7;
		enemy->width = 20;
		enemy->height = 20;
		enemy->speed = 3.0;
		enemy->sprite = al_load_bitmap("../sprites/enemy1.png");
		enemy->dir_x = enemy->pos_x-300;
		enemy->dir_y = enemy->pos_y;
		enemy->parent = enemy;
		enemy->next_think = level_time + 500;
		enemy->think = destroy;
		enemy->is_bolt = false;
		enemy->weapon = 0;
		enemy->fire_rate = 50;
		enemy->next_shoot = level_time;
		enemy->fire = shoot;
		enemy->health = 10;
		enemy->damage = 1;
		enemy->lives = 1;
		enemy->score = 1;
	}
	spawnenemy_timer = level_time + 100;
}