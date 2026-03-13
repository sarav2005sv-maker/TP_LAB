#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

void input(const char *fmt,...)
{
  va_list va;
  va_start(va,fmt);

  int l = strlen(fmt);
  printf("%d\n",l);
  for (int i = 0; i < l-1; i++)
    {
      char prev = *(fmt + i);
      char next = *(fmt + i + 1);
      if (prev == '%')
	{
	  switch (next)
	    {
	    case 'd':
	      {
		int *aux = va_arg(va,int*);
		if (scanf("%d",aux) != 1)
		  {
		    fprintf(stderr,"err citire aux ca int\n");
		    exit(-1);
		  }
		getchar();
		break;
	      }
	    case 'f':
	      {
		double *aux = va_arg(va,double*);
		if (scanf("%lf",aux) != 1)
		  {
		     fprintf(stderr,"err citire aux ca double\n");
		     exit(-1);
		  }
		getchar();
		break;
	      }
	    case 'c':
	      {
		char *aux = va_arg(va,char*);
		if (scanf("%c",aux) != 1)
		  {
		    fprintf(stderr,"err citire aux ca char\n");
		    exit(-1);
		  }
		getchar();
		break;
	      }
	    default:
	      {
		fprintf(stderr,"tip invalid pt argument\n");
		break;
	      }
	    }
	}
      else
	{
	  if (i != 0)
	    {
	      char p = *(fmt + i - 1);
	  if (p != '%')
	    {
	      printf("%c",prev);
	    }
	  else
	    {
	      continue;
	    }
	    }
	  else
	    {
	      printf("%c",prev);
	    }
	}
    }
  printf("\n");
  va_end(va);
}

int main()
{
  int n;
  char ch;
  double f;
  input("n=%d ch=%c f =%f",&n,&ch,&f);
  return 0;
}
