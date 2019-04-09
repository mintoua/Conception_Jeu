#include"entete.h"

void initPerso(Hero *A, SDL_Surface *ecran,int posx,int posy){

	int i=0;

	for(i=0;i<2;i++)
		A->perso[i]=NULL;
	
	A->T.time=NULL;

        if(A->perso==NULL){
                fprintf(stderr,"Unable to load PNG: %s\n",SDL_GetError());
                exit(EXIT_FAILURE);
        }

	A->positionInit.x=posx;
	A->positionInit.y=posy;
	A->positionInit.w=PLAYER_WIDTH;
	A->positionInit.h=PLAYER_HEIGTH;
	A->score=0;


}

void loadImage(SDL_Surface* sprite,char file_name[])
{
	sprite=IMG_Load(file_name);
}

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

void affScore(Hero *A,SDL_Surface *ecran){

	SDL_BlitSurface(A->T.time,NULL,ecran,&A->T.positionTimer);
}

void freePerso(Hero *A){
	int i;
	for(i=0;i<2;i++)
		SDL_FreeSurface(A->perso[i]);
	
	SDL_FreeSurface(A->T.time);

}


