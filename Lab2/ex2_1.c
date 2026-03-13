#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_NUME 20

typedef struct
{
  char* nume;
    int nota;
}rezultat;

void free_mem(rezultat *v,int n)
{
  for (int i = 0; i < n; i++)
    {
      free(v[i].nume);
    }
  free(v);
}

int compar1(const void *el1,const void *el2)
{
  const rezultat *e1 = (rezultat*)el1;
  const rezultat *e2 = (rezultat*)el2;
  if (e1->nota == e2->nota)
    {
      if (strcmp(e1->nume,e2->nume) > 0) return 1;
      else
	{
	  return -1;
	}
    }
  if (e1->nota > e2->nota) return -1;
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
  getchar();

  rezultat *v;
  v = malloc(n * sizeof(rezultat));
  if (v == NULL)
    {
      exit(-1);
    }

  for (int i = 0; i < n; i++)
    {
      v[i].nume = malloc(SIZE_NUME * sizeof(char));
      if (v[i].nume == NULL)
	{
	  fprintf(stderr,"eroare alocare");
	  exit(-1);
	}
      if (fgets(v[i].nume, SIZE_NUME, stdin) == NULL)
	{
	  exit(-1);
	}
     v[i].nume[strcspn(v[i].nume, "\n")] = '\0';
     if (scanf("%d",&v[i].nota) == EOF)
       {
	 fprintf(stderr,"eroare citire nota");
	 exit(-1);
       }
     getchar();
    }
   qsort(v,n,sizeof(rezultat),compar1);
   

    for (int i = 0; i < n; i++)
	{
	  printf("%s - %d\n",v[i].nume,v[i].nota);
	}

    free_mem(v,n);
  return 0;
}
