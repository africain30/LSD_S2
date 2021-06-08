#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct cellule
{
    int element;
    struct cellule * suivant;

};
typedef struct cellule cellule;
typedef struct cellule * liste;

///////// Prototypes ///////////////////
int testVide(liste);
unsigned longueur(liste);
void affichageListe(liste);
void ajoutDebut(int,liste *);
void liberer(liste);
liste creercellule(char n);
liste tabliste( char * tab );
int pallandrome(liste L );
/////////////////////////////////////////
