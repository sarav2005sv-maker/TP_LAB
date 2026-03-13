#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int length(const char* str)
{
  int i = 0,l = 0;
  while (*(str + i) != '\0')
    {
      l++;
      i++;
    }
  return l;
}

int vowels(const char* str)
{
  int i = 0;
  int vocale = 0;
  while (*(str + i) != '\0')
    {
      if (*(str + i) == 'a' || *(str + i) == 'e'|| *(str + i) == 'i' || *(str + i) == 'o' || *(str + i) == 'u')
	vocale++;
      if (*(str + i) == 'A' || *(str + i) == 'E'|| *(str + i) == 'I' || *(str + i) == 'O' || *(str + i) == 'U')
	vocale++;
      i++;
    }
  return vocale;
}

int count_upper(const char* str)
{
  int majuscule = 0;
  int i = 0;
  while (*(str + i) != '\0')
    {
      for (char j = 'A'; j <= 'Z'; j++)
	{
	  //printf("*(str + %d) = %c\n",i,*(str + i));
	  if (*(str + i) == j)
	    {
	      majuscule++;
	    }
	  
	  else
	    {
	      continue;
	    }
	}
      i++;
    }
  return majuscule;
}

int diferenta(const char* str)
{
  int dif;
  int lungime = length(str);
  dif = *(str) - *(str + lungime - 1);
  return dif;
}

int main(int argc, char** argv)
{
   int (*pf[4])(const char*);
   pf[0] = &length;
   pf[1] = &vowels;
   pf[2] = &count_upper;
   pf[3] = &diferenta;
   for (int i = 0; i < argc - 1; i++)
     {
       for (int j = 0; j < 4; j++)
	 {
	   int nr;
	   nr = pf[j](argv[i + 1]);
	   printf("%d ",nr);
	 }
       printf("\n");
     }
   
  return 0;
}
