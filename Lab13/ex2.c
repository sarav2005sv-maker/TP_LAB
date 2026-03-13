#include <stdio.h>

int v[100];
int m,n;

int valid(int k)
{
  if (k > m)
    {
      return 0;
    }
  for (int i = 1; i < k; i++)
    {
      if (v[k] == v[i])
	{
	  return 0;
	}
    }
  return 1;
}

int solutie(int k)
{
  if (k == m)
    {
       for (int i = 1; i < k; i++)
     {
      if (v[k] == v[i])
	{
	  return 0;
	}
     }
       return 1;
    }
  return 0;
}

void afisare(int m)
{
  for (int i = 1; i <= m; i++)
    {
      printf("%d ",v[i]);
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
	      afisare(m);
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
  scanf("%d",&n);
  scanf("%d",&m);
  back(1);
  return 0;
}
