prog:main.o enigme_clavier.o
	gcc main.o enigme_clavier.o -o prog -lSDL -lSDL_image -lSDL_ttf -g
main.o:main.c
	gcc main.c -c -lSDL -lSDL_image -lSDL_ttf -g
enigme_clavier.o:enigme_clavier.c
	gcc enigme_clavier.c -c -lSDL -lSDL_image -lSDL_ttf -g
