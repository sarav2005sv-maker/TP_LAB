#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#define SIZE 16

int main(int argc, char** argv)
{
  FILE* f = fopen(argv[1],"rb");
  if (f == NULL)
    {
      perror("err deschidere fisier\n");
      exit(-1);
    }
  char* array = malloc(SIZE * sizeof(char));
  if (array == NULL)
    {
      perror("err alocare array\n");
      exit(-1);
    }
  int nr;
  int ind;
  while ((nr = fread(array,sizeof(char),SIZE,f)) > 0)
    {
      ind = ftell(f);
      printf("%08x   ",ind-16);
      for (int i = 0; i < nr; i++)
	{
	  printf("%02x ",(unsigned char)*(array+i));
	}
      printf("%*s",30,"");
      for (int j = 0; j < nr; j++)
	{
	  if ((*(array + j)) >= 32 && *(array + j) <= 127)
	    {
	      printf("%c ",*(array + j));
	    }
	   else
	    {
	      printf(".");
	    }
	} 
      printf("\n");
    }
  printf("\n");
  fclose(f);
  free(array);
  return 0;
}
