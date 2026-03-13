#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
  int inf;
  struct nod* urm;
}nod;

nod* nou(int n,nod* next)
{
  nod* nod_nou = malloc(sizeof(nod));
  if (nod_nou == NULL)
    {
      perror("eroare alocare\n");
      exit(-1);
    }
  nod_nou->inf = n;
  nod_nou->urm = next;
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

nod* insert(int n,nod* lista)
{
  nod* prev = lista;
  if (prev == NULL || n < prev->inf)
    {
      prev = nou(n,lista);
      return prev;
    }
  if (lista->urm == NULL)
    {
      lista->urm = nou(n,NULL);
      return lista;
    }
  nod* p = lista->urm;
  for (;p->urm!=NULL;prev = p,p = p->urm)
    {
      if (p->inf > n)
	{
	  prev->urm = nou(n,p);
	  break;
	}
    }
  if (n > p->inf)
    {
      p->urm = nou(n,NULL);
    }
  return lista;
}

nod* sortare(nod* lista)
{
  nod* p = lista,*rez = NULL;
  while(p!=NULL)
    {
      rez = insert(p->inf,rez);
      p = p->urm;
    }
  return rez;
}

int main()
{
  nod* lista = NULL;
  lista = nou(30,lista);
  lista = nou(10,lista);
  lista = nou(20,lista);
  lista = nou(12,lista);
  lista = nou(26,lista);
  //lista = insert(26,lista);
  //lista = insert(5,lista);
  lista = insert(14,lista);
  lista = insert(35,lista);
  lista = insert(44,lista);
  lista = sortare(lista);
  afisare(lista);
  eliberare(lista);
  return 0;
}
