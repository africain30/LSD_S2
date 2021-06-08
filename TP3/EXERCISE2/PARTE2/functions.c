#include "functions.h"

// Implementation 
tableau  creer_tableau(unsigned n)
{
    tableau T;
    T.taille=n;
    T.tete=(int *)malloc(n*sizeof(int));
    return(T);
}
//La procédure affichage

void affichageTableau(tableau T)
{
    
    if(T.tete == NULL)
    	printf("[]");
    else
    {
        unsigned n = T.taille;
        printf("[");
        for(int i=0;i<n-1;i++)
            printf("%d,", T.tete[i]);
        printf("%d]",T.tete[n-1]);
    }
    printf("\n");
    return;
}
					///////question 1
					
//La procédure saisie
void saisieTableau(tableau T)
{
    srand(time(0));
    if(T.tete==NULL)
        printf("Tableau vide !\n");
    else
    {
        for(int i=0;i<T.taille;i++)
            *(T.tete+i) = rand();
            //T.tete[i] = rand();
    }
    return;
}
