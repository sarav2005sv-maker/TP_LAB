#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
  int inf;
  struct nod* urm;
}nod;

nod* nou(int n, nod* lista)
{
  nod* nod_nou;
  nod_nou = (nod*)malloc(sizeof(nod));
  if (nod_nou == NULL)
    {
      perror("eroare alocare\n");
      exit(-1);
    }
  nod_nou->inf = n;
  nod_nou->urm = lista;
  return nod_nou;
}

void afisare(nod* lista)
{
  nod* p = lista;
  while(p!=NULL)
    {
      printf("%d ",p->inf);
      p = p->urm;
    }
  printf("\n");
}

int identice(nod* lista1,nod* lista2)
{
  nod* p = lista1;
  nod* q = lista2;
  for (;p!=NULL&&q!=NULL;p=p->urm,q=q->urm)
    {
      if (p->inf != q->inf)
	{
	  return 0;
	}
    }
  if (p!= NULL || q!=NULL)
    {
      return 0;
    }
  return 1;
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
  lista1 = nou(10,lista1);
  lista1 = nou(20,lista1);
  lista1 = nou(30,lista1);
  afisare(lista1);
  nod* lista2 = NULL;
  lista2 = nou(10,lista2);
  lista2 = nou(20,lista2);
  lista2 = nou(30,lista2);
  afisare(lista2);
  printf("%d\n",identice(lista1,lista2));
  eliberare(lista1);
  eliberare(lista2);
  return 0;
}
