#include <stdio.h>

int v[100];
int n;

int valid(int k)
{
  if (k > n)
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
  if (k == n){
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

void afisare(void)
{
  for (int i = 1; i <= n; i++)
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
  scanf("%d",&n);
  back(1);
  return 0;
}
