#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
  int inf;
  struct nod* next;
}nod;

typedef struct
{
  nod* pare;
  nod* impare;
}lis;

nod* adaugare(nod* head,int elem)
{
  nod* nou = (nod*)malloc(1 * sizeof(nod));
   if (nou == NULL)
    {
      fprintf(stderr,"err alocare\n");
      return NULL;
    }
  nou->inf = elem;
  if (head == NULL)
    {
      nou->next = NULL;
      head = nou;
      return head;
    }
  nou->next = head;
  head = nou;
  return head;
}

void eliberare(nod* head)
{
  nod* p = head;
  while (head!=NULL)
    {
      p = head->next;
      free(head);
      head = p;
    }
}

void afisare(nod* head)
{
  nod* p = head;
  if (head == NULL)
    {
      printf("lista este goala\n");
      return;
    }
  while(p!=NULL)
    {
      printf("%d ",p->inf);
      p = p->next;
    }
  printf("\n");
}

lis* odd_even_lists(nod* head,lis* liste)
{
  if (head == NULL)
    {
      fprintf(stderr,"lista este nula, nu se poate face operatia\n");
      return NULL;
    }
  nod* p = head;
  for(;p!=NULL;p=p->next)
    {
      if (p->inf % 2 == 0)
	{
	  liste->pare = adaugare(liste->pare,p->inf);
	}
      else
	{
	  liste->impare = adaugare(liste->impare,p->inf);
	}
    }
  return liste;
}

int main(void)
{
  nod* head = NULL;
  lis* liste = (lis*)malloc(sizeof(lis));
  if (liste == NULL)
    {
      fprintf(stderr,"err alocare\n");
      return -1;
    }
  liste->pare = NULL;
  liste->impare = NULL;
  head = adaugare(head,1);
  head = adaugare(head,2);
  head = adaugare(head,3);
  head = adaugare(head,4);
  head = adaugare(head,5);
  head = adaugare(head,6);
  afisare(head);
  liste = odd_even_lists(head,liste);
  afisare(liste->pare);
  afisare(liste->impare);
  eliberare(liste->pare);
  eliberare(liste->impare);
  eliberare(head);
  return 0;
}
