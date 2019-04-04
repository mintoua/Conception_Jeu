#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "background.c"
int main()
{
int v=0;
background b ;
SDL_Surface *screen ;
screen =SDL_SetVideoMode(878,583,0,SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (screen == NULL){
printf("Unable to set video mode: %s\n",SDL_GetError());
}
char pause ;
int done=1;
if (SDL_Init(SDL_INIT_VIDEO)!=0)
{printf("Unable t initialize SDL: %s\n" , SDL_GetError());
v=1;
}

 b =initialiser (b);
 afficher (b , screen) ;

pause=getchar();
SDL_FreeSurface(b.image); 
SDL_VideoQuit();
SDL_Quit ();


return (v); 
}




