#include "gestion.h"

void initVie(vie *v)
{


v->image[0]=IMG_Load("vie0.png");
v->image[1]=IMG_Load("vie1.png");
v->image[2]=IMG_Load("vie2.png");
v->image[3]=IMG_Load("vie3.png");
v->image[4]=IMG_Load("vie4.png");
v->nbvie=3;
v->posvie.x=600;
v->posvie.y=0;

}

void affichevie(vie *v,SDL_Surface *ecran)
{
if (v->nbvie==3){
SDL_BlitSurface(v->image[3],NULL, ecran,&v->posvie);
}
if (v->nbvie==2){
SDL_BlitSurface(v->image[2],NULL, ecran,&v->posvie);
}

if (v->nbvie==1){
SDL_BlitSurface(v->image[1],NULL, ecran,&v->posvie);
}

if (v->nbvie==0){
SDL_BlitSurface(v->image[0],NULL, ecran,&v->posvie);
}

}

void initCoin(element coin , element coin1 , element coin2 ,element coin3)
{
	coin.image1=IMG_Load("coin.png");
	coin.poscoin.x=303;
	coin.poscoin.y=290;
        coin.on=1;
	coin1.image1=IMG_Load("coin1.png");
	coin1.poscoin.x=746;
	coin1.poscoin.y=280;
        coin1.on=1;
	coin2.image1=IMG_Load("coin2.png");
	coin2.poscoin.x=1174;
	coin2.poscoin.y=142;
	coin2.on=1;
        coin3.image1=IMG_Load("coin3.png");
	coin3.poscoin.x=2045;
	coin3.poscoin.y=148;
	coin3.on=1;
        
}

void AfficherCoin(element coin , element coin1 , element coin2 ,element coin3){

	if(coin.on==1 && coin1.on==1 && coin2.on==1 && coin3.on==1){
		SDL_BlitSurface(coin.image1,NULL,ecran,&coin.poscoin);
                SDL_BlitSurface(coin1.image1,NULL,ecran,&coin1.poscoin);
                SDL_BlitSurface(coin2.image1,NULL,ecran,&coin2.poscoin);
                SDL_BlitSurface(coin3.image1,NULL,ecran,&coin3.poscoin);
	}
}

int eatCoin(element coin , element coin1 , element coin2 ,element coin3,SDL_Rect posperso)
{
int s=0;
if( (posperso.x==coin.poscoin.x)&&(posperso.y==coin.poscoin.y)&& (coin.on==1)){
		coin.on = 0;
		s=10;
             SDL_BlitSurface(coin.image1,NULL,NULL,&coin.poscoin);
	}
if( (posperso.x==coin1.poscoin.x)&&(posperso.y==coin1.poscoin.y)&& (coin1.on==1)){
		coin1.on = 0;
		s+=10;
             SDL_BlitSurface(coin1.image1,NULL,NULL,&coin1.poscoin);
	}
if( (posperso.x==coin2.poscoin.x)&&(posperso.y==coin2.poscoin.y)&& (coin2.on==1)){
		coin2.on = 0;
		s+=10;
             SDL_BlitSurface(coin2.image1,NULL,NULL,&coin2.poscoin);
	}
if( (posperso.x==coin3.poscoin.x)&&(posperso.y==coin3.poscoin.y)&& (coin3.on==1)){
		coin3.on = 0;
		s+=10;
             SDL_BlitSurface(coin3.image1,NULL,NULL,&coin3.poscoin);
	}


return s;

}
void loadFont(TTF_Font *fon){
	font = TTF_OpenFont("PotLand.ttf", 35);
	if (font == NULL){
		printf("Failed to open Font : %s\n", TTF_GetError());
		exit(1);
	}
}

void closeFont(TTF_Font *font){
	if (font != NULL){
		TTF_CloseFont(font);
	}
}

void AfficheTexte(char *text,SDL_Rect postxt, TTF_Font *font,SDL_Surface *ecran)
{
	SDL_Surface *surface;
	SDL_Color couleur;

	couleur.r = 255;
	couleur.g = 0;
	couleur.b = 0;

	surface = TTF_RenderText_Blended(font, text, couleur);

	if (surface == NULL){
		printf("Couldn't create String %s: %s\n", text, SDL_GetError());

		return;
	}
	postxt.x = 200;
	postxt.y = 0;
	SDL_BlitSurface(surface, NULL, ecran, &postxt);
	SDL_FreeSurface(surface);



}

void gestVieScore(vie *v ,int collision, int enigme)
{

//if(collision)
	
// {
	if (enigme)
		score=eatCoin(coin, coin1, coin2, coin3, posperso)+50;
	else	 
		v->nbvie--;
	
}

void mort(vie *v,int *continuer)
{
	int countdown=150;

	if(v->nbvie==0){
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
		SDL_BlitSurface(v->image[4],NULL, ecran,&v->posvie);
		while(countdown>=0)
			countdown--;
		*continuer=0;
	}
}

void DrawScore(SDL_Rect postxt,SDL_Rect postxt2)
{

	char actualScore[10];
	AfficheTexte("Score", postxt, font, ecran);
	sprintf(actualScore,"%d",score);
	AfficheTexte(actualScore, postxt2, font, ecran);
}







