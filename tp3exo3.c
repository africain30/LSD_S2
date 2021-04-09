//
//  liste_simple.c
//  
//
//  Created by CHARAF YOUSRI on 28/02/2021.
//


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


struct tableau
{
    unsigned taille;
    int *tete;
};
typedef struct tableau tableau;

                      
tableau creer(unsigned);
void affichageTableau(tableau);
void saisieTableau(tableau);
void liberer(tableau);
tableau concatener(tableau, tableau); // Concatenation de deux tableaux 
void triInsertion(tableau); // Le tableau lui même doit être trié 
tableau triBulles(tableau); // Le résultat du tri doit être mis dans un autre tableau

                        // Implementation 
tableau  creer_tableau(unsigned n)
{
    tableau T;
    T.taille=n;
    T.tete=(int *)malloc(n*sizeof(int));
    return(T);
}
//La procédure affichage

void affichageTableau(tableau T)
{
    
    if(T.tete == NULL)
    	printf("[]");
    else
    {
        unsigned n = T.taille;
        printf("[");
        for(int i=0;i<n-1;i++)
            printf("%d,", T.tete[i]);
        printf("%d]",T.tete[n-1]);
    }
    printf("\n");
    return;
}
					///////question 1
					
//La procédure saisie
void saisieTableau(tableau T)
{
    srand(time(0));
    if(T.tete==NULL)
        printf("Tableau vide !\n");
    else
    {
        for(int i=0;i<T.taille;i++)
            *(T.tete+i) = rand();
            //T.tete[i] = rand();
    }
    return;
}










					//////question 2

//LE procedure du tri insertion
void triInsertion(tableau T)
{
	for(int i=0 ; i< (T.taille-1) ; i++)
	{
		for(int j=0 ; i<j ; j++)
		{
			if(T.tete[i] < T.tete[j])
			{
				int p;
				p = T.tete[i];
				T.tete[i] = T.tete[j];
				T.tete[j] = p;
			}
		}
	}
	return;
}










						//////question 3							
//LE procedure du tri bulle
tableau triBulles(tableau T)
{
	for(int i=0 ;	i < (T.taille -2)  ; i++)
	{
		for(int j=0 ; j <  (T.taille -2 - i) ; j++)
		{
			int p;
			if(T.tete[j] > T.tete[j+1])
			{	p = T.tete[j];
				T.tete[j] = T.tete[j+1];
				T.tete[j+1]= p;
			}
		}
	}
	return T;
}

//la procedure de concatenation 
tableau concatener_tab(tableau T1,tableau T2)
{
	tableau S = creer_tableau(T1.taille + T2.taille);
	for(int i=0 ; i<T1.taille ; i++)
	{
			S.tete[i] = T1.tete[i];
	}
	for(int i=0 ; i<T2.taille ; i++)
	{
		S.tete[T1.taille +i] = T2.tete[i];
	}
	return S;				
}

tableau merge_tableau(tableau t1 ,tableau t2 )
{
	unsigned  n = t1.taille + t2.taille;
	tableau t3 = creer_tableau(n);
	t3 = concatener_tab(t1,t2);
	triBulles(t3);
	return t3;
}	

tableau merge(tableau t1 , tableau t2)
{
	unsigned n1 = t1.taille ; unsigned n2 = t2.taille ;
	if(n1 == 0 && n2 ==0 )
		return t1;
	if(n1 != 0 && n2 ==0 )
		return t1;
	if(n1 == 0 && n2 !=0 )
		return t2;
	tableau t3 = creer_tableau(n1 + n2);
	if(n1!=0 && n2!=0)
	{
		int i = 0 ; int j = 0 ; int k = 0 ;
		while(i<n1 && j<n2)
		{
			if(t1.tete[i] < t2.tete[j])
			{
				t3.tete[k] = t1.tete[i];
				k++ ; i++;
			}
			if(t1.tete[i] > t2.tete[j])
			{
				t3.tete[k] = t2.tete[j];
				k++ ; j++;
			}
			if(t1.tete[i] == t2.tete[j])
			{
				t3.tete[k] = t1.tete[i] ;
				i++ ; j++ ; k++ ;
			}
		}
		if(i<n1)
		{
			while(i<n1)
			{
				t3.tete[k] = t1.tete[i];
				i++ ; k++;
			}
		}
		if(j<n2)
		{
			while(j<n2)
			{
				t3.tete[k] = t1.tete[j];
				j++ ; k++;
			}
		}
		return t3;
	}
}
	

//La procédure liberer
void liberertableau(tableau T)
{
    if(T.tete!=NULL)
        free(T.tete);
    return;
}


int main()
{
	tableau t1 = creer_tableau(100);
	saisieTableau(t1);
	affichageTableau(t1);
	printf("------------------------------------------\n");
	tableau t2 = creer_tableau(150);
	saisieTableau(t2);
	affichageTableau(t2);
	printf("------------------------------------------\n");
	tableau T1 = creer_tableau(100);
	T1 =triBulles(t1);
	affichageTableau(T1);
	printf("------------------------------------------\n");
	tableau T2 = creer_tableau(150);
	T2 =triBulles(t2);
	affichageTableau(T2);
	printf("------------------------------------------\n");
	affichageTableau(merge_tableau(t1,t2));
	liberertableau(t1);
	liberertableau(t2);
	liberertableau(T1);
	liberertableau(T2);
	
		
}
	
