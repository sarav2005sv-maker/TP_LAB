#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  FILE* f = fopen(argv[1],"ab");
  if (f == NULL)
    {
      perror(NULL);
      exit(-1);
    }
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
  fseek(f,c,SEEK_SET);
  fwrite(array,sizeof(char),argc,f);
  free(array);
  fclose(f);
  return 0;
}
