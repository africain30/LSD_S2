#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct cellule
{
    int element;
    struct cellule * suivant;
};
typedef struct cellule cellule;
typedef struct cellule * liste;





//prototypes dess fonctions utilisees dans le code
int testVide(liste ); //pour voir si la fonction est vide ou pas;
int longueur(liste ); //calcule la longueur de la liste;
void affichageListe(liste); //pour afficher la liste
void ajoutDebut(int ,liste * ); //pour ajouter une nouvelle cellule au debut de la liste
void ajoutFin(int ,liste * ); //pour ajouter une nouvelle cellule au debut de la liste
void liberer(liste); //pour liberer la liste
void inserer(liste * , int ); //pour inserer une nouvelle cellule dans une liste tout en gardant l'ordre croisant 
liste concatener( liste , liste ); //pour concatener deux liste simplement chainnees(afin de l'utiliser dans la fonction merge)
liste concatener2(liste , liste); //une autre methode pour realiser la concatenation
liste merge(liste,liste ); //pour repondre a la 4eme quesion 
liste merge2(liste ,liste ); //une deuxiemme methode pour realiser le merge
int  recherche(int , liste ); //pour cherhcher si un element existe dans une liste ou pas
liste duplicat(liste ); //pour eliminer les duplicates 
