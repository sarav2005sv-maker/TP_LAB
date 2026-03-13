#include <stdio.h>
#include <stdlib.h>

int v[1000];
int k;
int n;

int valid(int k)
{
  int flag = 0;
  for (int i = 1; i < k; i++)
    {
      if (v[k] == v[i])
	{
	  flag = 1;
	}
    }
    if (k <= n && flag == 0)
    {
      return 1;
    }
  return 0;
}

int solutie(int k)
{
  if (k == n)
    {
      int mijloc;
	  mijloc = n/2 + 1;
	  for (int i = 1;i < mijloc; i++)
	    {
	      for (int j = i + 1; j <= mijloc; j++)
		{
		  if (v[i] < v[j])
		    {
		      return 0;
		    }
		}
	    }
	  for (int m = mijloc; m < n; m++)
	    {
	      for (int l = m + 1; l <= n; l++)
		{
		  if (v[m] > v[l])
		    {
		      return 0;
		    }
		}
	    }
	  return 1;
    }
  return 0;
}

void afisare()
{
  for(int i = 1; i <= n; i++)
    {
      printf("%d",v[i]);
    }
  printf("\n");
}

void back(int k)
{
  for (int i = 1; i <= n; i++)
    {
      v[k] = i;
      if (valid(k))
	{
	  if (solutie(k))
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
  back(1);
  return 0;
}
