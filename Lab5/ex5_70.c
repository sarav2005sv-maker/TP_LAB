#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  FILE* f = fopen(argv[1],"rb+");
  if (f == NULL)
    {
      perror(NULL);
      exit(-1);
    }
  printf("%d ",(argc-3) * sizeof(char));
  int* array = malloc((argc-3) * sizeof(int));
  if (array == NULL)
    {
      perror(NULL);
      exit(-1);
    }
  
  for (int i = 0; i < argc-3; i++)
    {
      int m;
      m = strtol(argv[i+3],NULL,16);
      *(array + i) = m;
    }

  int c = strtol(argv[2],NULL,16);

	 printf("%d ",c);
	 printf("%d ",ftell(f));
	 fseek(f,c,SEEK_SET);
	 printf("%d ",ftell(f));
  fwrite(array,sizeof(char),1,f);
  free(array);
  fclose(f);
  return 0;
}
