#include <stdio.h>

int v[100];
int n;

int valid(int k)
{
  if (k > n)
    {
      return 0;
    }
  if (k == 1) return 1;
  if (v[k - 1] - v[k] == 1 || v[k - 1] - v[k] == -1) return 1;
  return 0;
}

int solutie(int k)
{
  return k == n && v[k] == 0;
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
      if(valid(k))
	{
	  if (solutie(k))
	    {
	      afisare();
	    }
	  else
	    {
	      back(k + 1);
	    }
	  if (k == 1)break;
	}
    }
}

int main()
{
  scanf("%d",&n);
  back(1);
  return 0;
}
