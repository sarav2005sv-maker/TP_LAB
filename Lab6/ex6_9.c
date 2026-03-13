#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv)
{
  float suma = 0.0;
  if (argc == 1)
    {
      printf("0\n");
    }
  else
    {
      for (int i = 1; i < argc; i++)
	{
	  float n = atof(argv[i]);
	  suma += n;
	}
      printf("%f\n",suma);
    }
  
  return 0;
}
