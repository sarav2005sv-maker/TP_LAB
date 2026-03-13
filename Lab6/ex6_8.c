#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int compar(const void* elem1,const void* elem2)
{
  const int* e1 = (int*)elem1;
  const int* e2 = (int*)elem2;
  if (*e1 < *e2) return -1;
  else
    {
      if (*e1 > *e2) return 1;
      else
	{
	  return 0;
	}
    }
 }

void sortare(int n,...)
{
  va_list va;
  va_start(va,n);
  int* a[n + 1];
  for(int i = 0; i < n; i++)
    {
      a[i] = va_arg(va,int*);
    }
  int v[n];
  for (int i = 0; i < n; i++)
    {
      v[i] = *(a[i]);
    }
  qsort(v,n,sizeof(int),compar);
  for (int i = 0; i < n; i++)
    {
      printf("%d ",v[i]);
    }
  printf("\n");
  va_end(va);
}

int main()
{
  int i = -8;
  int n = 2;
  int s = 12;
  int g = 7;
  sortare(4,&i,&n,&s,&g);
  return 0;
}
