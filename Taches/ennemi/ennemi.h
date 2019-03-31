/*La personne dont la tâche est concernée peut modifier comme il veut
les structure et même prototypes*/

#ifndef ENNEMI_H_
#define ENNEMI_H_
typedef struct
{
	SDL_Event evnt;
	char nom;
	SDL_Rect pos;
}entite_sec;

void init_ennemi(); 
void afficher_ennemi();
void deplacement_aleatoire();


/*
à vous de faire vos parametre et type de retour
les concernés peuvent modifier
*/
#endif /* ENNEMI_H_ */
