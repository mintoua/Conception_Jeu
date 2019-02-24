/* voilà quelques structures que j'ai pas resortir 
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

typedef struct
{
	char nom[20]
	int vies;
	int score;
	SDL_Rect pos_j;
	entite_sec * tab_outil;
	
}joueur;

typedef struct
{
	int nbre_enig;
	background Tab_map[];
}level;

#endif /* STRUCTURES_H_ */
