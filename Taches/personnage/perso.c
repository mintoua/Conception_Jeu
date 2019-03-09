/* ici vous pouvez inclure certaines headers necessaire à l'écriture de vos fonctions
vous pouvez même créer d'autres si voulez ça dependra du necessiteux
*/

#include "perso.h" //pour le moment


void initPerso(Hero * A)
{
A.positionInit.x=0;
A.positionInit.y=0;
A.Sperso = IMG_Load ("perso.png");
A.T = 0;
A.score = 0 ;
A.nbrvie = 0;

}

//à vous d'ecriture les fonctions deja definit dans perso.h
