#include "g_local.h"

//Initialization of the game
int init_level(){
	num_entities = 0;
	level_time = 0;
	game_over = false;
	score = 0;
	god_timer = level_time;
	spawnenemy_timer = level_time;
	spawnboss_timer = level_time + 10000;
	stage = 1;
	cheat_activated = false;
	file_score = NULL;
	boss_activated = false;
	background = al_load_bitmap("../art/sprites/space.png");
	memset (g_entities, 0, sizeof(g_entities));
	return 0;
}

//Destroys all game entities
int destroy_level(){
	int i;
	for (i=0;i<=num_entities;i++){
		if (g_entities[i]){
			g_entities[i]->inuse = false;
		}		
	}
	return 0;
}

//Spawns a game entity
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

//Destroys a game entity
void destroy(gentity_t *ent){
	ent->inuse = false;
	erase_entity(ent);
	if (ent == player)
		game_over = true;
	if (num_entities < MAX_ENTITIES && !(ent+sizeof(*ent))){ //if we can free space why not?
		memset (ent, 0, sizeof(*ent));
		free(ent);
	}
}

//Inflicts damage to both entities of a collision
void damage(gentity_t *this, gentity_t *other){
	if (!(this->flags & FL_GODMODE)){
		this->health -= other->damage;
		this->hit = true;
		if (this->pain)
			this->pain(this);
	}
	if (!(other->flags & FL_GODMODE)){
		other->health -= this->damage;
		other->hit = true;
		if (other->pain)
			other->pain(other);
	}
	if (this->health <= 0)
		this->die(this);
	if (other->health <= 0)
		other->die(other);
}

//Checks collision of one entity with all other entities
void check_collide(gentity_t *ent){
	int j;
	gentity_t *other;
	for (j=0;j<num_entities;j++){
    	other = g_entities[j];
    	if (other && other->inuse &&
    		other != ent &&
    		other->parent != ent &&
    		ent->parent != other &&
    		(!ent->is_bolt || !other->is_bolt) &&
    		(!ent->parent->is_enemy || !other->parent->is_enemy) &&
    		((other->pos_x >= ent->pos_x &&
    		other->pos_x <= ent->pos_x + ent->width &&
    		other->pos_y >= ent->pos_y &&
    		other->pos_y <= ent->pos_y + ent->height) ||
    		(other->pos_x >= ent->pos_x &&
    		other->pos_x <= ent->pos_x + ent->width &&
    		other->pos_y + other->height >= ent->pos_y &&
    		other->pos_y + other->height <= ent->pos_y + ent->height)
    		))
    	{
    		if (ent == player && other->weapon){ //colliding with a crate
    			changeWeapon(other->weapon);
    			other->health -= 999; //it needs to die after this
    		}
    		if (other == player && ent->weapon){ //colliding with a crate
    			changeWeapon(ent->weapon);
    			ent->health -= 999; //it needs to die after this
    		}
    		damage(ent,other);
    		break;
    	}
    }
}

//Spawns a wave of enemies
void enemy_wave(){
	int r = rand() % 5;
	switch (r){
		case 0:
			blaster_squad();
			break;
		case 1:
			melee_squad();
			break;
		case 2:
			fighter_squad();
			break;
		case 3:
			plasmamissile_squad();
			break;
		case 4:
			laserguy_squad();
			break;
		default:
			break;
	}
}

//Updates the state of the level 
void update_entities(){
	int i;
	gentity_t *ent;
	for (i=0;i<num_entities;i++){
		ent = g_entities[i];
		if (ent && ent->inuse){
            //collide
         	check_collide(ent);
            //move
            if (ent != player && ent->move)
            	ent->move(ent);
         	//fire
         	if (ent != player && ent->next_fire && ent->next_fire <= level_time && ent->fire)
                ent->fire(ent);
            //think
            if (ent->next_think && ent->next_think <= level_time && ent->think)
                ent->think(ent);
        }
	}
	//check timers
    if (player->flags & FL_GODMODE && level_time > god_timer){
    	player->flags ^= FL_GODMODE;
    	player->sprite = al_load_bitmap("../art/sprites/player.png");
    }
    //create boss
    if (level_time >= spawnboss_timer && !boss_activated){
    	boss_activated = true;
    	boss_fight(stage);
    }
	//create enemies
    if (level_time >= spawnenemy_timer && !boss_activated){
    	enemy_wave();
    }
}

