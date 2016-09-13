#include "g_local.h"

int init_level(){
	num_entities = 0;
	level_time = 0;
	return 0;
}

int spawn(gentity_t **ent){
	int i;
	if (num_entities < MAX_ENTITIES){
		for (i=0;i<MAX_ENTITIES;i++){
			if (!g_entities[i]){
				*ent = malloc(sizeof(**ent));
				g_entities[i] = *ent;
				g_entities[i]->is_used = true;
				break;	
			}
			if (!g_entities[i]->is_used){
				*ent = g_entities[i];
				g_entities[i]->is_used = true;
				break;	
			}
		}
		num_entities++;
		return 1;
	}
	return 0;
}


void update_entities(){
	int i;
	for (i=0;i<num_entities;i++){
		//g_entities[i]->pos_x = g_entities[i]->dir_x-g_entities[i]->pos_x;
		g_entities[i]->pos_y = g_entities[i]->pos_y - g_entities[i]->speed;
	}
	return;
}