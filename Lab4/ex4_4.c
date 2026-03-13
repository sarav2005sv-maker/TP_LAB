#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_SIZE 8

typedef struct {
  unsigned int picioare : 10;
  unsigned int greutate : 18;
  unsigned int danger : 1; //1 - da, 2 - nu
  unsigned int varsta : 11;
  char denumire[NAME_SIZE];
}animal;

void afisare(animal* animal_t)
{
  printf("%d picioare - ",animal_t->picioare);
  printf("%d kg - ",animal_t->greutate);
  if (animal_t->danger == 1)
    {
      printf("periculos - ");
    }
  else
    {
      printf("nu este periculos - ");
    }
  printf("%s - ",animal_t->denumire);
  printf("%d ani\n",animal_t->varsta);
}

int main(void)
{
  animal animal1;
  
  unsigned int aux_picioare;
  unsigned int aux_greutate;
  unsigned int aux_danger;
  unsigned int aux_varsta;
  char aux_denumire[NAME_SIZE];

  printf("dimensiune - %ld bytes\n",sizeof(animal));

  scanf("%d",&aux_picioare);
  if (aux_picioare >= 0 && aux_picioare <= 1000)
    {
      animal1.picioare = aux_picioare;
    }
  else
    {
      printf("nr trebuie sa fie intre 0 si 100\n");
      exit(-1);
    }
  
   scanf("%d",&aux_greutate);
   animal1.greutate = aux_greutate;
   scanf("%d",&aux_danger);
   animal1.danger = aux_danger;
   scanf("%8s",aux_denumire);
   strcpy(animal1.denumire,aux_denumire);
   scanf("%d",&aux_varsta);
    if (aux_varsta >= 0 && aux_picioare <= 2000)
    {
      animal1.varsta = aux_varsta;
    }
  else
    {
      printf("nr trebuie sa fie intre 0 si 2000\n");
      exit(-1);
    }

   afisare(&animal1);
   
  return 0;
}
