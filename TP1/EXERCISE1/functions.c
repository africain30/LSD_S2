#include<functions.h>

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
  
