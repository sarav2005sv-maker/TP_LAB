#include <stdio.h>

int v[100];
int nr[100];
int n;
int sizeN;
int q;
int maxv;

int max(int x, int y)
{
  if (x > y)
    {
      return x;
    }
  return y;
}

int valid(int k)
{
  for (int i = 1; i < k; i++)
    {
      if (v[i] >= v[k])
	{
	  return 0;
	}
    }
  return 1;
}

int solutie(int k)
{
  return k == sizeN - q;
}

int vect2int(int* v,int k)
{
  int result = 0;
  for (int i = k; i >= 1; i--)
    {
      result = result * 10 +nr[v[i]];
    }
  return result;
}

void back(int k)
{
  for (int i = 0; i < sizeN; i++)
    {
      v[k] = i;
      if (valid(k))
	{
	  if (solutie(k))
	    {
	      int x = vect2int(v,k);
	      maxv = max(maxv,x);		
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
  int i = 0;
  maxv = 0;
  scanf("%d",&n);
  scanf("%d",&q);
  int aux = n;
  while(aux != 0)
    {
      nr[i] = aux%10;
      aux = aux/10;
      i++;
    }
  sizeN = i;
  back(1);
  printf("%d\n",maxv);
  return 0;
}
