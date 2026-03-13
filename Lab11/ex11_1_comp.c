#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
  int x;
  int y;
}punct;

double distanta(int x1, int y1, int x2, int y2)
{
  return sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
}

int main(void)
{
  int n;
  if (scanf("%d",&n) != 1)
    {
      fprintf(stderr,"err citire n\n");
      exit(-1);
    }
  punct* array = (punct*)malloc(n * sizeof(punct));
  if (array == NULL)
    {
      fprintf(stderr,"err alocare array\n");
      exit(-1);
    };
  for (int i = 0; i < n; i++)
    {
      int aux1,aux2;
      scanf("%d",&aux1);
      array[i].x = aux1;
      scanf("%d",&aux2);
      array[i].y = aux2;
    }
  for (int i = 0; i < n; i++)
    {
      printf("%d - %d\n",array[i].x,array[i].y);
    }
  printf("ordinea pct este:\n");
  punct* traseu = (punct*)malloc(n * sizeof(punct));
  if (traseu == NULL)
    {
      fprintf(stderr,"err alocare traseu\n");
      exit(-1);
    }
  double dist_min;
  int exista = 0;
  for (int i = 0; i < n; i++)
    {
      if (i == 0)
	{
	  for (int j = 0; j < n; j++)
	    {
	      if (j == 0)
		{
		  double d = distanta(0,0,array[j].x,array[j].y);
	          dist_min = d;
		  traseu[i].x = array[j].x;
		  traseu[i].y = array[j].y;
		}
	      else
		{
		  double d_t = distanta(0,0,array[j].x,array[j].y);
		  if (d_t < dist_min)
		    {
		      traseu[i].x = array[j].x;
		      traseu[i].y = array[j].y;
		    }
		}
	    }	  
	}
      else
	{
	  double dist_min_t = -1;
	  double d = 0;
	  int k = 0;
          for (;k < n; k++)
	    {
	      for (int l = 0; l < i; l++)
		{
		  if ((array[k].x == traseu[l].x) && (array[k].y == traseu[l].y))
		    {
		      exista = 1;
		      break;
		    }
		}
		  
	      if(exista == 0){  
			  d = distanta(traseu[i-1].x,traseu[i-1].y,array[k].x,array[k].y);
			  if (dist_min_t == -1 || d < dist_min_t)
			    {
			      dist_min_t = d;
			      traseu[i].x = array[k].x;
			      traseu[i].y = array[k].y;
			    }
			}
	      
	      exista = 0;
	    }
		}
	  } 
  for (int i = 0; i < n; i++)
    {
      printf("%d - %d\n",traseu[i].x,traseu[i].y);
    }
  free(array);
  free(traseu);
  return 0;
}
