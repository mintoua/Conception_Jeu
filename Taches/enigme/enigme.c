/* ici vous pouvez inclure certaines headers necessaire à l'écriture de vos fonctions
vous pouvez même créer d'autres si voulez ça dependra du necessiteux
*/

#include "enigme.h" //pour le moment

void init_enigme(enigme tab[],int nbrE,char nomFich)
{
int i;
backgroung imgE;
FILE * F = fopen(nomFich,"rb")
	for(i=0;i<nbrE;i++)
		{
			tab[i].posEnigme.x=0
			tab[i].posEnigme.y=0
			fread(&img.image,sizeof(background),1,F);
			tab[i].Senigme = img.image;
			tab[i].reponse = -1;
		}

}


//à vous d'ecriture les fonctions deja definit dans enigme.h
