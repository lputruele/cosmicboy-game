#include "g_local.h"

int init_level(){
	num_entities = 0;
	level_time = 0;
	game_over = false;
	memset (g_entities, 0, sizeof(*g_entities));
	return 0;
}


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

void free_entity(gentity_t *ent){
	//memset (ent, 0, sizeof(*ent));
	ent->inuse = false;
	erase_entity(ent);
	if (ent == player)
		game_over = true;
}

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
    		free_entity(ent);
    		free_entity(other);
    		break;
    	}
    }
}

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
        }
	}
}

