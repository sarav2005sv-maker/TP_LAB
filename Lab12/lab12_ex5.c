#include <stdio.h>
#include <stdlib.h>

int n;//nr obiecte
int v[100];
int vol[100];
int vol_max;  
int sume[10000]; 
int contor = 0; 


int valid(int k) 
{
    int s = 0;

    //deci aici verifici daca obictul de la pasul k a mai fost folosit sau nu
    for (int i = 1; i < k; i++) 
    {
        if (v[k] == v[i]) 
        {
            return 0;
        }
    }

    //faci frumos suma VOLUMELOR obiectelor din v
    for (int i = 1; i <= k; i++) 
    {
        s = s + vol[v[i]];
    }
    if (s > vol_max || k > n) 
    {
        return 0;
    }
    return 1;
}


void solutie(int k) 
{
    int s = 0;
    for (int i = 1; i <= k; i++) 
    {
        s += vol[v[i]]; // si aici neaparat bagi tot vol[v[i]] in sume daca v e valid
    }
    sume[contor++] = s;
}

void afisare(int k) {
    for (int i = 1; i <= k; i++) {
        printf("%d ", vol[v[i]]); // --""--
    }
    printf("\n");
}

void back(int k) 
{
    for (int i = 1; i <= n; i++) 
    {
        v[k] = i; //CEL MAI IMPORTANT, AICI STOCAM INDICELE OBIECTULUI, NU VALOAREA
        if (valid(k)) 
        {
            solutie(k);
            afisare(k);
            back(k + 1);
        }
    }
}

int main() {
    printf("introduceti nr de obiecte: \n");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "err citire n\n");
        exit(-1);
    }
    if (n <= 0 || n > 100) {
        fprintf(stderr, "0 < n <= 100\n");
        exit(-1);
    }

    printf("introduceti volumul fiecarui obiect: \n");
    for (int i = 1; i <= n; i++) {
        if (scanf("%d", &vol[i]) != 1) {
            fprintf(stderr, "err citire vol[%d]\n", i);
            exit(-1);
        }
    }

    printf("introduceti volumul maxim: \n");
    if (scanf("%d", &vol_max) != 1) {
        fprintf(stderr, "err citire vol_max\n");
        exit(-1);
    }

    printf("combinarile testate:\n");
    back(1);

    int max = 0;
    if (contor > 0) //DACA CONTOR E MAI MARE DECAT 0, ATUNCI ASIGNAM VAL MAXIMA, CA POATE NU E
    {
        max = sume[0];
    }
    for (int i = 1; i < contor; i++) 
    {
        if (sume[i] > max) {
            max = sume[i];
        }
    }
    printf("suma maxima: %d\n", max);

    return 0;
}
