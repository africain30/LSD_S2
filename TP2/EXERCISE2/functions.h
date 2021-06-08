#include<stdio.h>
#include<stdlib.h>


//la declaration de la nouvelle stricture de donnnes
struct node
{
    int element  ;
    struct node * next ;

};
typedef struct node node; // pour modifier son nom d'appelle dans les autre fonction
typedef node* t_liste;



//declaration des fonctions a utiliser 
	t_liste creat_node(int); //pour creer une nouvelle cellule
	t_liste add_node(int  , t_liste); //ajouter une celloule qu'on vient de creer a une liste chainees
	t_liste arraytoliste(int* , int ); //pour convertir un tableau a une liste 
	void printliste(t_liste ); //pour afficher la liste
	t_liste removenode( int , t_liste) //pour pouvoire supprimer une cellule 
	void free_node(t_list L); //pour liberer la zone memoire reserveé lors de la creation de la cellule
