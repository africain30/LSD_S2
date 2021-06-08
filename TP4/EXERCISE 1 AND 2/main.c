#include "functions.h"



int main()
{
    tree T1=NULL;
    T1=make_tree(1,NULL,NULL);
    tree T2=NULL;
    T2=make_tree(2,NULL,NULL);
    tree T=make_tree(0,T1,T2);
    tree T3=NULL;
    tree T4=NULL;
    T3=make_tree(0,NULL,T);
    T4=make_tree(2,T3,NULL);
    printf("the size of the tree T is %d\n",tree_size(T));
    printf("the depth of the tree T is %d\n",height(T));
    printf("the diameter of the tree T is %d\n",tree_diameter_2(T));
    printf("the minimum  of the tree T is %d\n",min_tree(T));
    printf("the maximum  of the tree T is %d\n",max_tree(T));
    insert_bst(3,&T);
    return 0;


  /*  tree T1=NULL;
    tree T2=NULL;
    T1=make_tree(3,NULL,NULL);
    T2=make_tree(7,NULL,NULL);
    tree T=make_tree(5,T1,T2);
    tree T3=NULL;
    tree T4=NULL;
    tree T5=make_tree(11,NULL,NULL);
    tree T6=make_tree(15,NULL,NULL);
    tree T7=make_tree(13,T5,T6);
    T3=make_tree(0,NULL,T);
    T4=make_tree(10,T3,T7);
    printf("the size of the tree T is %d\n",tree_size(T4));
    printf("the depth of the tree T is %d\n",height(T4));
    printf("the diameter of the tree T is %d\n",tree_diameter_2(T4));
    printf("the minimum  of the tree T is %d\n",min_tree(T4));
    printf("the maximum  of the tree T is %d\n",max_tree(T4));
    printf("the sum of the leafs is %d\n",sum_leaf(T4));
    //printf("the max  of the ldepths  is %d\n",max_depth(T4));
    insert_bst(3,&T4);
    printf("the maximum  of the tree T is %d\n",max_tree(T4));
    return 0;*/
}
