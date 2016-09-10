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
#define MAX_KEYS		4

bool redraw;
bool doexit;

enum MYKEYS {
   KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};
bool key[MAX_KEYS];

typedef struct gentity gentity_t;

struct gentity{
	float pos_x;
	float pos_y;
	int width;
	int height;
	float speed;
	ALLEGRO_BITMAP  *sprite;
};

gentity_t *player;

//g_display.c

int init_screen();
int destroy_screen();
void draw_entity(gentity_t *ent);
void erase_entity(gentity_t *ent);

//g_player.c

int init_player();
int destroy_player();

//g_controls.c

int init_controls();