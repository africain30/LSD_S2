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
