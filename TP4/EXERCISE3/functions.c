#include "functions.h"


// Test à vide d'un arbre
int estVideArbre(arbre T)
{
    if(T==NULL)
        return 1;
    return 0;
}

// Racine
 int racine(arbre T)
{
    if(estVideArbre(T))
       exit(EXIT_FAILURE);
    return T->cle;
}


// Sous-arbre gauche
arbre gauche(arbre T)
{
    if(estVideArbre(T))
        return NULL;
    return T->gauche;
}

// Sous-arbre droit
arbre droit(arbre T)
{
    if(estVideArbre(T))
        return NULL;
    return T->droit;
}

// faireArbre

arbre faireArbre(int x,arbre T_1,arbre T_2)
{
    arbre T=(arbre)malloc(sizeof(noeud));
    T->cle=x;
    T->gauche=T_1;
    T->droit=T_2;
    return T;
}

//pour calculer la hauteur
int hauteur(arbre T)
{
    if(T==NULL)
        return -1;
    return 1+maximum(hauteur(gauche(T)),hauteur(droit(T)));
}





void rotationGauche(arbre *T)
{
    if(*T==NULL||(*T)->droit==NULL)
        return;
    arbre temp=(*T)->droit;
    (*T)->droit=temp->gauche;
    temp->gauche=*T;
    *T=temp;
    return;
}

void rotationDroite(arbre *T)
{
    if(*T==NULL||(*T)->gauche==NULL)
        return;
    arbre temp=(*T)->gauche;
    (*T)->gauche=temp->droit;
    temp->droit=*T;
    *T=temp;
    return;
}






void equilibrer_Avl(int val,arbre * T)
{
    if(hauteur(gauche(*T)) - hauteur(droit(*T))==-2)
    {
        if(hauteur(droit(droit(*T))) < hauteur(gauche(droit(*T))))
        {
            rotationDroite(&(*T)->droit);
            rotationGauche(T);
            return ;
        }
        else
        {
            rotationGauche(T);
            return;
        }
    }
    if(hauteur(gauche(*T)) - hauteur(droit(*T))==2)
    {
        if(hauteur(gauche(gauche(*T))) < hauteur(droit(gauche(*T))))
        {
            rotationGauche(&(*T)->gauche);
            rotationDroite(T);
            return ;
        }
        else
        {
            rotationDroite(T);
            return;
        }
    }
    return;
}
