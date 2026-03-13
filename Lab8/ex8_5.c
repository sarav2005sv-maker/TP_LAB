#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  unsigned int cod : 14;
  unsigned int locuri : 4;
  unsigned int putere : 9;
  char marca[20];
  char culoare[20];
  unsigned int an : 11;
}automobil;

typedef struct nod
{
  automobil masina;
  struct nod* next;
  struct nod* prev;
}nod;

typedef struct
{
  nod* first;
  nod* last;
}list;

list* adauga_inceput(list* list,automobil elem)
{
  nod* nou = (nod*)malloc(1 * sizeof(nod));
  if (nou == NULL)
    {
      fprintf(stderr,"eroare alocare\n");
      exit(-1);
    }
  nou->masina = elem;
  if (list->first == NULL)
    {
      list->first = nou;
      list->first->prev = NULL;
      list->first->next = NULL;
      return list;
    }
  nou->next = list->first;
  nou->prev = NULL;
  list->first = nou;
  return list;
}

void afisare(list* list)
{
  nod* p = list->first;
  while(p!=NULL)
    {
      printf("%d - %d - %d - %s - %s - %d\n",p->masina.cod,p->masina.locuri,p->masina.putere,p->masina.marca,p->masina.culoare,p->masina.an);
      p = p->next;
    }
}

void afisare_filtrata(list* list,int m)
{
  nod* p = list->first;
  int flag = 0;
  while(p!=NULL)
    {
      if (p->masina.locuri == m)
	{
	  flag = 1;
	  printf("cod:%d - locuri:%d - putere:%d - marca:%s - culoare:%s - an:%d\n",p->masina.cod,p->masina.locuri,p->masina.putere,p->masina.marca,p->masina.culoare,p->masina.an);
	  p = p->next;
	}
      else
	{
	  p = p->next;
	}
    }
  if (flag == 0)
    {
      printf("nu exista automobil cu nr de locuri specificat\n");
    }
}

list* stergere_element(list* list,int elem)
{
  if (list->first == NULL || list == NULL)
    {
      printf("lista este nula\n");
      return NULL;
    }
  nod* p = list->first;
      if (elem == list->first->masina.cod)//sterge primul element
	{
	  list->first = p->next;
	  if (list->first != NULL)
	    {
	      list->first->prev = NULL;
            }
        free(p);
        return list;
	}
  
  while(p!=NULL)
    {
      if (p->masina.cod == elem)
	{
	  if (p->next == NULL) //sterge ultimul element
	    {
	      p->prev->next = NULL;
	      free(p);
	      return list;
	    }
	  //stergem element din interior
	  p->next->prev = p->prev;
	  p->prev->next = p->next;
	  free(p);
	  return list;
	}
      p = p->next;
    }
  return list;
}

list* adaugare_sortata(list* list,automobil elem)
{
  nod* nou = (nod*)malloc(1 * sizeof(nod));
  if (nou == NULL)
    {
      fprintf(stderr,"eroare alocare\n");
      return NULL;
    }
  nou->masina = elem;
  if (list->first == NULL) //inserare in lista goala
    {
      nou->prev = NULL;
      nou->next = NULL;
      list->first = nou;
      return list;
    }
  nod* p = list->first;
  while(p != NULL)
    {
      if (p == list->first && nou->masina.an < p->masina.an)
	{
	  //inserare la inceput
	  nou->next = p;
	  nou->prev = NULL;
	  p->prev = nou;
	  list->first = nou;
	  return list;
	}
      if (p->next == NULL && nou->masina.an > p->masina.an)
	{
	  //inserare la final
	  p->next = nou;
	  nou->prev = p;
	  nou->next = NULL;
	  return list;
	}
      if (p->masina.an < nou->masina.an && p->next->masina.an > nou->masina.an)
	{
	  p->next->prev = nou;
	  nou->prev = p;
	  nou->next = p->next;
	  p->next = nou;
	  return list;
	}
      p = p->next;
    }
  return list;
}

int main()
{
  int n;
  if (scanf("%d",&n) != 1)
    {
      fprintf(stderr,"eroare citire n\n");
      exit(-1);
    }
  unsigned int aux_cod;
  unsigned int aux_locuri;
  unsigned int aux_putere;
  char aux_marca[20];
  char aux_culoare[20];
  unsigned int aux_an;
  list* list = malloc(1 * sizeof(list));
  automobil masina;
  for (int i = 0; i < n; i++)
    {
      printf("introduceti cod:\n");
      scanf("%d",&aux_cod);
      getchar();
      masina.cod = aux_cod;
      printf("introduceti nr locuri:\n");
      scanf("%d",&aux_locuri);
      getchar();
      masina.locuri = aux_locuri;
      printf("introduceti putere:\n");
      scanf("%d",&aux_putere);
      getchar();
      masina.putere = aux_putere;
      printf("introduceti marca:\n");
      fgets(aux_marca,20,stdin);
      aux_marca[strcspn(aux_marca, "\n")] = 0;
      strcpy(masina.marca,aux_marca);
      printf("introduceti culoarea:\n");
      fgets(aux_culoare,20,stdin);
      aux_culoare[strcspn(aux_culoare, "\n")] = 0;
      strcpy(masina.culoare,aux_culoare);
      printf("introduceti anul:\n");
      scanf("%d",&aux_an);
      getchar();
      masina.an = aux_an;
      list = adaugare_sortata(list,masina);
    }
  afisare(list);
  int m;
  printf("introduceti nr de locuri dorit:\n");
  if(scanf("%d",&m) != 1)
    {
      fprintf(stderr,"eroare citire m\n");
      exit(-1);
    }
  afisare_filtrata(list,m);
  int s;
  printf("introduceti codul masinii de eliminat:\n");
  scanf("%d",&s);
  list = stergere_element(list,s);
  afisare(list);
  free(list);
  return 0;
}
