#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "restaurant.h"
int main()
{
    FILE *f;
    f = fopen("meniu.txt", "r");
    Meniu *meniu = init_meniu(f);
    printf("%s", meniu->articole->nume);
    printf("\n\n");
    afisaremeniu(meniu);
    Lista_Comenzi *ceva; 
    ceva= (Lista_Comenzi *)malloc(sizeof(Lista_Comenzi));
    ceva->nr_comenzi = 0;
    printf("%d", ceva->nr_comenzi);
    ceva->Comanda = NULL;
    printf("sal");
    fflush(stdout);
    adaugarecomanda(ceva, meniu);
   // printf("%d", ceva->nr_comenzi);
    //printf("%d", ceva->Comanda->articole->pret);
    afisarecomanda(ceva, 0);

    return 0;
}