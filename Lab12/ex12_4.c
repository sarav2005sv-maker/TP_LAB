#include <stdio.h>
#include <stdlib.h>

/*
  alb - 0
  galben - 1
  rosu - 2
  verde - 3
  albastru - 4
  negru - 5 
 */

int k;
int v[1000];

int valid(int k)
{
  int flag = 0;
  for (int i = 0; i < k; i++)
    {
      if (v[k] == v[i])
	{
	  flag = 1;
	}
    }
  if (k <= 2 && flag != 1)
    {
      return 1;
    }
  return 0;
}

int solutie(int k)
{
  if (k == 2)
    {
      if (v[1] == 1 || v[1] == 3)
	{
	  return 1;
	}
    }
  return 0;
}
void afisare()
{
  for (int i = 0; i < 3; i++)
    { 
      switch(v[i]){
      case(0):
	{
	  if (i == 2)
	    {
	      printf("alb\n");
	    }
	  else
	    {
	      printf("alb - ");
	    }
	  break;
	}
      case(1):
	{
	  if (i == 2)
	    {
	      printf("galben\n");
	    }
	  else
	    {
	      printf("galben - ");
	    }
	  break;
	}
	case(2):
	{
	  if (i == 2)
	    {
	      printf("rosu\n");
	    }
	  else
	    {
	      printf("rosu - ");
	    }
	  break;
	}
	case(3):
	{
	  if (i == 2)
	    {
	      printf("verde\n");
	    }
	  else
	    {
	      printf("verde - ");
	    }
	  break;
	}
	case(4):
	{
	  if (i == 2)
	    {
	      printf("albastru\n");
	    }
	  else
	    {
	      printf("albastru - ");
	    }
	  break;
	}
	case(5):
	{
	  if (i == 2)
	    {
	      printf("negru\n");
	    }
	  else
	    {
	      printf("negru - ");
	    }
	  break;
	}
	} 
    }
}

void back(int k)
{
  for (int i = 0; i < 6; i++)
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
  back(0);
  return 0;
}
