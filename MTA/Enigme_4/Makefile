prog: random.o enigme.o text.o  jeu.o main.o  
	gcc random.o enigme.o text.o  jeu.o main.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
main.o: main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
jeu.o: jeu.c
	gcc -c jeu.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
text.o: text.c
	gcc -c text.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
enigme.o: enigme.c
	gcc -c enigme.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g 
random.o: random.c
	gcc -c random.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
