#include "functions.h"


//QUESTION 2
//valide
int maximum(int x , int y)
{
    if(x>y)
        return x;
    return y;
}

//valide
int height(tree A)
{
    if(A==NULL)
        return -1;
    if(A!=NULL && A->right==NULL && A->left==NULL)
        return 0;
    if(A!=NULL && (A->right==NULL || A->left==NULL))
        return 1;
    return 1 + maximum(height(A->left),height(A->right));
}

//QUESTION 3
//valide
int max_nodes(tree T){
    if(T==NULL){
        return 0;
    }
    int lmax = max_nodes(T->left);
    int rmax = max_nodes(T->right);
    return maximum(lmax , rmax) + 1 ;
}
//valide
int tree_diameter_2(tree T){
    if(T==NULL)
        return 0;
    int ltree = tree_diameter_2(T->left);
    int rtree = tree_diameter_2(T->right);
    return maximum(max_nodes(T->left) + max_nodes(T->right) + 1, maximum(ltree,rtree));
}






//QUESTION 4
//look at the end ot the file

//EXERCICE 2
//QUESTION 1

//valide
int max_tree(tree A)
{
    if(A==NULL)
        exit(EXIT_FAILURE);
    if(A->left==NULL && A->right==NULL)
        return A->data;
    if(A->left!=NULL && A->right==NULL)
        return maximum(A->data,A->left->data);
    if(A->left==NULL && A->right!=NULL)
        return maximum(A->data,A->right->data);
    if(A->left!=NULL && A->right!=NULL)
        return maximum(maximum(max_tree(A->left),max_tree(A->right)),A->data);
}
//valide
int minimum(int x ,int y)
{
    if(x<y)
        return x;
    return y; 
}
//valide
int min_tree(tree A)
{
    if(A==NULL)
        exit(EXIT_FAILURE);
    if(A->left==NULL && A->right==NULL)
        return A->data;
    if(A->left!=NULL && A->right==NULL)
        return minimum(A->data,A->left->data);
    if(A->left==NULL && A->right!=NULL)
        return minimum(A->data,A->right->data);
    if(A->left!=NULL && A->right!=NULL)
        return minimum(minimum(min_tree(A->left),min_tree(A->right)),A->data);
}



bool test_bst(tree A)
{
    if(A==NULL)
        return true;
    if(A!=NULL  &&  (A->data)<(A->right->data)  &&  (A->data)>(A->left->data))
        return true;
    return (test_bst(A->left) && test_bst(A->right) && max_tree(A->left)<(A->data) && min_tree(A->right)<(A->data) );
}



//valide
tree  make_tree(int x,tree T_1,tree T_2)
{
    tree T=(tree)malloc(sizeof(node));
    T->data=x;
    T->right=T_1;
    T->left=T_2;
    return T;
}

void insert_bst2(int val , tree *T)
{
    tree temp= *T;
    if(temp=NULL);
        temp=make_tree(val,NULL,NULL);
        return;
    while(temp->left!=NULL || temp->right!=NULL)
    {
        if(val< temp->data)
        {
            if(temp->left!=NULL)
                temp=temp->left;
            break;
        }
        if(temp->data <val)
        {
            if(temp->right !=NULL)
                temp=temp->right;
            break;
        }
    }
    tree temp1=NULL;
    temp1=make_tree(val,NULL,NULL);
    if(val< temp->data)
        temp->left=temp1;
        return;
    if(temp->data < val)
        temp->right=temp1;
        return;
}



void insert_bst(int val,tree * T)
{
    printf("%d\n",(*T)->data);
    if(*T==NULL)
    {
        
        return;
    }
    if(val==(*T)->data)
        return;
    if(val<(*T)->data && (*T)->left!=NULL)
    {
        insert_bst(val,&(*T)->left);
    }
    if(val>(*T)->data  && (*T)->right!=NULL)
    {
        insert_bst(val,&(*T)->right);
    }
}



//valide
tree search_bst(tree T, int x)
{
    if(T==NULL)
        return NULL;
    tree temp=T;
    pile_arbre P={NULL,0};
    while(estVidePile(P)==0 || temp!=NULL)
    {
        if(temp!=NULL)
        {
            empiler(temp,&P);
            temp=temp->left;
        }
        else
        {
            temp=depiler(&P);
            if(temp->data=x)
                return temp;
            temp=temp->right;
        }
    } 
    return NULL;       
}


//nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn
int max_depth(tree A)
{
    if(test_bst(A)==false)
        return -1;
    return height(A);
}


//valide
int tree_size(tree A)
{
    if (A==NULL)
        return 0;
    return tree_size(A->right) + tree_size(A->left) +1;
}


//Valide
int sum_leaf(tree T)
{
    if(T==NULL)
        return 0;
    tree temp=T;
    pile_arbre P={NULL,0};
	int i=0;
    while(estVidePile(P)==0 || temp!=NULL)
    {
        if(temp!=NULL)
        {
            empiler(temp,&P);
            temp=temp->left;
        }
        else
        {
            temp=depiler(&P);
            if(temp->left==NULL && temp->right==NULL)
                i+=temp->data;
            temp=temp->right;
        }
    } 
    return i;     
}
