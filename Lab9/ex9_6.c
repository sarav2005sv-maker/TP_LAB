#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
  int inf;
  struct nod* prev;
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
      nou->prev = NULL;
      nou->next = NULL;
      head = nou;
      return head;
    }
  nou->prev = NULL;
  nou->next = head;
  head->prev = nou;
  head = nou;
  return head;
}

nod* add_last_to_front(nod* head)
{
  nod* p = head;
  nod* q = head;
  if (head->next == NULL)
    {
      return head;
    }
  while(p->next != NULL)
    {
      p = p->next;    
    }
  p->prev->next = NULL;
  p->next = head;
  p->prev = NULL;
  head = p;
  return head;
}

void afisare(nod* head)
{
  nod* p = head;
  if (head == NULL)
    {
      printf("lista este goala\n");
      return;
    }
  for(;p!=NULL;p = p->next)
    {
      printf("%d ",p->inf);
    }
  printf("\n");
}

int main(void)
{
  nod* head = NULL;
  head = adaugare(head,10);
  head = adaugare(head,20);
  head = adaugare(head,30);
  afisare(head);
  head = add_last_to_front(head);
  afisare(head);
  return 0;
}
