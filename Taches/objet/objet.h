/*La personne dont la tâche est concernée peut modifier comme il veut
les structure et même prototypes*/

#ifndef OBJET_H_
#define OBJET_H_
typedef struct
{
	SDL_Event evnt;
	char nom;
	SDL_Rect pos;
}entite_sec;

void init_objet(); 
void afficher_objet();
void deplacement_objet();


/*
à vous de faire vos parametre et type de retour
les concernés peuvent modifier
*/
#endif /* OBJET_H_ */
