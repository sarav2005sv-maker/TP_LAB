#include <stdio.h>
#include <stdlib.h>

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
  int a[n][n];
  int nr;
  //int v = 1;
  for (int m = 0; m < n; m++)
    {
      for (int s = 0; s < n; s++)
	{
	  a[m][s] = -2; //initializam toate distantele cu -2 pentru a putea verifica la citire ca citim o singura distanta pentru 2 orase, si nu o suprascriem
	}
    }
  int min;
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
	{
	  if (i == j)
	    {
	      a[i][j] = 0;
	    }
	  else
	    {
	      if (a[i][j] == -2) 
		{
		  if (scanf("%d",&nr) == 1)
		    {
		      if (i == 0 && j == 1)
			{
			  min = nr;
			}
		      a[i][j] = nr;
		      a[j][i] = nr; // distanta dintre orasele 0 si 1 este egale cu distanta dintre orasele                                     1 si 0; nu citim decat o singura data
		      if (a[i][j] < min)
			{
			  min = a[i][j];
			}
		    }
		}
	    }
	}
    }

  for (int k = 0; k < n; k++)
    {
      for (int l = 0; l < n; l++)
	{
	  printf("distanta dinte orasele %d si %d este: %d\n",k,l,a[k][l]);
	}
      printf("\n");
    }
  printf("distanta minima dintre 2 orase distincte este: %d\n",min);
  return 0;
}
