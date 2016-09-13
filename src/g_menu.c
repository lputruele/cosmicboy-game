#include "g_local.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

int main_menu(){
	al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon();// initialize the ttf (True Type Font) addon
    ALLEGRO_FONT *font = al_load_ttf_font("../ui/pirulen.ttf",72,0 );
 
    if (!font){
        fprintf(stderr, "Could not load 'pirulen.ttf'.\n");
        return -1;
    }

    al_clear_to_color(al_map_rgb(50,10,70));
    al_draw_text(font, al_map_rgb(255,255,255), SCREEN_W/2, (SCREEN_H/4),ALLEGRO_ALIGN_CENTRE, "COSMIC BOY");
 
    al_flip_display();
    sleep(2);
    return 0;
}