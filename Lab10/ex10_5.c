#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 30


char* fib(int n,char* sir1,char* sir2)
{
  int size = 1;
  char* sir = NULL;
    if(n == 0)
    {
	  size = size + strlen(sir1);
	  sir = realloc(sir,size * sizeof(char));
	    if (sir == NULL)
	      {
		fprintf(stderr,"err alocare sir\n");
		exit(-1);
	      }
      strcpy(sir,sir1);
      return sir;
    }
    if(n == 1)
    {
	  size = size + strlen(sir2);
	  sir = realloc(sir,size * sizeof(char));
	    if (sir == NULL)
	      {
		fprintf(stderr,"err alocare sir\n");
		exit(-1);
	      }
      strcpy(sir,sir2);
      return sir;
    }
    else
      {
	    size = size + strlen(sir1) + strlen(sir2);
	    sir = realloc(sir,size * sizeof(char));
	    if (sir == NULL)
	      {
		fprintf(stderr,"err alocare sir\n");
		exit(-1);
	      }
	return strcat(fib(n-1,sir1,sir2),fib(n-2,sir1,sir2));
      }
}

int main()
{
  char* string = malloc(200 * sizeof(char));
  if (string == NULL)
    {
      fprintf(stderr,"err alocare string\n");
      exit(-1);
    }
  int n;
  scanf("%d",&n);
  getchar();
  string = fib(n,"a","b");
  printf("%s",string);
  free(string);
  printf("\n");
  return 0;
}
