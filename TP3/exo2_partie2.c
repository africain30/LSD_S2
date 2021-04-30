//
//  liste_simple.c
//  
//
//  Created by CHARAF YOUSRI on 28/02/2021.
//


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


struct tableau
{
    unsigned taille;
    int *tete;
};
typedef struct tableau tableau;

                      
tableau creer(unsigned);
void affichageTableau(tableau);
void saisieTableau(tableau);
void liberer(tableau);
tableau concatener(tableau, tableau); // Concatenation de deux tableaux 
void triInsertion(tableau); // Le tableau lui même doit être trié 
tableau triBulles(tableau); // Le résultat du tri doit être mis dans un autre tableau

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
