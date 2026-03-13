#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv)
{
  double *v = malloc(argc * sizeof(int));
  if (v == NULL)
    {
      perror("eroare alocare\n");
      exit(-1);
    }
  int j = 0;
  for (int i = 1; i <= argc; i+=2)
    {
      int d = atoi(argv[i]);
      *(v + j) = d;
      printf("%.2f ",*(v + j));
      j++;
    }

  printf("\n");
  int m = 1;
  double rez = *(v);
  printf("%.2f ",rez);
  for (int k = 2; k < argc; k+=2)
    {
      switch (argv[k][0])
	{
	case 'a':
	{
	  rez = rez + *(v + m);
	  printf("add %.2f ",*(v + m));
	  m++;
	  break;
	}
    case 's':
      {
	rez = rez - *(v + m);
	printf("sub %.2f ",*(v + m));
	m++;
	break;
      }
    case 'm':
      {
	rez = rez * (*(v + m));
	printf("mul %.2f ",*(v + m));
	m++;
	break;
      }
    case 'd':
      {
	rez = rez / *(v + m);
	printf("div %.2f ",*(v + m));
	m++;
	break;
      }
	default:
	  {
	    printf("am intrat in switch nu am facut operatie\n");
	    break;
	  }
	}
    }
  printf("\n");
  printf("%.2f\n",rez);
  free(v);
  return 0;
}
