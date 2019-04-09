prog:*.h *.c
	gcc *.h *.c -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -lm  -o prog -g
main.o:main.c
	gcc -c main.c -g
affPerso.o:affPerso.c
	gcc -c affPerso.c -g
affEnigme.o:affEnigme.c
	gcc -c affEnigme.c -g
countdown.o:countdown.c
	gcc -c countdown.c -g
animation.o:animation.c
	gcc -c animation.c -g
clean:
	rm -fr *.o
mrproper:clean
	rm -f prog
