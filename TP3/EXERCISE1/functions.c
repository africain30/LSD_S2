#include "functions.h"



// Test d'une liste vide.
int testVide(liste L)
{
    if(L==NULL)
        return 1;
    return 0;
}

// Affichange d'une liste
void affichageListe(liste L)
{
    if(L==NULL)
        printf("[ ]");
    else
    {
        printf("[");
        liste temp=L;
        while(temp->suivant!=NULL)
        {
            printf("%c, ",temp->element);
            temp=temp->suivant;
        }
        if(temp!=NULL)
            printf("%c",temp->element);
        printf("]\n");
    }
}

// Ajout au début d'une liste.
void ajoutDebut(int x,liste * L)
{
    // Allocation de mémoire pour une nouvelle cellule
    cellule * C=(cellule *)malloc(sizeof(cellule));
    //Remplissage de la cellule
    C->element=x;
    C->suivant=*L;
    // Ajout de la cellule au début de la liste
    *L=C;
    return;
}


// destruction d'une liste
void liberer(liste L)
{
    while(L!=NULL)
    {
        liste temp=L;
        L=L->suivant;
        free(temp);
    }
}

//la fonction qui convertie les tableau a une liste
liste creercellule(char n)
{
    liste node1 = (liste)malloc(sizeof(cellule));
    node1 ->element = n;
    node1 ->suivant = NULL ;
    return node1 ;
}

// question 2 
liste tabliste( char * tab )
{
	liste c = creercellule(tab[0]);
	int n = strlen(tab);
	for(int i=1 ; i<n ; i++)
		ajoutFin(tab[i] , &c);
	return c;
}


int pallandrome(liste L )
{
	if(L==NULL)
		return 0 ;
	liste temp = L;
	liste c = NULL;
	while(temp!=NULL)
	{
		ajoutDebut(temp->element , &c);
		temp = temp->suivant ;
	}
	temp = L;
	while(temp!=NULL)
	{
		if(temp->element != c->element)
			return 0;
		temp = temp->suivant;
		c = c->suivant;
	}
	return 1 ;
}
