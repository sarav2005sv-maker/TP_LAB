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
  nou->next = head;
  nou->prev = NULL;
  head->prev = nou;
  head = nou;
  return head;
}

nod* sterge_first_last(nod* head)
{
  if (head == NULL)
    {
      fprintf(stderr,"nu putem sterge din lista goala\n");
      exit(-1);
    }
  if (head->next == NULL)
    {
      free(head);
      return NULL;
    }
  nod* p = head;
  head = head->next;
  free(p);
  head->prev = NULL;
  nod* q = head;
  while(q->next!=NULL)
    {
      q = q->next;
    }
  q->prev->next = NULL;
  free(q);
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
  head = sterge_first_last(head);
  afisare(head);
  eliberare(head);
  return 0;
}
