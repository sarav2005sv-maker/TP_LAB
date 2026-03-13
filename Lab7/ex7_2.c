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
	if(nod_nou == NULL)
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

nod *inversare(nod *lista)
{ 
  if(lista == NULL)
    { 
      return lista;
    } 
  nod *prev, *q,*aux; 
  for(prev=lista, q=lista->urm;q->urm!= NULL; prev = q, q=aux) 
    { 
      aux=q->urm;
      q->urm = prev;
    } 
  q->urm=prev; 
  lista->urm=NULL; 
  lista=q; 
return lista;
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
  nod* lista = NULL;
  lista = nou(10,lista);
  lista = nou(20,lista);
  lista = nou(30,lista);
  afisare(lista);
  lista = inversare(lista);
  afisare(lista);
  eliberare(lista);
  return 0;
}
