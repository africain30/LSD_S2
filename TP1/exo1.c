//exercice 1
//
#include<stdio.h>
 

int recfib(int);
int fibo(int );
int isprime(int);
void getprime(int);
int isprimeop(int)

  
int recfib(int n)
{
  if (n==0)
    return 0;
  if (n==1)
    return 1;
  int m = recfib(n-1) +recfib(n-2);
  return m;
}



int fibo(int n)
{
  if (n==0)
    return 0;
  if (n==1)
    return 1;

  int a = 1;
  int b = 1;
  int c = 0;
  for (int i =2 ; i<n; i++)
  {
    c=a+b;
    a=b;
    b=c;
   }  
  return c;

int main()
{
  int n;
  scanf("%d", &n);
  // int result = recfib(n);
  // printf("%d\n" , result);
  // int result2 = fibo(n);
  // printf("%d\n" , result2);
  // int result3 = isprime(n);
  // printf("%d\n" , result3);
  // getprime(n);
  int result5 = isprime(n);
  printf("%d\n" , result5);
  return 0;
}
