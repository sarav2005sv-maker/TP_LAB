#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m;
    printf("introduceti nr de elemente ale matricei a (n):");
    scanf("%d", &n);
    printf("introduceti nr de elemente ale matricei b (m):");
    scanf("%d", &m);

    int **a = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++)
      {a[i] = (int *)malloc(n * sizeof(int));
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

    int **b = (int **)malloc(m * sizeof(int *));
    for(int i = 0; i < m; i++)
      {b[i] = (int *)malloc(m * sizeof(int));
    if (b[i] == NULL)
	{
	  for (i--;i >= 0;i--)
	    {
	      free(b[i]);
	    }
	  free(b);
	  fprintf(stderr,"eroare alocare");
	  exit(-1);
	}
      }

    printf("introduceti elementele matricei a:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("introduceti elementele matricei b:\n");
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &b[i][j]);

    int found = 0;

    for(int i = 0; i <= n - m; i++)
      {
        for(int j = 0; j <= n - m; j++)
	  {
            int match = 1;
            for(int k = 0; k < m; k++)
	      {
                for(int l = 0; l < m; l++)
		  {
                    if(a[i + k][j + l] != b[k][l])
		      {
                        match = 0;
                        break;
                      }
                  }
                if(!match) break;
              } 
            if(match)
	      {
                printf("Matricea mica apare in matricea mare la pozitia: (%d, %d)\n", i, j);
                found = 1;
              }
         }
    }

    if(!found)
        printf("Nu apare\n");

    for(int i = 0; i < n; i++)
        free(a[i]);
    free(a);

    for(int i = 0; i < m; i++)
        free(b[i]);
    free(b);

    return 0;
}

