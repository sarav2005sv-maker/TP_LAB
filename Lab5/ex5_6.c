#include <stdlib.h>
#include <stdio.h>
#define SIZE 100

int main(int argc, char** argv)
{
  if (argc < 3)
    {
      fprintf(stderr,"trebuie 2 argumente\n");
    }
  FILE* f1 = fopen(argv[1],"r");
   if (f1 == NULL)
    {
      perror("err deschidere fisier\n");
      exit(-1);
    }
  FILE* f2 = fopen(argv[2],"r");
   if (f2 == NULL)
    {
      perror("err deschidere fisier\n");
      exit(-1);
    }
   char* array1 = malloc(SIZE * sizeof(char));
   if (array1 == NULL)
    {
      perror(NULL);
      exit(-1);
    }
   char* array2 = malloc(SIZE * sizeof(char));
   if (array2 == NULL)
    {
      perror(NULL);
      exit(-1);
    }
   int nr1,nr2;
   while (((nr1 = fread(array1,sizeof(char),1,f1)) > 0) && ((nr2 = fread(array2,sizeof(char),1,f2)) > 0))
     {
       for (int i = 0; i < nr1; i++)
	 {	
	   if (array1[i] != array2[i])
	     {
	       int ind = ftell(f2);
	       printf("%d - %02x - %02x\n",ind,*(array1 + i),*(array2 + i));
	     }
	 }
      
     }
    free(array1);
    free(array2);
   fclose(f1);
   fclose(f2);
  return 0;
}
