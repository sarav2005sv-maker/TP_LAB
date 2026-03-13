#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int crescator(int n,char tip,...)
{
  va_list va;
  va_start(va,tip);
  int comut = 1;
  switch(tip)
    {
    case 'd':
      {
	int prev = va_arg(va,int);
	for (int i = 1; i < n; i++)
	  {
	    int current = va_arg(va,int);
	    if (prev > current)
	      {
		comut = 0;
		break;
	      }
	  }
	break;
      }
    case 'f':
      {
	int prev = va_arg(va,double);
	for (int i = 1; i < n; i++)
	  {
	    int current = va_arg(va,double);
	    if (prev > current)
	      {
		comut = 0;
		break;
	      }
	  }
	break;
      }
    default:
      {
	printf("tipul specificat nu este valid\n");
	exit(-1);
	break;
      }
    }
  
  va_end(va);
  return comut;
}

int main()
{
  printf("%d\n",crescator(3,'d',-3,-2,1));
  printf("%d\n",crescator(3,'f',-3.2,2.4,7.0)); 
  return 0;
}
