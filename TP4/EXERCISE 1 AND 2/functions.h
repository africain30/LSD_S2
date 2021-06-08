#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdio.h>

#define N 200

struct node
{
    int data;
    struct node * left;
    struct node* right;
};
typedef struct node node ;
typedef struct node * tree;



struct pile_arbre
{
    tree tete[N];
    unsigned longueur;
};
typedef struct pile_arbre pile_arbre;




int maximum(int, int);
int minimum(int,int);
int height(tree);
int max_nodes(tree);
int tree_diameter_2(tree);
int max_tree(tree);
int min_tree(tree);
bool test_bst(tree);
tree make_tree(int,tree,tree);
void insert_bst2(int,tree *);
void insert_bst(int,tree *);
tree search_bst(tree,int);
int tree_size(tree);
int sum_leaf(tree);



int estVidePile(pile_arbre);
void empiler(tree,pile_arbre);
tree depiler(pile_arbre *);

