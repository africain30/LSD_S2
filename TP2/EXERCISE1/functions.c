#include "functions.h"

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
