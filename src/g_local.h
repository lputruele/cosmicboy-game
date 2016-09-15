#include <stdio.h>
#include <allegro.h>
#include <allegro_primitives.h>
#include <allegro_image.h>

ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *events;
ALLEGRO_BITMAP *bouncer;
ALLEGRO_TIMER *timer;
ALLEGRO_COLOR orange,black,red;

//gentity flags
#define FL_GODMODE		0x00000001

//constants
#define SCREEN_W		800
#define SCREEN_H		600
#define FPS 			60.0
#define MAX_KEYS		5
#define MAX_ENTITIES	1000

enum MYKEYS {
   KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT,
   KEY_SHOOT
};

typedef struct gentity gentity_t;

//Game entity structure i.e ships, bolts and asteroids
struct gentity{
	bool			inuse;
	float 			pos_x;
	float 			pos_y;
	int 			width;
	int 			height;
	float 			speed;
	ALLEGRO_BITMAP  *sprite;
	float 			dir_x;
	float 			dir_y;
	int 			weapon;
	int 			fire_rate;
	int 			flags;
	gentity_t 		*parent;
	int 			next_think;
	int 			next_shoot;
	void 			(*think)(gentity_t *self);
	void			(*fire)(gentity_t *self);
	//void			(*die)(gentity_t *self);
	bool			is_bolt;
	int 			lives;
	int 			health;
	int 			damage;
	int 			count;
	int 			score;
};

bool redraw;
bool doexit;
bool game_over;
bool key[MAX_KEYS];
int num_entities;
int level_time;
int score;
int god_timer;
int spawnenemy_timer;
gentity_t *player;
gentity_t *g_entities[MAX_ENTITIES];


//g_display.c

int init_screen();
int destroy_screen();
void draw_entity(gentity_t *ent);
void erase_entity(gentity_t *ent);
void draw_entities();

//g_player.c

//int changeWeapon(int weapon);
int init_player();
int destroy_player();
void shoot(gentity_t *ent);
void revive();

//g_controls.c

int init_controls();
int pressed_keys();
int key_down(ALLEGRO_EVENT ev);
int key_up(ALLEGRO_EVENT ev);

//g_menu.c

int main_menu();
int game_over_screen();
int hud();

//g_level.c

int init_level();
gentity_t *spawn(gentity_t *ent);
void update_entities();
void destroy(gentity_t *ent);
void create_enemy();
