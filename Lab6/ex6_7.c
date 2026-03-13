#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int comune(int nVec,...) 
{
    int count = 0;
    va_list va;
    va_start(va, nVec);
    int* v1 = va_arg(va, int*);
    int n1 = va_arg(va, int);

    int switch_t = 0;
    
    for (int i = 0; i < n1; i++) 
    {
       int* v = va_arg(va, int*);
       int n = va_arg(va, int);
      for (int k = 0; k < (nVec - 1); k++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (v1[i] == v[j]) 
                {
		  switch_t = 1;
                    printf("%d - %d - vector: %d\n", *(v1 + i), *(v + j),k);
                    break;
                }
		else
                {
                    switch_t = 0;
                    continue;
		} 
            }
            if (switch_t != 1) 
            {
	      break;
            } 
            else 
            {
	      printf("nu am gasit potrivire in vectorul %d pt %d\n",k,*(v1 + i));
                break;
	    } 
        }        
        if (switch_t == 1) 
        {
            count++;
	    printf("count = %d\n",count);
        }
        switch_t = 0;
    }
    
    va_end(va);
    return count;
}

int main() 
{
    int v1[] = {8, 5, 4};
    int v2[] = {1, 8, 5};
    int v3[] = {9, 0, 5};
    int n = comune(3, v1, 3, v2, 3, v3, 3);
    printf("%d\n", n);
    return 0;
}
