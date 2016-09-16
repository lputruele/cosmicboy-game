CC = gcc
CFLAGS = -Wall -I.
DEPS = g_local.h
OBJ = main.o g_display.o g_player.o g_controls.o g_menu.o g_level.o g_weapon.o g_animation.o g_enemy.o g_movement.o g_death.o g_sound.o


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) -I"/usr/include/allegro5"

test:
	make build clean;
	./build;

build: $(OBJ)
	gcc -o  $@ $^ $(CFLAGS) -lallegro -lallegro_primitives -lallegro_image  -lallegro_font -lallegro_ttf -lallegro_audio -lallegro_acodec

clean:
	rm -f $(OBJ)


