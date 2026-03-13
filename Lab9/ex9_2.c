#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 10

typedef struct nod
{
  int inf;
  struct nod* next;
}nod;

typedef struct
{
  struct nod* pare;
  struct nod* impare;
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


int main(int argc,char** argv)
{
  if (argc < 2)
    {
      fprintf(stderr,"trebuie 2 argumente\n");
      return -1;
    }
  FILE* f = fopen(argv[1],"r");
  if (f == NULL)
    {
      fprintf(stderr,"err deschidere fisier\n");
      exit(-1);
    }
  nod* head = NULL;
  lis* liste = (lis*)malloc(sizeof(lis));
  if (liste == NULL)
    {
      fprintf(stderr,"err alocare\n");
      return -1;
    }
  liste->pare = NULL;
  liste->impare = NULL;
  char ch;
  char buf[SIZE + 1];
  int i = 0;
  while ((ch = fgetc(f)) != EOF)
    {
      if (isdigit(ch))
	{
	  buf[i] = ch;
	  i++;
	  if (i > SIZE)
	    {
	      fprintf(stderr,"nr pot avea maxim 10 cifre\n");
	      return -1;
	    }
	}
      else
	{
	  if (i > 0)
	    {
	      buf[i] = '\0';
	      int n = atoi(buf);
	      head = adaugare(head,n);
	      i = 0;
	    }
	}
    }
  if (i > 0)
    {
        buf[i] = '\0';
        int n = atoi(buf);
        head = adaugare(head, n);
    }

  afisare(head);
  liste = odd_even_lists(head,liste);
  afisare(liste->pare);
  afisare(liste->impare);
  eliberare(liste->pare);
  eliberare(liste->impare);
  eliberare(head);
  if (fclose(f) != 0)
    {
      fprintf(stderr,"err inchidere fisier\n");
      exit(-1);
    }
  return 0;
}




