/* Les structure et prototypes des fonctions ne sont pas definitives, 
vous pouvez les changer selons vos besoins
*/


#ifndef PERSO_H_
#define PERSO_H_


typedef struct
{
	SDL_Rect positionInit;
	SDL_Rect positionMouv;
	SDL_Surface *perso;
	Timer T;
}Hero;

void affPerso(Hero *A, SDL_Surface *ecran);
void affScore(Hero *A,SDL_Surface *ecran,int Time);
void freePerso(Hero *A);
#endif /* PERSO_H_ */
