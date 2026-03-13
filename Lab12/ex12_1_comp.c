#include <stdio.h>
#include <stdlib.h>

int n,m;
int v[20];


int valid(int k)
{ 
  if (k > n)
    {
      return 1;
    }
  return 0;
}

int solutie(int k)
{
  int nr_m = 0;
  if (k == n && (v[1] != 0))
    {
      for (int i = 1; i <= n; i++)
	{
	  if (v[i] == 1)
	    {
	      nr_m++;
	    }
	}
      if (nr_m == m)
	{
	  return 0;
	}
    }
  return 1;
}

void afisare()
{
  for (int i = 1; i <= n; i++)
    {
      printf("%d",v[i]);
    }
  printf("\n");
}

void back(int k)
{
  for (int i = 0; i <= 9; i++)
    {
      v[k] = i;
      if (valid(k) == 0)
	{
	  if (solutie(k) == 0)
	    {
	      afisare();
	    }
	  else
	    {
	      back(k + 1);
	    }
	}
    }
}

int main()
{
  if (scanf("%d",&n) != 1)
    {
      fprintf(stderr,"err citire n\n");
      exit(-1);
    }
  if (scanf("%d",&m) != 1)
  {
      fprintf(stderr,"err citire m\n");
      exit(-1);
    }
  back(1);
  return 0;
}
