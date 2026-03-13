#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n;
  if (scanf("%d",&n) == EOF)
    {
      fprintf(stderr,"eroare la citire");
      exit(-1);
    }
  int **a;
  a = (int**)malloc(n * sizeof(int *));
  if (a == NULL)
    {
      fprintf(stderr,"eroare malloc");
      exit(-1);
    }

  int i;
  for(i=0;i<n;i++)
    {
      a[i]=(int*)malloc(n*sizeof(int));
      if(a[i]==NULL)
	{
	  for(i--;i>=0;i--)	    
	    {
	      free(a[i]);
	    }
	      free(a); 
	      printf("memorie insuficienta\n");
	      exit(EXIT_FAILURE);
	}
    }

  for(int s=0;s<n;s++)
    {
      for(int d=0;d<n;d++)
	{
	  printf("a[%d][%d]=",s,d);scanf("%d",&a[s][d]);
	}
    } 

  int *v;
  int *g;
  int suma1 = 0;
  int suma2 = 0;
  v = malloc(n * sizeof(int));
  if (v == NULL)
    {
      fprintf(stderr,"eroare malloc");
      exit(-1);
    }
  
  g = malloc(n * sizeof(int));
  if (g == NULL)
    {
      fprintf(stderr,"eroare malloc");
      exit(-1);
    }
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
	{
	  suma1 = suma1 + a[i][j];
	  suma2 = suma2 + a[j][i];
	}
      *(v + i) = suma1;
      *(g + i) = suma2;
      suma1 = 0;
      suma2 = 0;
    }

  //afisare matrice
  for (int k = 0; k < n; k++)
    {
      for (int l = 0; l < n; l++)
	{
	  printf("%d ",a[k][l]);
	}
      printf("\n");
    }

  //afisare vector cu sumele de pe linii
  printf("sumele pe linii sunt: ");
  for (int h = 0; h < n; h++)
    {
      printf("%d ",*(v + h));
    }
  printf("\n");

  //afisare vector cu sumele de pe coloane
  printf("sumele pe coloane sunt: ");
   for (int h = 0; h < n; h++)
    {
      printf("%d ",*(g + h));
    }
   printf("\n");
   
  for(int i=0;i<n;i++)
    {
      free(a[i]);
    }
  free(a); 
  
  return 0;
}
