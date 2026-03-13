#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc,char** argv)
{
  char flags[argc]; 
  int flagCount = 0;
  for (int i = 1; i < argc; i++)
    {
      if (argv[i][0] == '-')
	{
	  flags[flagCount++] = argv[i][1];
	}
      else
	{
	  for (int f = 0 ; f < flagCount; f++)
	    {
		
		  switch(flags[f])
		    {
		    case 'u':
		      {
			int l = strlen(argv[i]);
			for (int k = 0; k < l; k++)
			  {
			   argv[i][k] = toupper(argv[i][k]);
			  }
			break;
		      }
		    case 'f':
		      {
			int l = strlen(argv[i]);
			for (int k = 0; k < l; k++)
			  {
			    if (k == 0)
			      {
				argv[i][k] = toupper(argv[i][k]);
			      }
			    else
			      {
				argv[i][k] = tolower(argv[i][k]);
			      }
			  }
			break;
		      }
		    case 'r':
		      {
			int l = strlen(argv[i]);
			int start = 0, end = l - 1;
			while (start < end)
			 {
			  char temp = argv[i][start];
			  argv[i][start] = argv[i][end];
			  argv[i][end] = temp;
			  start++;
			  end--;
			 }

			break;
		      }
		    default:
		      {
			printf("am intrat in switch nu am facut nimic");
			break;
		      }
		    }
		
	    }
	  flagCount = 0;
	    }
	
    }
  for (int i = 1; i < argc; i++)
    {
      if (argv[i][0] != '-')
	{
	  int l = strlen(argv[i]);
	  for (int j = 0; j < l; j++)
	    {
	      printf("%c",argv[i][j]);
	    }
	  printf(" ");
	}
    }
  printf("\n");
  return 0;
}
