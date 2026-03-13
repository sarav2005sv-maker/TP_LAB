#include <stdio.h>
#include <stdlib.h>

int compar(const void *el1,const void *el2)
{
  const float *e1 = (float*)el1;
  const float *e2 = (float*)el2;
  if (*e1 == *e2) return 0;
  if (*e1 < *e2) return -1;
  return 1;
}

int main(void)
{
  int n;
  if (scanf("%d",&n) == EOF)
    {
      fprintf(stderr,"eroare citire");
      exit(-1);
    }
  float *v;
  if (n < 10 && n > 0)
    {
      v = malloc(n * sizeof(float));
	if (v == NULL)
	  {
	    exit(-1);
	  }
      for (int i = 0; i < n; i++)
	{
	  scanf("%f",&v[i]);
	}
    }

  qsort(v,n,sizeof(float),compar);
  for (int i = 0; i < n; i++)
	{
	  printf("%.2f ",v[i]);
	}
  printf("\n");

  float x;
  if (scanf("%f",&x) == EOF)
    {
      fprintf(stderr,"eroare citire");
      exit(-1);
    }
  int *ptr = (int*) bsearch(&x, v, n, sizeof(float), compar);
  if (ptr != NULL)
    {
      printf("Valoarea %.2f a fost gasita in array\n", x);
    }
  else
    {
      printf("Valoarea %.2f nu a fost gasita in array.\n", x);
    }

  free(v);
  return 0;
}
