//suma cifrelor unui nr cu recursivitate
#include <stdio.h>

int suma(int n)
{
  if (n == 0)
    {
      return 0;
    }
  else
    {
      return n%10 + suma(n/10);
    }
}

int factorial(int n)
{
  if (n == 0)
    {
      return 1;
    }
  if (n == 1)
    {
      return 1;
    }
  else
    {
      return n * factorial(n - 1);
    }
}

int main()
{
  int n;
  scanf("%d",&n);
  //int m = suma(n);
  int m = factorial(n);
  printf("%d\n",m);
}
