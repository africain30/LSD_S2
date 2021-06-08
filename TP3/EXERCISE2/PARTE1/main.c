#include "functions.h"
#include "functions.c"



int main()
{
	liste l1 =NULL;
	liste l2 = NULL;
	int i = 0;
	for(i=0 ; i<5 ; i++)
	{
		int x = rand();
		ajoutDebut(x , &l1);
	}
	int j = 0;
	for(j=0 ; j<3 ; j++)
	{
		int y = rand();
		ajoutDebut(y , &l2);
	}
	affichageListe(l1);
	printf("________________________\n");
	affichageListe(l2);
	printf("________________________\n");
	liste L1=NULL;
	L1 = tri_insertion(l1);
	liste L2=NULL;
	L2 = tri_insertion(l2);
	affichageListe(L1);
	printf("________________________\n");
	affichageListe(L2);
	printf("________________________\n");
	liste t=NULL;
	t=merge2(L1,L2);
	affichageListe(t);
}
