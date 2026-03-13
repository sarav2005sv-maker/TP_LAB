#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#define SIZE 10

char* concat(int n,...)
{
  va_list va;
  va_start(va,n);

  char* sir = NULL;
  int l = 0;
  for (int i = 0; i < n; i++)
    {
      char* temp = va_arg(va,char*);
      l = l + strlen(temp) + 1;
      sir = realloc(sir,l * sizeof(char));
      if (sir == NULL)
	{
	  perror("err realocare\n");
	  exit(-1);
	}
      if (i == 0)
	{
	  strcpy(sir,temp);
	}
      else
	{
	  strcat(sir," ");
	  strcat(sir,temp);
	}
    }
  printf("%s\n",sir);
  va_end(va);
  return sir;
}

int main()
{
  char* m;
  m = concat(3,"Ana","are","mere");
  free(m);
  return 0;
}
