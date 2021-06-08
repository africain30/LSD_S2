#include "functions.h"

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






//j'ai realiser cette partie de l'exercice un mois aprés la premiere semaine, c'est pour cela j'ai changé de methode 
void trier_tableau(int arr[], int n){
    int s;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                s=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=s;
            }
        }
    }
    return ;
}

int NotDuplicates(int arr[], int n){
    int c=0,i=0;
    while(i<n){
        if(arr[i]!=arr[i+1]){
            c++;
            i++;
        }
        else{
            i++;
        }
    }
    return c;
}

int* removeDuplicates(int arr[],int n, int c){
    int* Arr=(int*)malloc(c*sizeof(int));
    int m=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=arr[i+1]){
            Arr[m]=arr[i];
            m+=1;
        }
    }
    return Arr;
}

int* mergeArray(int arr1[], int n1, int arr2[], int n2){
    int* Arr=(int*)malloc((n1+n2)*sizeof(int));
    for(int i=0;i<n1+n2;i++){
        if(i<n1)
            Arr[i]=arr1[i];
        else
            Arr[i]=arr2[i-n1];
    }
    return Arr;
}
