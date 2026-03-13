#include <stdio.h>

int cautareBinara(int a[],int elem,int inceput,int sfarsit)
{
  if (inceput <= sfarsit)
    {
      int mijloc = (inceput+sfarsit)/2;
      if (elem == a[mijloc])
	{
	  return mijloc;
	}
      else
	{
	  if (elem < a[mijloc])
	    {
	      return cautareBinara(a,elem,inceput,mijloc-1);
	    }
	  else
	    {
	      return cautareBinara(a,elem,mijloc+1,sfarsit);
	    }
	}
    }
  else
    {
      return -1;
    }
}

int main()
{
  int a[] = {1,2,3,4};
  int n = cautareBinara(a,4,0,3);
  if (n != -1)
    {
      printf("am gasit elementul pe pozitia %d\n",n);
    }
  else
    {
      printf("nu am gasit elementul in vector\n");
    }
  return 0;
}
