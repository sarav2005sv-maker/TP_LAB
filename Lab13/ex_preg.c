//toate nr de n cifre cu suma cifrelor x
#include <stdio.h>

int v[100];
int x;
int n;

int valid(int k)
{
  if (v[0] == 0)
    {
      return 0;
    }
  if (k > n)
    {
      return 0;
    }
  return 1;
}

int solutie(int k)
{
  int s = 0;
  if (k+1 == n)
    {   
      for (int i = 0; i < n; i++)
	{
	  s = s + v[i];
	}
      if (s == x)
	{
	  return 1;
	}
    }
  return 0;
}

void afisare()
{
  for (int i = 0; i < n; i++)
    {
      printf("%d",v[i]);
    }
  printf("\n");
}

void back(int k)
{
  for (int i = 0; i < 10; i++)
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
  scanf("%d",&x);
  back(0);
  return 0;
}
