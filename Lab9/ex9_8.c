#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
  int inf;
  struct nod* next;
}nod;

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
      exit(-1);
    }
  while(p!=NULL)
    {
      printf("%d ",p->inf);
      p = p->next;
    }
  printf("\n");
}

nod* first_goes_last(nod* head)
{
  nod* p = head;
  if (head == NULL)
    {
      fprintf(stderr,"nu se poate efectua operatia pe lista vida\n");
      exit(-1);
    }
  if (head->next == NULL)
    {
      fprintf(stderr,"nu se poate efectua operatia pe lista cu mai putin de 3 elem\n");
      exit(-1);
    }
   if (head->next->next == NULL)
    {
      fprintf(stderr,"nu se poate efectua operatia pe lista cu mai putin de 3 elem\n");
      exit(-1);
    }
  head = head->next;
  nod* aux = p;
  for(;p->next !=NULL;p = p->next);
  p->next = aux;
  aux->next = NULL;
  return head;
}

int main(void)
{
  nod* head = NULL;
  head = adaugare(head,10);
  head = adaugare(head,20);
  head = adaugare(head,30);
  head = adaugare(head,40);
  head = adaugare(head,50);
  head = adaugare(head,60);
  afisare(head);
  head = first_goes_last(head);
  afisare(head);
  eliberare(head);
  return 0;
}
