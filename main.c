#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "restaurant.h"
int main()
{
    FILE *f;
    f = fopen("meniu.txt", "r");
    Meniu *meniu = init_meniu(f);
    Lista_Comenzi *Lista_de_comenzi = (Lista_Comenzi *)malloc(sizeof(Lista_Comenzi));
    int n = 0;
    while (n != 9)
    {
        printf("Alegeti optiunea dorita:\n");
        printf("1.Afisati meniul\n");
        printf("2.Plasati o comanda\n");
        printf("3.Afisati o comanda\n");
        printf("Alegeti optiunea dorita:\n");
        printf("Alegeti optiunea dorita:\n");
        printf("9.Iesire\n");
        scanf("%d", &n);
        if (n == 1)
        {
            afisaremeniu(meniu);
        }
        if (n == 2)
        {
            adaugarecomanda(Lista_de_comenzi, meniu);
        }
        if (n == 3)
        {
            int nrcomanda;
            printf("Introduceti numarul comenzii:\n");
            scanf("%d", &nrcomanda);
            nrcomanda--;
            afisarecomanda(Lista_de_comenzi, nrcomanda);
        }
    }

    return 0;
}