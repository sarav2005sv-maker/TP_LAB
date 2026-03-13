#include <stdio.h>

double f1(int x)
{
  return (x*x*x + 4) / (x*x + 5);
}

double f2(int x)
{
  return x + 10;
}

double f3(int x)
{
  return 2*x*x - 1;
}


void tabelare(int a, int b, int n, double(*pf)(int))
{
  int p;
   p = (b - a) / n;
  for (int i = 0; i <= n; i++)
    {
      int n = 0;
      n = pf(a + i * p);
      printf("%5d ",n);
    }
  printf("\n");
}

int main(void)
{
  int a,b;
  int n;
  scanf("%d",&a);
  scanf("%d",&b);
  scanf("%d",&n);
  
  double (*pf[3])(const int);
  pf[0] = &f1;
  pf[1] = &f2;
  pf[2] = &f3;

  for (int i = 0; i < 3; i++)
    {
      tabelare(a,b,n,pf[i]);
    }
  return 0;
}
