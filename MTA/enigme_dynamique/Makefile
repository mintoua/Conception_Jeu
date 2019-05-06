
prog: random.o text.o enigme_dynamique.o main.o  
	gcc random.o text.o enigme_dynamique.o main.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
main.o: main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
text.o: text.c
	gcc -c text.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
enigme_dynamique.o: enigme_dynamique.c
	gcc -c enigme_dynamique.c -lSDL -lSDL_image -lSDL_ttf -g
random.o: random.c
	gcc -c random.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
