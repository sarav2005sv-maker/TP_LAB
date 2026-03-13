#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

typedef struct{
  unsigned int cod : 14;
  unsigned int locuri : 4;
  unsigned int putere : 9;
  unsigned int an : 11;
  unsigned int culoare : 7; //~100 de culori
  char marca[SIZE];
}automobil;

void add(automobil* parc,int* nr_vehicule,int max)
{
  unsigned int aux_cod;
  unsigned int aux_locuri;
  unsigned int aux_putere;
  unsigned int aux_an;
  unsigned int aux_culoare;
  char aux_marca[SIZE];

  if (*(nr_vehicule) == max)
    {
      printf("lista este plina\n");
      return;
    }
  else
    {
      scanf("%d",&aux_cod);
      if (aux_cod < 1 || aux_cod > 9000)
	{
	  fprintf(stderr,"trb nr intre 1 si 9000\n");
	  exit(-1);
	}
      (parc + *nr_vehicule)->cod = aux_cod;
      scanf("%d",&aux_locuri);
       if (aux_locuri < 1 || aux_locuri > 9)
	{
	  fprintf(stderr,"trb nr intre 1 si 9\n");
	  exit(-1);
	}
      (parc + *nr_vehicule)->locuri = aux_locuri;
      scanf("%d",&aux_putere);
       if (aux_putere < 1 || aux_putere > 500)
	{
	  fprintf(stderr,"trb nr intre 1 si 500\n");
	  exit(-1);
	}
      (parc + *nr_vehicule)->putere = aux_putere;
      scanf("%d",&aux_an);
       if (aux_an < 1800 || aux_an > 2017)
	{
	  fprintf(stderr,"trb nr intre 1800 si 2017\n");
	  exit(-1);
	}
      (parc + *nr_vehicule)->an = aux_an;
      scanf("%d",&aux_culoare);
      (parc + *nr_vehicule)->culoare = aux_culoare;
      scanf("%8s",aux_marca);
      strcpy((parc + *nr_vehicule)->marca,aux_marca);
    }
  *(nr_vehicule) = *(nr_vehicule) + 1;
}

void afisare(automobil* parc,int nr_vehicule)
{
  for (int i = 0; i < nr_vehicule; i++)
    {
      printf("cod: %d\n locuri: %d\n putere: %d\n an: %d\n culoarea: %d\n marca: %s\n",(parc + i)->cod,(parc+i)->locuri,(parc + i)->putere,(parc + i)->an,(parc + i)->culoare,(parc + i)->marca);
      printf("\n");
    }
}

void filter(automobil* parc,int nr_vehicule,int nlocuri)
{
  for (int i = 0; i < nr_vehicule; i++)
    {
      if (((parc + i)->locuri) == nlocuri)
	{
	  printf("cod: %d\n locuri: %d\n putere: %d\n an: %d\n culoarea: %d\n marca: %s\n",(parc + i)->cod,(parc+i)->locuri,(parc + i)->putere,(parc + i)->an,(parc + i)->culoare,(parc + i)->marca);
      printf("\n");
	}
    }
}

int compar(const void* el1, const void* el2)
{
  const automobil* e1 = (automobil*)el1;
  const automobil* e2 = (automobil*)el2;
  if (e1->an < e2->an) return -1;
  if (e1->an > e2->an) return 1;
  return 0;
}

void delete(automobil* parc, int* nr_vehicule,int ncod)
{
  for (int i = 0; i < *nr_vehicule; i++)
    {
      if (((parc + i)->cod) == ncod)
	{
	  for (int j = i; j < *(nr_vehicule-1);j++)
	    {
	      *(parc + j) = *(parc + j + 1);
	    }
	}
    }
  *nr_vehicule = *nr_vehicule - 1;
}

int main(void)
{
  int max;
  printf("introduceti nr de locuri disponibile: ");
  if (scanf("%d",&max) == EOF)
    {
      perror(NULL);
      exit(-1);
    }
  automobil* parc;
  parc = malloc(max * sizeof(automobil));
  if (parc == NULL)
    {
      perror("eroare alocare");
      exit(-1);
    }
  int nr_vehicule = 0;
  int n;
  printf("introduceti nr de vehicule de introdus: ");
  scanf("%d",&n);
  for (int j = 0; j < n; j++)
    {
      add(parc,&nr_vehicule,max);
    }
  afisare(parc,nr_vehicule);
  printf("introduceti nr de locuri dorit: ");
  int nlocuri;
  scanf("%d",&nlocuri);
  printf("automobilele cu %d locuri sunt: \n",nlocuri);
  filter(parc,nr_vehicule,nlocuri);

  qsort(parc,nr_vehicule,sizeof(automobil),compar);
  printf("automobilele in ordinea crescatoare a anului:\n");
  afisare(parc,nr_vehicule);

  int ncod;
  printf("introduceti codul automobilului de sters: ");
  scanf("%d",&ncod);
  delete(parc,&nr_vehicule,ncod);
  afisare(parc,nr_vehicule);
  
  free(parc);
  return 0;
}
