#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 10

typedef struct nod
{
  int inf;
  struct nod* next;
}nod;

nod* adaugare_sfarsit(nod* head,int elem)
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
  nod* p = head;
  for(;p->next!=NULL;p=p->next);
  p->next = nou;
  nou->next = NULL;
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

nod* sterge_inceput(nod* head)
{
  nod* p = head;
  if (head == NULL)
    {
      fprintf(stderr,"nu se poate sterge din lista vida\n");
      exit(-1);
    }
  head = head->next;
  free(p);
  return head;
}

nod* permutare(nod* head,int k)
{
  for (int i = 0; i < k; i++)
    {
      int n = head->inf;
      head = sterge_inceput(head);
      head = adaugare_sfarsit(head,n);
    }
  return head;
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
  char ch;
  char buf[SIZE + 1];
  int i = 0;
  int j = 0;
  int k;
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
	      if (j != 0)
		{
	          buf[i] = '\0';
	          int n = atoi(buf);
	          head = adaugare_sfarsit(head,n);
	          i = 0;
		}
	      else
		{
		  buf[i] = '\0';
	          k = atoi(buf);
		  i = 0;
		  j = 1;
		}
	    }
	}
    }
  if (i > 0)
    {
        buf[i] = '\0';
        int n = atoi(buf);
        head = adaugare_sfarsit(head, n);
    }
  printf("k: %d\n",k);
  afisare(head);
  head = permutare(head,k);
  afisare(head);
  eliberare(head);
  if (fclose(f) != 0)
    {
      fprintf(stderr,"err inchidere fisier\n");
      exit(-1);
    }
  return 0;
}
