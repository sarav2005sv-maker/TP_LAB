#include <stdio.h>
#include <stdlib.h>

int m[100];
int k;
int n;
int v[100];
int s;

FILE* out;

int valid(int k)
{
  int sum = 0;
  for (int i = 0; i < k + 1; i++)
    {
      sum = sum + v[i] * m[i];
    }
   if (k >= n)
     {
       return 0;
     }
      if (sum > s)
     {
       return 0;
     }
   return 1;
}

int solutie(int k)
{
  int suma = 0;
  if (k != n-1)
    {
      return 0;
    }
  for (int i = 0; i < k+1; i++)
    {
      suma = suma + v[i]*m[i];
    }
  if (suma == s)
    {
      return 1;
    }
  else{
  return 0;
  }
}

void afisare()
{
  for (int i = 0; i < n; i++)
    {
      printf("%d*%d ",v[i],m[i]);
    }
  printf("\n");
}

void afisare_fisier()
{
 for (int i = 0; i < n; i++)
    {
      fprintf(out,"%d*%d ",v[i],m[i]);
    }
 fprintf(out,"\n");
}

void back(int k)
{
  for (int i = 0; i < 1000; i++)
    {
      v[k] = i;
      if (valid(k))
	{
	  if (solutie(k))
	    {
	      afisare();
	      afisare_fisier();
	    }
	  else
	    {
	      back(k + 1);
	    }
	}
    }
}

int main(int argc,char** argv)
{
  FILE* f = fopen(argv[1],"r");
  if (f == NULL)
    {
      fprintf(stderr,"err deschidere fisier in\n");
      exit(-1);
    }
  out = fopen(argv[2],"w");
  if (out == NULL)
    {
      fprintf(stderr,"err deschidere fisier out\n");
      exit(-1);
    }
  fscanf(f,"%d",&n);
  for (int i = 0; i < n; i++)
    {
      fscanf(f,"%d",&m[i]);
    }
  for (int i = 0; i < n; i++)
    {
      printf("%d ",m[i]);
    }
  printf("\n");
  if (scanf("%d",&s) != 1)
    {
      fprintf(stderr,"err citire suma\n");
      exit(-1);
    }
  back(0);
  fclose(f);
  fclose(out);
  return 0;
}
