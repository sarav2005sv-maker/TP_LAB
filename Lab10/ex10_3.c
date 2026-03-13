#include <stdio.h>

int comp(int a,int b)
{
  if (a > b)
    {
      return a;
    }
  else
    {
      return b;
    }
}

int cif_max(int n)
{
  if (n < 10)
    {
      return n;
    }
  else
    {
      return comp(n%10,cif_max(n/10));
    }
}

int main()
{
  int x = cif_max(87);
  printf("%d\n",x);
  return 0;
}
