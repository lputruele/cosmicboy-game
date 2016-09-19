#include "g_local.h"

//cheat variables
char last_char[2]; // saves last character of every partial cheatcode
bool partial_cheatcode; // true if player is writing a cheatcode

int init_controls(){
	int i;
	for (i=0;i<MAX_KEYS;i++){
		key[i] = false;
	}
    memset(last_char,0, sizeof(last_char));
    partial_cheatcode = false;
    return 0;
}

void check_lives_cheat(ALLEGRO_EVENT ev){
    switch(ev.keyboard.keycode) {
        case ALLEGRO_KEY_I:
            partial_cheatcode = true;
            last_char[0] = 'i';
            break; 
        case ALLEGRO_KEY_M:
            if (partial_cheatcode && last_char[0] == 'i')
                last_char[0] = 'm';
            break;
        case ALLEGRO_KEY_A: 
            if (partial_cheatcode && last_char[0] == 'm')
                last_char[0] = 'a';
            break;
        case ALLEGRO_KEY_P:
            if (partial_cheatcode && last_char[0] == 'a')
                last_char[0] = 'p';
            break;
        case ALLEGRO_KEY_U:
            if (partial_cheatcode && last_char[0] == 'p')
                last_char[0] = 'u';
            break;
        case ALLEGRO_KEY_S:
            if (partial_cheatcode && last_char[0] == 'u')
                last_char[0] = 's';
            break;
        case ALLEGRO_KEY_Y:
            if (partial_cheatcode && last_char[0] == 's'){
                last_char[0] = 'y';
                player->lives = 99;
                cheat_activated = true;
                partial_cheatcode = false;
            }
            break;
        default:
            last_char[0] = '!';
            break;
    }
}

void check_fort_cheat(ALLEGRO_EVENT ev){
    switch(ev.keyboard.keycode) {
        case ALLEGRO_KEY_R:
            partial_cheatcode = true;
            last_char[1] = 'r';
            break; 
        case ALLEGRO_KEY_O:
            if (partial_cheatcode && last_char[1] == 'r')
                last_char[1] = 'o';
            break;
        case ALLEGRO_KEY_Y: 
            if (partial_cheatcode && last_char[1] == 'o')
                last_char[1] = 'y';
            break;
        case ALLEGRO_KEY_C:
            if (partial_cheatcode && last_char[1] == 'y')
                last_char[1] = 'c';
            break;
        case ALLEGRO_KEY_E:
            if (partial_cheatcode && last_char[1] == 'c'){
                last_char[1] = 'e';
                player->sprite = al_load_bitmap("../art/sprites/fort.png");
                cheat_activated = true;
                partial_cheatcode = false;
            }
            break;
        default:
            last_char[1] = '!';
            break;
    }
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
    if (game_over){
        switch(ev.keyboard.keycode){
            case ALLEGRO_KEY_ENTER:
                destroy_level();
                //restart_level();
                game_over = false;
                score = 0;
                level_time = 0;
                spawnenemy_timer = 0;
                init_player();
                break;
            default:
                break;
        }              
    }
    check_lives_cheat(ev);
    check_fort_cheat(ev);
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