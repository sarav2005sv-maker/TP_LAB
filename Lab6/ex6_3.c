#include <stdio.h>
#include <stdarg.h>
#include <math.h>

void absN(int n,...)
{
  va_list va;
  va_start(va,n);
  for (int i = 0; i < n; i++)
    {
      double* n = va_arg(va,double*);
      *n = fabs(*n);
    }
  va_end(va);
}

int main()
{
  float x = -3;
  float b = -44;
  float y = 5;
  printf("%f %f %f\n",x,y,b);
  absN(3,&x,&y,&b);
  printf("%f %f %f\n",x,y,b);
  return 0;
}
