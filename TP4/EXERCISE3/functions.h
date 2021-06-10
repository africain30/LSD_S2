#include <stdio.h>
#include<stdlib.h>



/* La structure arbre*/
struct noeud
{
    int cle;
    struct noeud * gauche;
    struct noeud * droit;
};
typedef struct noeud noeud;
typedef struct noeud * arbre;




// Prototypes
int estVideArbre(arbre); /*Teste si un arbre est vide*/
int racine(arbre); /*Extrait la racine de l'arbre*/
arbre gauche(arbre);/*Extrait le sous-arbre gauche*/
arbre droit(arbre); /*Extrait le sous-arbre droit*/
arbre faireArbre(int, arbre,arbre); /* construit un arbre a partir d'une racine et de deux arbres */
void libererArbre(arbre *); /* libere la zone memoire*/
int hauteur(arbre); /* Calcule la hauteur d'un arbre */


//la fonction demandé dans l'exercice;
void equilibrer_Avl(int ,arbre * );



#define N 200

/* La pile d'arbres implementée à l'aide d'un tableau*/
struct pile_arbre
{
    arbre tete[N];
    unsigned longueur;
};
typedef struct pile_arbre pile_arbre;

// Prototypes
int estVidePile(pile_arbre);
void empiler(arbre,pile_arbre *);
arbre depiler(pile_arbre *);

