#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n;
  if (scanf("%d",&n) == EOF)
    {
      perror(NULL);
      exit(-1);
    }
  int *p;
  int a[n][n];
  int nr;
  for (p = &a[0][0]; p < &a[n-1][n]; p = p + 1)
    {
      if (scanf("%d",&nr) == EOF)
	{
	  perror(NULL);
	  exit(-1);
	}
      *p = nr;
    }

  int temp;
  
  for (int k = 0; k < n; k++)
    {
      for (int l = k + 1; l < n; l++)
	{
	  if (k != l)
	    {
	      temp = a[k][l];
	      a[k][l] = a[l][k];
	      a[l][k] = temp;
	    }
	}
    }
  
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
	{
	  printf("%d ",a[i][j]);
	}
      printf("\n");
    }
  
  return 0;
}
