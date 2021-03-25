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



t_liste creat_node(int element  )
{
    t_liste node1 = (t_liste)malloc(sizeof(node));
    node1 ->element = element;
    node1 ->next = NULL ;
    return node1 ;
}


t_liste add_node(int x , t_liste l)
{
    t_liste c = creat_node( x );
    if(l == NULL)
        l = c;
    else
    {
        t_liste temp = l;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = c ;
    }
    return l ;
}

t_liste arraytoliste(int*  tab , int n)
{
    t_liste c = creat_node(tab[0]);
    for(int i=1 ; i<n ; i++)
    {
        c = add_node(tab[i] , c );
    }
    return c;
}


void printliste(t_liste t)
{
    if(t = NULL)
    printf("[]");
    else
    {
        printf("[");
        t_liste temp = t;
        while (temp->next != NULL)
        {
            printf(" %d ," ,temp->element);
            temp = temp->next;
        }
        printf(" %d ]" ,temp->element);
    }
    return;
}


t_liste removenode( int n , t_liste L )
{
    
    t_liste t,s;
    s=L;
    t=L;
    if(L->next == NULL)
    	return L;    	
    int i = 0;
    while( s->next != NULL )
    {
	
	s = s->next;
	i++;
    }
    int j;
    j=i;
    i = 0 ;
    s=L;
    if(n<0 || n> j )
	printf(" :-(" );
    if(n>0 || n< j)
    {
	while(i<n)
	{	
		t = s;
		s = s->next;
		i++;
	}
	t->next = s->next;
	free(t);
	return L;
    }			  
    if(n == 0)
    {
    t_liste temp=L;
    L=L->next;
    free(temp);
    }

}


void free_node(t_list L){
    while(L!=NULL){
        t_list p=L;
        L=L->next;
        free(p);
    }
    return ;
}





int main(){
    t_list c;
    t_list* k=&c;
    int n,T[n],m;
    printf("Enter the desired array length: ");
    scanf("%d",&n);
    if(n>0){
        printf("Please start typing the array values:\n");
        for(int i=0;i<n;i++){
            scanf("%d",&T[i]);
        }
        c=arraytoliste(T,n);
        printlist(c);
        printf("Remove a node by typing it int address: ");
        scanf("%d",&m);
        removenode(k,m);
    }
    else{
        c=arraytoliste(T,n);
    }
    printliste(c);
    freenode(c);
    return 0;
}
















































