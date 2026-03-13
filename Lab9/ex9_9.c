#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
  int inf;
  struct nod* next;
}nod;

nod* adaugare(nod* lista,int elem)
{
  nod* nou = (nod*)malloc(1 * sizeof(nod));
  if (nou == NULL)
    {
      perror("err alocare\n");
      return NULL;
    }
  
  if (lista == NULL)
    {
      nou->next = NULL;
    }
  nou->inf = elem;
  nou->next = lista;
  lista = nou;
  return lista;
}

void afisare(nod* lista)
{
  if (lista == NULL)
    {
      printf("lista este goala\n");
      return;
    }
  nod* p = lista;
  for(;p != NULL; p = p->next)
    {
      printf("%d ",p->inf);
    }
  printf("\n");
}

nod* stergere_pare(nod* lista)
{
  if (lista == NULL)
    {
      fprintf(stderr,"lista este goala\n");
      return NULL;
    }
  nod* aux;
  while (lista != NULL && lista->inf % 2 == 0)
    {
      aux = lista;
      lista = lista->next;
      free(aux);     
    }
  if (lista == NULL)
    {
      return lista;
    }
  nod* p = lista;
  for (;p->next!=NULL;)
    {
      if (p->next->inf % 2 == 0)
	{
	  aux = p->next;
	  p->next = p->next->next;
	  free(aux);
	}
      else
	{p = p->next;}	
    }
  return lista;
}


int main()
{
  nod* lista = NULL;
  int nr;
  int m;
  scanf("%d",&nr);
  //getchar();
  for (int i = 0; i < nr; i++)
    {
      scanf("%d",&m);
      //getchar();
      lista = adaugare(lista,m);
    }
  afisare(lista);
  lista = stergere_pare(lista);
  afisare(lista);
  return 0;
}
