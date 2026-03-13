#include <stdio.h>
#include <stdlib.h>

/*periculozitate:
   0 = scazuta
   1 = medie
   2 = mare
  reteta:
  0 = nu
  1 = da
 */

typedef struct {
  char pericol : 2;
  char reteta : 1;
  char varsta : 5;
}medicament;

medicament* read(medicament* medicament1)
{
  char aux_pericol;
  char aux_reteta;
  char aux_varsta;
  scanf("%hhd",&aux_pericol);
  medicament1->pericol = aux_pericol;
  scanf("%hhd",&aux_reteta);
  medicament1->reteta = aux_reteta;
  scanf("%hhd",&aux_varsta);
  medicament1->varsta = aux_varsta;
  return medicament1;
}

void afisare(medicament* medicament1)
{
  switch(medicament1->pericol)
    {
    case 0:
      {printf("grad de periculozitate scazut\n");
	break;}
    case 1:
      {printf("grad de periculozitate mediu\n");
        break;}
    case 2:
      {printf("grad de periculozitate mare\n");
	break;}
    default:
      {
	fprintf(stderr,"grad de periculozitate necunoscut\n");
      }
    }

      switch(medicament1->reteta)
	{
	case 1:
	  {
	    printf("trebuie reteta\n");
	    break;
	  }
	case 0:
	  {
	    printf("nu trebuie reteta\n");
	    break;
	  }
	default:
	  {
	    fprintf(stderr,"nu se stie\n");
	  }
	}
      printf("%d ani\n",medicament1->varsta);
      
}

int main(void)
{
  printf("%ld\n",sizeof(medicament));

  medicament medicament_t;
  read(&medicament_t);
  afisare(&medicament_t);
  return 0;
}
