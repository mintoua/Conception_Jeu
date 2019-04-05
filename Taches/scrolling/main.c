#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "scrolling.h"

int main()
{
    SDL_Surface *ecran =NULL;
    SDL_Surface *image =NULL,*personage=NULL;
    SDL_Rect positionecran,positionpersonage;
   // char pause;
    int continuer =1;
    int curseur=1;
    int c=1;
    scorlling scrol;

    SDL_Event event;

    image =IMG_Load("Maison.png");
	personage=IMG_Load("perso.png");
    
   
    	positionecran.x=0;
    	positionecran.y=1240;
    	scrol.posback.x=0;
    	scrol.posback.y=0;
	scrol.posback.h=760;
	scrol.posback.w=1366;

    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(1366, 760, 32, SDL_HWSURFACE );
		positionpersonage.x=0;
    	        positionpersonage.y=315;



    while (continuer)
    {
		
    		
        SDL_BlitSurface(image,&(scrol.posback), ecran, &positionecran);
	SDL_BlitSurface(personage,NULL,ecran,&positionpersonage);
	
        
        SDL_Flip(ecran);
	 SDL_WaitEvent(&event);
	
		
				
       switch (event.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer=0;
                break;
            case SDLK_RIGHT:
		scrol.mouvement_personnage=1;
		scrolling(&scrol,&positionpersonage);
	
                break;
            case SDLK_LEFT:
		scrol.mouvement_personnage=2;
		scrolling(&scrol,&positionpersonage);
                break;
             case SDLK_UP :  
        scrol.mouvement_personnage=4;
        scrolling(&scrol,&positionpersonage);
                break;
                     case SDLK_DOWN  :
        scrol.mouvement_personnage=3;
        scrolling(&scrol,&positionpersonage);
                break;
            }
		
	}
	
    }
    SDL_FreeSurface(image);
    SDL_FreeSurface(personage);
 
    return 0;
}
