#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv)
{
  if (argc < 2)
    {
      perror("trebuie 2 argumente: ");
      exit(-1);
    }
  FILE* f_out = fopen(argv[1],"r+b");
  setbuf(f_out,NULL);
  if (f_out == NULL)
    {
      perror("eroare deschidere fisier: ");
      exit(-1);
    }
  
  int m,n;
  if (scanf("%d",&m) == EOF)
    {
      perror("eroare citire m");
      exit(-1);
    }
  int val,val1,val2;
  val = fwrite(&m,sizeof(int),1,f_out);
  if (val != 1)
    {
      perror("eroare scriere: ");
      exit(-1);
    }
  if (scanf("%d",&n) == EOF)
    {
      perror("eroare citire: ");
      exit(-1);
    }
  val1 = fwrite(&n,sizeof(int),1,f_out);
  if (val1 != 1)
    {
      perror("eroare scriere: ");
      exit(-1);
    }
  int a[m][n];
  for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
	{
	  if (scanf("%d",&a[i][j]) == EOF)
	    {
	      perror("eroare citire elemente a[i][j] ");
	      exit(-1);
	    }
	}
    }
  
  val2 = fwrite(a,sizeof(int),m * n,f_out);
  if (val2 != m*n)
    {
      perror("eroare scriere: ");
      exit(-1);
    }
  int** b;
  b = (int**)malloc(m * sizeof(int*));
  if (b == NULL)
    {
      perror("eroare alocare matrice ");
      exit(-1);
    }
  for(int i = 0; i < m; i++)
      {b[i] = (int *)malloc(n * sizeof(int));
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
  fseek(f_out,2 * sizeof(int),SEEK_SET);
  for (int i = 0; i < m; i++)
    {
      val = fread(b[i],sizeof(int),n,f_out);
      if (val != n)
    {
      perror("eroare scriere: ");
      exit(-1);
    }
    }

  printf("matricea este: \n");
  for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
	{
	  printf("%d ",b[i][j]);
	}
      printf("\n");
    }
  for(int i=0;i<m;i++)
    {
      free(b[i]);
    }
  free(b);
  int h;
  if ((h = fclose(f_out)) != 0)
  {
    perror("eroare inchidere fisier \n");
    exit(-1);
  }
  return 0;
} 
