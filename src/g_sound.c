/*
---------------------------------------------------------------
COSMIC BOY

This script has functions for handling the sound and music.
Used by main and level scripts.
---------------------------------------------------------------
*/

#include "g_local.h"

int init_sound(){
	if(!al_install_audio()){
      fprintf(stderr, "failed to initialize audio!\n");
      return -1;
   }
 
   if(!al_init_acodec_addon()){
      fprintf(stderr, "failed to initialize audio codecs!\n");
      return -1;
   }
 
   if (!al_reserve_samples(10)){
      fprintf(stderr, "failed to reserve samples!\n");
      return -1;
   }
   explosion_sound = al_load_sample( "../art/sounds/explosion.wav" );
   fire_sound = al_load_sample( "../art/sounds/fire.wav" );
   return 0;
}

int level_music(){
	music = al_load_sample( "../art/music/level1.wav" );
	al_play_sample(music, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
	return 0;
}

int boss_music(){
   music = al_load_sample( "../art/music/boss.wav" );
   al_play_sample(music, 0.5, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
   return 0;
}

void destroy_sound(){
	al_destroy_sample(music);
}