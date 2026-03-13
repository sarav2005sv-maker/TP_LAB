#include <stdio.h>
#include <stdlib.h>
#define SAMPLES 10

int main(void)
{
  int n;
  if (scanf("%d",&n) == EOF)
    {
      fprintf(stderr,"eroare citire");
      exit(-1);
    }

  if (n > 10)
    {
      printf("numarul trebuie sa fie maxim 10\n");
      exit(-1);
    }

  int** a;
  a = (int**)malloc(n * sizeof(int *));
  if (a == NULL)
    {
      fprintf(stderr,"eroare alocare\n");
      exit(-1);
    }
  for (int i = 0; i < n; i++)
    {
      a[i] = (int*)malloc(n * sizeof(int *));
      if (a[i] == NULL)
	{
	  for (i--;i >= 0;i--)
	    {
	      free(a[i]);
	    }
	  free(a);
	  fprintf(stderr,"eroare alocare");
	  exit(-1);
	}
    }

  int flag = 0;
  int nr = 0;
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
	{
	  int temp;
	  if (scanf("%d",&temp) == 1)
	    {
	      a[i][j] = temp;
	      nr++;
	      if (nr == n)
		{
		  n = n + SAMPLES;
		  a[i] = (int*)realloc(a[i],n * sizeof(int *));
		  if (a[i] == NULL)
		    {
		      for (i--;i >= 0;i--)
			{
			  free(a[i]);
			}
		      free(a);
		      fprintf(stderr,"eroare alocare");
		      exit(-1);
		    }
		}
	    }
	  else
	    if (feof(stdin))
	    {
	      flag = 1;
	      clearerr(stdin);
	      break;
	    }
	}

      printf("persoana %d are %d prieteni",i,nr);
      nr = 0;
      if (flag)
	{
	  flag = 0;
	  continue;
	}
    }

   for(int i=0;i<n;i++)
    {
      free(a[i]);
    }
  free(a); 
  
    return 0;
}
