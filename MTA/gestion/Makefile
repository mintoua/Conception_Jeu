prog:*.h *.c
	gcc *.h *.c -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -lm  -o prog -g 
gestion.o:gestion.c
	gcc -c gestion.c -g
clean:
	rm -fr *.o
mrproper:clean
	rm -f prog
