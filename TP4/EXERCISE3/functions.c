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


// Liberer
void libererArbre(arbre *T)
{
    arbre temp=*T;
    if(temp==NULL)
        return;
    if(temp->gauche!=NULL)
        libererArbre(&temp->gauche);
    if(temp->droit!=NULL)
        libererArbre(&temp->droit);
    free(temp);
    *T=NULL;
}


/* Implementation de la pile d'arbres*/

int estVidePile(pile_arbre P)
{
    if (P.longueur ==0)
        return 1;
    return 0;
}

void empiler(arbre T,pile_arbre * P)
{
    if(P->longueur==N)
    {
        printf("Pile vide.\n");
        return;
    }
    P->tete[P->longueur]=T;
    P->longueur+=1;
}

arbre depiler(pile_arbre * P)
{
    if(estVidePile(*P))
        return NULL;
    arbre T=P->tete[P->longueur-1];
    P->longueur-=1;
    return T;
}



//pour aficher nitre arbre
void affichagePrefixe(arbre T)
{
    if(T==NULL)
        return;
    pile_arbre P={NULL,0};
    arbre temp=T;
    empiler(T,&P);
    while(estVidePile(P)==0)
    {
        temp=depiler(&P);
        printf("%d\t",temp->cle);
        if(temp->droit!=NULL)
            empiler(temp->droit,&P);
        if(temp->gauche!=NULL)
            empiler(temp->gauche,&P);
    }
    return;
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
