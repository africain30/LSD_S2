#include "functions.h"
#include "functions.c"



int main()
{
        t_point D ;
	printf("il faut saisir les dimensions du tableau  \n");
        saisie(&D);
        affichage(D);
	char ** t;
	t = tab(D);
	tab_saisie( D , t );
	int i;
	int j;
	for(i=0 ; i<D.L ; i++)
	{	
		for(j=0 ; j<D.l ; j++)
		{
			printf(" %c ", t[i][j] );
		}
		printf("\n");
	}
	//vider(D , t);
	t_point P;
	printf("il faut saisir la position du point  \n");
	P = get_point();
	affichage(P);
	char c;
	char d;
	printf("il faut saisir la valeur que vous vouler chager \n");
	printf("il faut saisir la nouvel valeur \n");
        return 0;
}
