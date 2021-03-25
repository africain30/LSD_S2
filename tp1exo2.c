#include<stdio.h>
#include<stdlib.h>
#include<time.h>


// cet algorithme a pour but de trouver la 3eme plus gande valeur (entier) dans un tableau;
int main ()
{
    int array[5];
int i=0;
    srand(time(0));
for (i=0;i<5;i++)
{
array[i]=rand();
}

    int j=0;
for (j = 0 ; j <5 ; j++)
    {
        printf("%d\n", array[j]);
    }
   
    int m1 = 2;
    int m2 = 1;
    int m3 = 0;
    for (i=0;i<5;i++)
    {
        if (array[i]>m1)
        {
            m1 = array[i];
        }
    }
    for (i=0;i<5;i++)
    {
        if (m1>array[i] && array[i]>m2)
        {
            m2 = array[i];
        }
    }
    for (i=0;i<5;i++)
    {
        if (m2>array[i] && array[i]>m3)
        {
           m3 = array[i];
        }
    }
    printf("( %d , %d , %d )\n",m1,m2,m3);
   
  return 0;
}


