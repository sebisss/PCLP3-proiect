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
    void afisarecomanda(Lista_Comenzi * Lista_Comenzi, int nrcomanda);
    return 0;
}