#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
  int inf;
  struct nod* next;
  struct nod* prev;
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
      head = nou;
      nou->next = NULL;
      nou->prev = NULL;
      return head;
    }
  nou->next = head;
  nou->prev = NULL;
  head->prev = nou;
  head = nou;
  return head;
}

void afisare(nod* head)
{
  nod* p = head;
  while(p!=NULL)
    {
      printf("%d ",p->inf);
      p = p->next;
    }
  printf("\n");
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

void interschimbare(nod** phead)
{
  nod* p = *phead;
  if (*phead == NULL) 
    {
      printf("lista este goala\n");
      //return *phead;
    }
  *phead = p->next;
  while(p!=NULL)
    {
      p->next->prev = p->prev; 
      p->prev = p->next;
      p->next = p->next->next;  
      p->prev->next = p;
      if (p->next != NULL)
	{
	  p->next->prev = p;
	}
      if (p->prev->prev != NULL)
	{
	  p->prev->prev->next = p->prev;
	}
      p = p->next;
    }
  //return *phead;
}

int main()
{
  nod* head = NULL;
  head = adaugare(head,10);
  head = adaugare(head,20);
  head = adaugare(head,30);
  head = adaugare(head,40);
  head = adaugare(head,50);
  head = adaugare(head,60);
  head = adaugare(head,70);
  head = adaugare(head,80);
  afisare(head);
  interschimbare(&head);
  afisare(head);
  //printf("nod: %ld\n",sizeof(nod));
  eliberare(head);
  return 0;
}
