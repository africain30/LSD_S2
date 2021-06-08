#include "functions.h"
#include "functions.c"

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
