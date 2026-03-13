#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000

typedef struct nod
{
  char inf[SIZE];
  struct nod* prev;
  struct nod* next;
}nod;

nod* adaugare_sortata(nod* head,char* line)
{
  nod* nou = (nod*)malloc(sizeof(nod));
  if (nou == NULL)
    {
      fprintf(stderr,"eroare alocare\n");
      exit(-1);
    }
  strcpy(nou->inf,line); 
  nod* p = head;
  if (head == NULL)
    {
      nou->prev = NULL;
      nou->next = NULL;
      head = nou;
      return head;
    }
  while(p!=NULL)
    {
      if (p == head && strcmp(nou->inf,p->inf)<0)
	{
	  nou->next = p;
	  nou->prev = NULL;
	  p->prev = nou;
	  head = nou;
	  return head;
	}
      if (p->next == NULL && strcmp(nou->inf,p->inf)>0)
	{
	  p->next = nou;
	  nou->prev = p;
	  nou->next = NULL;
	  return head;
	}
      if (strcmp(p->inf,nou->inf)<0 && strcmp(p->next->inf,nou->inf)>=0)
	{
	  p->next->prev = nou;
	  nou->prev = p;
	  nou->next = p->next;
	  p->next = nou;
	  return head;
	}
      p = p->next;
    }
  return head;
}

void afisare(nod* head)
{
  nod* p = head;
  while(p!=NULL)
    {
      printf("%s",p->inf);
      p = p->next;
    }
}

int main(int argc,char** argv)
{
  FILE* f;
  f = fopen(argv[1],"r");
  if (f == NULL)
    {
      fprintf(stderr,"eroare deschidere fisier\n");
      exit(-1);
    }

  nod* head = NULL;
  char line[SIZE];
  while(fgets(line,1000,f) != NULL)
    {
      head = adaugare_sortata(head,line);
    }
  afisare(head); 
  if (fclose(f) != 0)
    {
      fprintf(stderr,"eroare inchidere fisier\n");
      exit(-1);
    }
  return 0;
}
