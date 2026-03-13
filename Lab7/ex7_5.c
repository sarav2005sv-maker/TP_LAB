#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
  int inf;
  struct nod* urm;
}nod;

nod* nou(int n,nod* p)
{
  nod* nou;
  nou = (nod*)malloc(1 * sizeof(nod));
  if (nou == NULL)
    {
      return NULL;
    }
  nou->inf = n;
  nou->urm = p;
  return nou;
}

nod* adauga_inceput(nod* lista,int n)
{
  return nou(n,lista);
}

void afisare(nod* lista)
{
  nod* p;
  for (p = lista; p!=NULL;p = p->urm)
    {
      printf("%d ",p->inf);
    }
  printf("\n");
}

int com(nod* lista1,nod* lista2)
{
  nod *p,*q;
  int flag = 1;
  for (p = lista1;p!=NULL;p=p->urm)
    {
      for (q = lista2;q!=NULL;q=q->urm)
	{
	  if (p->inf == q->inf)
	    {
	      flag = 1;
	      break;
	    }
	  else
	    {
	      flag = 0;
	    }
	}
      if (flag == 0)
	{
	  break;
	}
    }
  return flag;
}

int com1(nod* lista1,nod* lista2)
{
  int p = com(lista1,lista2);
  int q = com(lista2,lista1);
  return p && q;
}

void eliberare(nod* lista)
{
  nod* p;
  while(lista!=NULL)
    {
      p = lista->urm;
      free(lista);
      lista = p;
    }
}

int main()
{
  nod* lista1 = NULL;
  lista1 = adauga_inceput(lista1,6);
  lista1 = adauga_inceput(lista1,1);
  //lista1 = adauga_inceput(lista1,8);
  lista1 = adauga_inceput(lista1,3);
  nod* lista2 = NULL;
  lista2 = adauga_inceput(lista2,6);
  lista2 = adauga_inceput(lista2,3);
  lista2 = adauga_inceput(lista2,1);
  lista2 = adauga_inceput(lista2,8);
  printf("lista1 = \n");
  afisare(lista1);
  printf("lista2 = \n");
  afisare(lista2);
  printf("%d\n",com1(lista1,lista2));
  eliberare(lista1);
  eliberare(lista2);
  return 0;
}
