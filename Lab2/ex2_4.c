#include <stdio.h>
#include <math.h>

void tabelare(double a,double b,int n,double(*pf)(double))
{
  int p;
  p = (b - a) / n;
  for (int i = 0; i <= n; i++)
    {
      int n = 0;
      n = pf(a + i * p);
      printf("%d ",n);
    }
  printf("\n");
}

int main(void)
{
  double a,b;
  int n;
  scanf("%lf",&a);
  scanf("%lf",&b);
  scanf("%d",&n);
  tabelare(a,b,n,fabs);
  return 0;
}
