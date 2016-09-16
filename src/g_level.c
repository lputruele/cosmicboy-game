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

void damage(gentity_t *this, gentity_t *other){
	if (!this->flags & FL_GODMODE)
		this->health -= other->damage;
	if (!other->flags & FL_GODMODE)
		other->health -= this->damage;
	if (this->health <= 0)
		this->die(this);
	if (other->health <= 0)
		other->die(other);
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
    		))
    	{
    		if (ent == player && other->weapon){ //colliding with a crate
    			changeWeapon(other->weapon);
    			other->health -= 999; //it needs to die after this
    		}
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
            if (ent->move)
            	ent->move(ent);
            //collide
         	check_collide(ent);
         	//fire
         	if (ent != player && ent->next_fire && ent->next_fire < level_time && ent->fire)
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

