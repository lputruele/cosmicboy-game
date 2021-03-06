/*
---------------------------------------------------------------
COSMIC BOY

This script has functions for the display of menus, intermission
screens and the hud.
Used by main script.
---------------------------------------------------------------
*/

#include "g_local.h"

ALLEGRO_FONT *font_big,*font_medium, *font_small;
ALLEGRO_BITMAP *hud_object;
char buffer[20];
int topscore;

int main_menu(){
	al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon();// initialize the ttf (True Type Font) addon
    font_big = al_load_ttf_font("../ui/pirulen.ttf",72,0 );
    memset(buffer, 0, sizeof(buffer));
    topscore = 0;
 
    if (!font_big){
        fprintf(stderr, "Could not load 'pirulen.ttf'.\n");
        return -1;
    }

    font_medium = al_load_ttf_font("../ui/pirulen.ttf",24,0 );
 
    if (!font_medium){
        fprintf(stderr, "Could not load 'pirulen.ttf'.\n");
        return -1;
    }

    font_small = al_load_ttf_font("../ui/pirulen.ttf",12,0 );
 
    if (!font_small){
        fprintf(stderr, "Could not load 'pirulen.ttf'.\n");
        return -1;
    }
    al_clear_to_color(al_map_rgb(50,10,70));
    al_draw_text(font_big, al_map_rgb(255,255,255), SCREEN_W/2, (SCREEN_H/4),ALLEGRO_ALIGN_CENTRE, "COSMIC BOY");
    al_flip_display();
    sleep(2);
    return 0;
}

int stage_screen(){
    al_clear_to_color(al_map_rgb(50,120,50));
    sprintf(buffer, "STAGE %d", stage);
    al_draw_text(font_big, al_map_rgb(255,255,255), SCREEN_W/2, (SCREEN_H/4),ALLEGRO_ALIGN_CENTRE, buffer);
    al_flip_display();
    sleep(2);
    return 0;
}

int game_over_screen(){
    al_clear_to_color(red);
    al_draw_text(font_big, al_map_rgb(255,255,255), SCREEN_W/2, (SCREEN_H/4),ALLEGRO_ALIGN_CENTRE, "GAME OVER");
    al_draw_text(font_medium, al_map_rgb(255,255,255), SCREEN_W/2, (SCREEN_H*0.6),ALLEGRO_ALIGN_CENTRE, "PRESS ENTER TO RESTART");
    sprintf(buffer, "%d", score);
    file_score = fopen("topscore.txt","rw+");
    if (file_score){
        fscanf(file_score, "%d", &topscore);
        if (topscore < score){
            freopen(NULL,"w+",file_score);
            fprintf(file_score, "%d", score);
            topscore = score;
        }
        fclose(file_score);
    }
    sprintf(buffer, "TOP SCORE: %d", topscore);
    al_draw_text(font_medium, al_map_rgb(255,255,255), SCREEN_W/2, (SCREEN_H*0.8),ALLEGRO_ALIGN_CENTRE, buffer);
    al_flip_display();
    return 0;
}

int hud(){
    hud_object = al_load_bitmap("../art/sprites/heart.png");
    al_draw_bitmap(hud_object,SCREEN_W/10 - 35,SCREEN_H*0.9,0);

    sprintf(buffer, "%d", player->lives);
    al_draw_text(font_small, al_map_rgb(255,255,255), SCREEN_W/10, SCREEN_H*0.9, ALLEGRO_ALIGN_CENTRE, buffer);
    sprintf(buffer, "SCORE %d", score);
    al_draw_text(font_small, al_map_rgb(255,255,255), 2*SCREEN_W/10, SCREEN_H*0.9, ALLEGRO_ALIGN_CENTRE, buffer);
    sprintf(buffer, "STAGE %d", stage);
    al_draw_text(font_small, al_map_rgb(255,255,255), 3*SCREEN_W/10, SCREEN_H*0.9, ALLEGRO_ALIGN_CENTRE, buffer);
 
    return 0;
}