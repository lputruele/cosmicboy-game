#include <stdio.h>
#include <allegro.h>
#include <allegro_primitives.h>
#include <allegro_image.h>

ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *events;
ALLEGRO_BITMAP *bouncer;
ALLEGRO_TIMER *timer;
ALLEGRO_COLOR orange,black,red;

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

struct gentity{
	bool			is_used;
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

};

bool redraw;
bool doexit;
bool key[MAX_KEYS];
int num_entities;
int level_time;
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
int shoot();

//g_controls.c

int init_controls();
int pressed_keys();
int key_down(ALLEGRO_EVENT ev);
int key_up(ALLEGRO_EVENT ev);

//g_menu.c

int main_menu();

//g_level.c

int init_level();
int spawn(gentity_t **ent);
void update_entities();