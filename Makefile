CC = gcc
CFLAGS = -Wall -I.
DEPS = g_local.h
OBJ = main.o g_display.o g_player.o g_controls.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) -I"/usr/include/allegro5"

test:
	make build clean;
	./build;

build: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) -lallegro -lallegro_primitives -lallegro_image 

clean:
	rm -f $(OBJ)


