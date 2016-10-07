#include <stdio.h>
#include <allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_ttf.h>
#include <stdlib.h>
#include <string.h>

ALLEGRO_DISPLAY *display;
ALLEGRO_DISPLAY_MODE disp_data;
ALLEGRO_EVENT_QUEUE *events;
ALLEGRO_BITMAP *background;
ALLEGRO_TIMER *timer;
ALLEGRO_COLOR orange,black,red,green;
ALLEGRO_SAMPLE *music,*explosion_sound,*fire_sound;

//gentity flags
#define FL_GODMODE		0x00000001
#define FL_BOUNCE		0x00000002

//constants
//#define SCREEN_W		800
//#define SCREEN_H		600
#define FPS 			60.0
#define MAX_KEYS		5
#define MAX_ENTITIES	1000
int SCREEN_W,SCREEN_H;

enum MYKEYS {
   KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT,
   KEY_SHOOT
};

typedef struct gentity gentity_t;

//Game entity structure i.e ships, bolts and asteroids
struct gentity{
	bool			inuse;	//entity is ignored if false
	float 			pos_x;	
	float 			pos_y;
	int 			width;
	int 			height;
	float 			speed;
	ALLEGRO_BITMAP  *sprite;
	float 			dir_x;
	float 			dir_y;
	int 			weapon; //matters if entity is a crate
	int 			fire_rate;
	int 			flags;
	gentity_t 		*parent;
	int 			next_think;	//when to call think	
	int 			next_fire;	//when will fire be available
	void 			(*think)(gentity_t *self);
	void			(*fire)(gentity_t *self);
	void			(*move)(gentity_t *self);
	void			(*pain)(gentity_t *self);
	void			(*die)(gentity_t *self);
	bool			is_bolt;
	bool			is_enemy;
	int 			lives;	//amount of lives left
	int 			health;
	int 			damage;	//damage that inflicts when colliding
	int 			count;	//just a counter utility
	int 			score;	//amount of score an enemy gives if dead
	bool			hit;
};

bool redraw;
bool doexit;
bool game_over;
bool game_paused;
bool key[MAX_KEYS];
bool cheat_activated;
bool boss_activated;
int num_entities;	//entities currently allocated in game
int level_time;	//global clock
int score;
int god_timer;
int spawnboss_timer;
int spawnenemy_timer;
int stage;
gentity_t *player;
gentity_t *g_entities[MAX_ENTITIES];	//has pointers to all entities in the game
FILE* file_score;


//g_display.c

int init_screen();
int destroy_screen();
void draw_entity(gentity_t *ent);
void erase_entity(gentity_t *ent);
void draw_entities();
void level_background();

//g_player.c

void changeWeapon(int weapon);
int init_player();
int destroy_player();
void revive();

//g_controls.c

int init_controls();
int pressed_keys();
int key_down(ALLEGRO_EVENT ev);
int key_up(ALLEGRO_EVENT ev);

//g_menu.c

int main_menu();
int stage_screen();
int game_over_screen();
int hud();

//g_level.c

int init_level();
void restart_level();
int destroy_level();
void update_entities();
gentity_t *spawn(gentity_t *ent);
void destroy(gentity_t *ent);

//g_enemy.c

void blaster_squad();
void melee_squad();
void fighter_squad();
void laserguy_squad();
void crossunit_squad();
void plasmamissile_squad();
void boss_fight();

//g_animation.c

void explosion_anim(gentity_t *ent);
void explosion_small_anim(gentity_t *ent);
void explosion_plasma_anim(gentity_t *ent);

//g_weapon.c

void fire_gun(gentity_t *ent);
void fire_shotgun(gentity_t *ent);
void fire_machinegun(gentity_t *ent);
void fire_rocket(gentity_t *ent);
void fire_bouncegun(gentity_t *ent);
void fire_lasergun(gentity_t *ent);
void fire_enemy1(gentity_t *ent);
void fire_enemy2(gentity_t *ent);
void fire_enemy3(gentity_t *ent);
void fire_enemy4(gentity_t *ent);
void fire_boss1(gentity_t *ent);

//g_missile.c

gentity_t *spawn_rocket(float posx, float posy, float dirx, float diry, gentity_t *parent);
gentity_t *spawn_bullet(float posx, float posy, float dirx, float diry, gentity_t *parent);
gentity_t *spawn_bounceball(float posx, float posy, float dirx, float diry, gentity_t *parent);
gentity_t *spawn_laser(float posx, float posy, float dirx, float diry, gentity_t *parent);
gentity_t *spawn_enemy_bullet(float posx, float posy, float dirx, float diry, gentity_t *parent);
gentity_t *spawn_enemy_bullet_medium(float posx, float posy, float dirx, float diry, gentity_t *parent);
gentity_t *spawn_enemy_bullet_big(float posx, float posy, float dirx, float diry, gentity_t *parent);
gentity_t *spawn_enemy_laser(float posx, float posy, float dirx, float diry, gentity_t *parent);

//g_movement.c

void move(gentity_t *ent);
void move_enemy1(gentity_t *ent);
void move_enemy2(gentity_t *ent);
void move_boss1(gentity_t *ent);

//g_death.c

void death_player (gentity_t *ent);
void death_enemy (gentity_t *ent);
void death_rocket (gentity_t *ent);
void death_plasmamissile (gentity_t *ent);
void death_boss (gentity_t *ent);

//g_sound.c

int init_sound();
int level_music();
int boss_music();
void destroy_sound();
