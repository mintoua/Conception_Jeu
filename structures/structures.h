/* voilà quelques structures que j'ai pu resortir 
MINTOUA
*/

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

typedef struct
{
	SDL_Surface * image;
	SDL_Rect position;
	Mix_Music * music;
	TTF_Font *texte;
}background;

typedef struct 
{
	SDL_Surface * img_but;
	SDL_Rect pos_but;
	Mix_Music * son_but;
}button;

typedef struct
{
	SDL_Event evnt;
	char nom;
	SDL_Rect pos;
}entite_sec;

/*J'ai modifié la structure joueur ( Hero), en mettant que ce dont on a besoin pour le moment*/

typedef struct{
	SDL_Rect positionTimer;
	SDL_Surface *time;
	int timer;
}Timer;
typedef struct
{
	SDL_Rect positionInit;
	SDL_Rect positionMouv;
	SDL_Surface *perso;
	Timer T;
}Hero;

typedef struct
{
	int nbre_enig;
	background Tab_map[];
}level;

//L'énigme contient une variable réponse je pense que l'ajouter serait plus juste.

typedef struct
{
	SDL_Rect posEnigme;
	SDL_Surface *enigme;
	int reponse;
}Enigme;

#endif /* STRUCTURES_H_ */
