#include "ennemi.c"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

int main()
{char pause ;
int done =1 ;
	entite_sec e ;
	SDL_Surface * ecran;
	/*SDL_Surface *Surface_Ennemi;
	SDL_Rect pos_ennemi;*/
        SDL_Init(SDL_INIT_VIDEO);
        ecran=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	e = init_ennemi();
	
 afficher_ennemi( ecran,  e);
         SDL_Flip(ecran);
pause =getchar () ;
SDL_FreeSurface (e.surface );
SDL_FreeSurface (ecran);
SDL_Quit ;

return 0 ;
}

