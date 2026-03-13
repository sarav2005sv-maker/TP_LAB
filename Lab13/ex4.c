#include <stdio.h>

int v[100];
int nr[100];
int n;

int valid(int k)
{
  if (k > n)
    {
      return 0;
    }
  for (int i = 1; i < k; i++)
    {
      if (v[k] == v[i] || v[k] < v[i])
	{
	  return 0;
	}
    }
  return 1;
}

int solutie(int k)
{
  for (int i = 1; i < k; i++)
    {
      if (v[k] == v[i] || v[k] < v[i])
	{
	  return 0;
	}
    }
  return 1;
}

void afisare(int k)
{
  for (int i = 1; i <= k; i++)
    {
      printf("%d ",v[i]);
    }
  printf("\n");
}

void back(int k)
{
  for (int i = 1; i <= n; i++)
    {
      v[k] = nr[i];
      if (valid(k))
	{
	  if (solutie(k))
	    {
	      afisare(k);
	      back(k + 1);
	    }
	}
    }
}

int main()
{
  scanf("%d",&n);
  for (int i = 1; i <= n; i++)
    {
      scanf("%d",&nr[i]);
    }
  for (int j = 1; j <= n; j++)
    {
      printf("%d ",nr[j]);
    }
  printf("\n");
  back(1);
  return 0;
}
