//
//TP2
//ALGO2
//

#include<stdio.h>
#include<stdlib.h>

struct t_point
{
        int L;
        int l;
};
typedef struct t_point t_point;

//declaration de la nouvelle stricture de donnees
	void saisie(t_point *);  //pour pouvoire saisir dans la nouvelle stricture de donnees;
	void affichage(t_point );  //pour pouvoire afficher la  nouvelle stricture de donnees;
	char ** tab(t_point );  //pour reserver une zone memoire pour le nouveau tableau;
	void vider(t_point ,char** ); // pour vider la zone memoire a la fin de l'execution du code ;
	char **  tab_saisie(t_point ,char ** ); //pour le saisie dans le nouveau tableau;
	t_point get_point();  //pour retenir la position du point dont on veut :-) ;
	void flood_fill(char**  , t_point  , t_point  , char  , char  ); // la fonction la plus importante de l'exercice(txa rahha le but diallo nabek);




void saisie(t_point * p)
{
        scanf("%d%d",&p->L,&p->l);
        return;
}


void affichage(t_point p)
{
        printf("( %d , %d )\n",p.L,p.l);
        return;
}



char ** tab(t_point D)
{
        char **t;
        t = malloc(sizeof(char *) * D.L);
	int i = 0 ;
        while(i <= D.L)
        {
                t[i] = malloc(sizeof(char) * D.l);
                i++;
        }
	return t ;
}

void vider(t_point t,char** tab)
{
        int i = 0;
        while(i < t.L)
                free(tab[i]);
                i++;
        free(tab);
	return;
}

char **  tab_saisie(t_point T,char ** p)
{
        for(int i = 0 ;i < T.L ; i++)
        {
                for(int j=0 ; j<T.l ; j++)
                        scanf(" %c" , &p[i][j]);
        }
	return p;
}


t_point get_point()
{
        t_point T;
        saisie(&T);
        return T;
}


void flood_fill(char** tab , t_point D , t_point P , char c , char d )
{
	if(P.L > D.L || P.l> D.l ||   P.L<0 || P.l<0 )
		return ;
	if(tab[P.l][P.L]!= c)
		return;
 
	else   //(tab[P.l][P.L]== c)	
	{	
		tab[P.l][P.L] = d ;
		flood_fill(tab , D ,(t_point ){(P.L+1),(P.l)} , c , d );
		flood_fill(tab , D ,(t_point ){(P.L-1),(P.l)} , c , d );
		flood_fill(tab , D ,(t_point ){(P.L),(P.l+1)} , c , d );
		flood_fill(tab , D ,(t_point ){(P.L),(P.l-1)} , c , d );
	}
}




int main()
{
        t_point D ;
	printf("il faut saisir les dimensions du tableau  \n");
        saisie(&D);
        affichage(D);
	char ** t;
	t = tab(D);
	tab_saisie( D , t );
	int i;
	int j;
	for(i=0 ; i<D.L ; i++)
	{	
		for(j=0 ; j<D.l ; j++)
		{
			printf(" %c ", t[i][j] );
		}
		printf("\n");
	}
	//vider(D , t);
	t_point P;
	printf("il faut saisir la position du point  \n");
	P = get_point();
	affichage(P);
	char c;
	char d;
	printf("il faut saisir la valeur que vous vouler chager \n");
	printf("il faut saisir la nouvel valeur \n");
        return 0;
}
