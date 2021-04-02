//
// tp_3
// created by CHARAF YOUSRI ON 02/04/21
//





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



int testVide(liste L)
{
    if(L==NULL)
        return 1;
    return 0;
}



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
            printf("%d, ",temp->element);
            temp=temp->suivant;
        }
        if(temp!=NULL)
            printf("%d",temp->element);
        printf("]\n");
    }
}


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


void ajoutFin(int x,liste * L)
{
    // Allocation de mémoire pour une nouvelle cellule
    liste C=(liste)malloc(sizeof(cellule));
    //Remplissage de la cellule
    C->element=x;
    C->suivant=NULL;
    // Acces à la fin de la liste L
    if(*L==NULL)
        *L=C;
    else
    {
        liste temp=*L;
        while(temp->suivant!=NULL)
            temp=temp->suivant;
        temp->suivant=C;
    }

}


void liberer(liste L)
{
    while(L!=NULL)
    {
        liste temp=L;
        L=L->suivant;
        free(temp);
    }
}



void inserer(liste * L , int x)
{
	if((*L) == NULL ) {
		ajoutDebut(x,L);
		return ;
	}
	liste temp = (*L);
	if(x < (temp->element) ){
			ajoutDebut(x,L);
			return;
		}
	while(temp->suivant != NULL)
	{
			
		if(x > (temp->element) && x < (temp->suivant->element)){
			liste c = (liste)malloc(sizeof(cellule));
			c -> element = x;
			c -> suivant = (temp)->suivant;
			temp->suivant = c;
			return ;
		}
		temp = temp->suivant;
	}
	ajoutFin(x,L);
	return ;
}


				
liste tri_insertion( liste L )
{
	liste c = NULL;
	liste temp = L;
	while(temp!= NULL)
	{
		inserer(&c , temp->element);
		temp = temp->suivant;
	}				
	return c;
}



liste concatener( liste L , liste  D)
{
	if(testVide(L) && testVide(D))
		return NULL;
	if(testVide(L)==0 && testVide(D))
		return L;
	if(testVide(L) && testVide(D)==0)
		return D;
	if(testVide(L)==0 && testVide(D)==0)
	{
		
		liste temp1 = L;
		while(temp1->suivant !=NULL)
		{
			temp1=temp1->suivant;
		}
		temp1->suivant = D;
		return L;
	}
}

liste concatener2(liste l1 , liste l2)
{
	liste c = NULL;
	liste temp = l1 ;
	while(temp!=NULL)
	{
		ajoutDebut( temp->element , &c );
		temp = temp->suivant;
	}
	temp = l2;
	while(temp!=NULL)
	{
		ajoutDebut( temp->element , &c );
		temp = temp->suivant;
	}
	liste c2 = NULL;
	while(c!=NULL)
	{
		ajoutDebut( c->element , &c2 );
		c = c->suivant;
	}
	return c2 ;
}


liste merge(liste L1,liste L2)
{
	liste temp1 = L1;
	liste temp2 = L2;
	liste t1 = NULL;
	while(temp2!=NULL)
	{
		inserer( &temp1 , temp2->element);
		temp2 = temp2->suivant;
	}
	liste c = temp1;
	return c;
}

liste merge2(liste L1,liste L2)
{
	liste l = NULL;
	l = concatener(L1,L2);
	liste c = NULL;
	c = tri_insertion( l );
	return c;
}
 int longueur(liste L )
 { 
 	liste temp = NULL;
 	int i=0;
 	while(temp!=NULL)
 	{	
 		i++;
 		temp = temp->suivant;
 	}
 	return i ; 
} 		

int  recherche(int x, liste l)
{
	if(testVide(l) ==1)
	{
		return 0;
	}
	liste temp = l;
	int n = longueur(l);
	//for(int i = 0 ; i<n ; i++ )
	while(temp->suivant != NULL)
	{
		if(temp->element == x)
		{
			return 1;
		}
		temp = temp->suivant;
	}
	return 0;
}

liste duplicat(liste L)
{
	if(testVide(L) == 1)
		return NULL;
	liste temp = L;
	liste c =NULL;
	while(temp!=NULL)
	{
		if(temp->element != temp->suivant->element )
			ajoutFin( temp->element ,  &c);
		temp =temp->suivant;
	}
	return c;

}




int main()
{
	liste l1 =NULL;
	liste l2 = NULL;
	int i = 0;
	for(i=0 ; i<5 ; i++)
	{
		int x = rand();
		ajoutDebut(x , &l1);
	}
	int j = 0;
	for(j=0 ; j<3 ; j++)
	{
		int y = rand();
		ajoutDebut(y , &l2);
	}
	affichageListe(l1);
	printf("________________________\n");
	affichageListe(l2);
	printf("________________________\n");
	liste L1=NULL;
	L1 = tri_insertion(l1);
	liste L2=NULL;
	L2 = tri_insertion(l2);
	affichageListe(L1);
	printf("________________________\n");
	affichageListe(L2);
	printf("________________________\n");
	liste t=NULL;
	t=merge2(L1,L2);
	affichageListe(t);
}
