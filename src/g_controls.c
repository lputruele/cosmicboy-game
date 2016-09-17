#include "g_local.h"

int init_controls(){
	int i;
	for (i=0;i<MAX_KEYS;i++){
		key[i] = false;
	}
	return 0;
}

int pressed_keys(){
    if (!game_over){
    	if(key[KEY_UP] && player->pos_y >= player->height) {
    		player->pos_y -= player->speed;
    	}
    	if(key[KEY_DOWN] && player->pos_y <= SCREEN_H - 2*player->height) {
    		player->pos_y += player->speed;
    	}
    	if(key[KEY_LEFT] && player->pos_x >= player->width) {
    		player->pos_x -= player->speed;
    	}
    	if(key[KEY_RIGHT] && player->pos_x <= SCREEN_W - 4*player->width) {
    		player->pos_x += player->speed;
    	}
        if(key[KEY_SHOOT] && level_time >= player->next_fire) {
            player->fire(player);
        }
    }
	return 0;
}

int key_down(ALLEGRO_EVENT ev){
	switch(ev.keyboard.keycode) {
        case ALLEGRO_KEY_UP:
        	key[KEY_UP] = true;
       		break; 
        case ALLEGRO_KEY_DOWN:
            key[KEY_DOWN] = true;
            break;
        case ALLEGRO_KEY_LEFT: 
            key[KEY_LEFT] = true;
            break;
        case ALLEGRO_KEY_RIGHT:
            key[KEY_RIGHT] = true;
            break;
        case ALLEGRO_KEY_ESCAPE:
        	doexit = true;
        	break;
        case ALLEGRO_KEY_A:
            key[KEY_SHOOT] = true;
            break;
    }
	return 0;
}

int key_up(ALLEGRO_EVENT ev){
	switch(ev.keyboard.keycode) {
        case ALLEGRO_KEY_UP:
        	key[KEY_UP] = false;
       		break; 
        case ALLEGRO_KEY_DOWN:
            key[KEY_DOWN] = false;
            break;
        case ALLEGRO_KEY_LEFT: 
            key[KEY_LEFT] = false;
            break;
        case ALLEGRO_KEY_RIGHT:
            key[KEY_RIGHT] = false;
            break;
        case ALLEGRO_KEY_A:
            key[KEY_SHOOT] = false;
            break;
    }
	return 0;
}