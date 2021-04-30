/exercice3
//
#include<stdio.h>
#include<math.h>

int isprime(int n)
{
  if (n==1)
    return 1;
  if (n==0)
    return 10;
  if (n%2 == 0)
    return 0;
  int i;
    for (i=2 ; i< (n-1);i+2)
      {
        if (n%i == 0)
          return 0;
        else
          return 1;
      }
}




void getprime(int n)
{
  for(int i =2; i<=n; i++)
    {
      if (isprime(i)==1)
        printf("%d\n",i);
    }
}




int isprimeop(int n)
{
  int i=2;
  while(i<(sqrt((double)n)))
  {
    if (n%i == 0)
      return 0;
    else
      return 1;
    i++ ;
   }
}




void getprimeop(int n)
{
  for(int i =2; i<=n; i++)
  {
    if (isprimeop(i)==1)
      printf("%d\n",i);
  }
}


int main()
{
int n;
scanf("%d", &n);
int result3 = isprime(n);
printf("%d\n" , result3);
getprime(n);
int result5 = isprime(n);
printf("%d\n" , result5);
return 0;
}
