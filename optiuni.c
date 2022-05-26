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
    Comanda *aux;
    for (int i = 0; i < nrcomanda; i++)
    {

        aux = Lista_Comenzi->Comanda;
        aux = aux->next;
    }
    printf("Pretul total este: %d", aux->pret);
    printf("\n");
    while (aux->articole != NULL)
    {
        printf("Produs: %s\n", aux->articole->nume);
        printf("Pret: %d\n", aux->articole->pret);
        aux->articole = aux->articole->next;
    }
}

void adaugarecomanda(Lista_Comenzi **listacomanda, Meniu *meniu)
{
    (*listacomanda)->nr_comenzi++;
    Comanda *aux = (*listacomanda)->Comanda;
    while (aux->next != NULL)
    {
        aux = aux->next;
    }
    Comanda *newcommand = plasare();
    while (1)
    {
        char *c = malloc(sizeof(4));
        scanf("%s", c);
        printf("mai doresti cv bossule:\n");
        if (strcmp(c, "nu") == 0)
            break;
        printf("ce ti dau");
        int b;
        scanf("%d", &b);
        adaugarearticol(&newcommand, b, meniu);
    }
    aux->next = newcommand;
}

Comanda *plasare()
{

    Comanda *newcommand = (Comanda *)malloc(sizeof(Comanda));
    newcommand->status = 0;
    newcommand->pret = 0;
    newcommand->articole = NULL;
    return newcommand;
}

void adaugarearticol(Comanda **comanda, int k, Meniu *meniu)
{
    Articol *articol = meniu->articole;
    while (k > 0)
    {
        articol = articol->next;
    }
    Articol *newarticol = (Articol *)malloc(sizeof(Articol));
    newarticol->pret = articol->pret;
    strcpy(newarticol->nume, articol->nume);
    newarticol->numar = articol->numar;
    // int counter = 0;

    Articol *finalarticole = (*comanda)->articole;
    while (finalarticole->next != NULL)
    {
        finalarticole = finalarticole->next;
        //    counter++;
    }
    finalarticole->next = newarticol;
    (*comanda)->pret = (*comanda)->pret + newarticol->pret;
}
