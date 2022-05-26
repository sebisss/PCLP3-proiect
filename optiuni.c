#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "restaurant.h"
#define NR_MAX 20
Meniu *init_meniu(FILE *f)
{
    Meniu *meniu = (Meniu *)malloc(sizeof(Meniu));
    fscanf(f, "%d\n", &meniu->numar_articole);
    meniu->articole = NULL;
    Articol *prev = NULL;
    for (int i = meniu->numar_articole; i > 0; i--)
    {
        Articol *articol = malloc(sizeof(Articol));
        articol->nume = malloc(NR_MAX);
        fscanf(f, "%s ", articol->nume);
        fscanf(f, "%d ", &articol->pret);
        fscanf(f, "%d\n", &articol->numar);
        if (prev == NULL)
        {
            meniu->articole = articol;
        }
        else
        {
            prev->next = articol;
        }
        prev = articol;
    }
    prev->next = NULL;
    return meniu;
}

void afisaremeniu(Meniu *meniu)
{
    Articol *articol = meniu->articole;
    for (int i = meniu->numar_articole; i > 0; i--)
    {
        printf("%s ", articol->nume);
        printf("%d ", articol->pret);
        printf("%d\n", articol->numar);
        articol = articol->next;
    }
}
void afisarecomanda(Lista_Comenzi *Lista_Comenzi, int nrcomanda)
{
    if (nrcomanda > Lista_Comenzi->nr_comenzi)
        return 0;
    for (int i = 0; i < nrcomanda; i++)
    {

        Comanda *aux = Lista_Comenzi->Comanda;
    }
}