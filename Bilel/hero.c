/**
* @file hero.c
* @date Apr 28, 2019
* @brief the creation of a hero
* @version 0.1
* @author Bilel Taktak
*/
#include"hero.h"

/**
* @brief intialize a Heros' position and initial caracteristics
* @param nomduf the name of the save file
* @param lineNumber the linenumber that will get read and transferred to the main characters' initial parameters
* @param A the Hero
* @return Nothing
*/
void initPerso(Hero *A,char nomduf[], int lineNumber){
	FILE *f=NULL;

	f=fopen(nomduf,"r");
	int i=0;

    if(f==NULL)
    {
    	fprintf(stderr,"Le fichier ne s'est pas ouvert correctement.\n");
    	exit(EXIT_FAILURE);
    }
    else
    {
    	while(!feof(f)){
            if(lineNumber==0){
                fscanf(f,"%hu %hu %hu %hu %d %d %d %d %u\n",&A->positionInit.x,&A->positionInit.y,&A->positionInit.w,&A->positionInit.h,&A->score,&A->frameNumber,&A->frameTimer,&A->T.timer,&Gameplay);
                break;         
            }
    		if(lineNumber!=0){
    			for(i=0;i<lineNumber;i++)
    				fscanf(f,"\n");
    		}
    		fscanf(f,"%hu %hu %hu %hu %d %d %d %d %u\n",&A->positionInit.x,&A->positionInit.y,&A->positionInit.w,&A->positionInit.h,&A->score,&A->frameNumber,&A->frameTimer,&A->T.timer,&Gameplay);

    	}
    }

	fclose(f);
}

/**
* @brief getting the heros' perfect pixels positions
* @param A the Hero
* @return Nothing
*/
void posPerso(Hero *A)
{

	// Position HAUT

	A->C[0].X=A->positionInit.x + A->positionInit.w / 2;
	A->C[0].Y=A->positionInit.y;

	// Position BAS

	A->C[1].X=A->positionInit.x + A->positionInit.w / 2;
	A->C[1].Y=A->positionInit.y + A->positionInit.h;

	// Position GAUCHE

	A->C[2].X=A->positionInit.x;
	A->C[2].Y=A->positionInit.y + A->positionInit.h / 2;

	// Position DROITE

	A->C[3].X= A->positionInit.x + A->positionInit.w;
	A->C[3].Y= A->positionInit.y + A->positionInit.h / 2;


}

/**
* @brief display the hero
* @param A the Hero
* @param ecran the screen
* @param direction the direction in which the character is going
* @return Nothing
*/
void affPerso(Hero *A, SDL_Surface *ecran,int direction){

	posPerso(&*A);

	SDL_Rect src;

    src.x = detective.frameNumber * PLAYER_WIDTH;
    src.y = 0;
    src.w = PLAYER_WIDTH;
    src.h = PLAYER_HEIGTH;

    // 0 si droite
    // 1 si gauche

	SDL_BlitSurface(A->perso[direction],&src,ecran,&A->positionInit);

}

/**
* @brief display the score
* @param A the heros' structure
* @param ecran the screen
* @return Nothing
*/
void affScore(Hero *A,SDL_Surface *ecran){

	SDL_BlitSurface(A->T.time,NULL,ecran,&A->T.positionTimer);
}

/**
* @brief freeing the heros' images
* @param A the heros' structure
* @return Nothing
*/
void freePerso(Hero *A){
	int i;
	for(i=0;i<2;i++)
		SDL_FreeSurface(A->perso[i]);
	
	SDL_FreeSurface(A->T.time);

}

/**
* @brief update the players' position
* @return Nothing
*/
void updatePlayer(void)
{

     if (input.left == 1)
    {
        detective.positionInit.x -= PLAYER_SPEED;
    }

    else if (input.right == 1)
    {
        detective.positionInit.x += PLAYER_SPEED;

    }

    else if (input.up == 1)
    {
        detective.positionInit.y -= PLAYER_SPEED;

    }

    else if (input.down == 1)
    {
        detective.positionInit.y += PLAYER_SPEED;

    }
   
}


