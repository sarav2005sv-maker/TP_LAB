#include <stdio.h>
#include <stdlib.h>

int even(int n)
{
    return n % 2 == 0;
}

int* filter(int* v,int* n,int (*pf)(int))
{
  for (int i = 0; i < *n; i++)
    {
      if ((*pf)(v[i]) == 0)
      {
	for (int j = i; j < (*n-1); j++)
	  {
	    v[j] = v[j + 1];
	  }
	(*n)--;
	i = i - 1;
      }
    }
  return v;
}

int main(void)
{
  int n;
  printf("Introduceti nr elemente: ");
  if (scanf("%d",&n) == EOF)
    {
      fprintf(stderr,"eroare citire");
      exit(-1);
    }

  int *v;
  v = malloc(n * sizeof(int));
  if (v == NULL)
    {
      exit(-1);
    }
  for (int p = 0; p < n; p++)
    {
      if (scanf("%d",&v[p]) == EOF)
	{
	  fprintf(stderr,"eroare citire");
          exit(-1);
	}
    }
  int (*pf)(int);
  pf = &even;
  v = filter(v,&n,pf);
  printf("elementele care satisfac conditia sunt: ");
  for (int g = 0; g < n; g++)
    {
      printf("%d ",v[g]);
    }
  printf("\n");
  free(v);
  return 0;
}
