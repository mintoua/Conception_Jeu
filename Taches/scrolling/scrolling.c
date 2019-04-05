#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "scrolling.h"

void scrolling (scorlling *scrol,SDL_Rect *positionpersonage )
{

	switch(scrol->mouvement_personnage)
	{

		case 1:
			if (scrol->posback.x<634)
                		scrol->posback.x=scrol->posback.x+50;
			if (((positionpersonage->x<450)||((scrol->posback.x>=634))&&(positionpersonage->x<1166)))
				positionpersonage->x=positionpersonage->x+50;
	
		break;
		case 2:
			if (scrol->posback.x>0)
                		scrol->posback.x=scrol->posback.x-50;
	    		if (((scrol->posback.x!=0)&&(positionpersonage->x>=150))||((scrol->posback.x==0)&&(positionpersonage->x>=50)))
				positionpersonage->x=positionpersonage->x-50;
		break;
		case 3:
			if (scrol->posback.y<1240)
                		scrol->posback.y=scrol->posback.y+50;
			if (((positionpersonage->y<300)||((scrol->posback.y>=1240))&&(positionpersonage->y<300)))
				positionpersonage->y=positionpersonage->y+50;
		break;
		case 4:
			if (scrol->posback.y>0)
                		scrol->posback.y=scrol->posback.y-50;
	    		if (((scrol->posback.y!=0)&&(positionpersonage->y>=150))||((scrol->posback.y==0)&&(positionpersonage->y>=50)))
				positionpersonage->y=positionpersonage->y-50;
		break;

	}

}




