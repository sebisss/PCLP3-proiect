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
    Comanda *aux = Lista_Comenzi->Comanda;
    for (int i = 0; i < nrcomanda; i++)
    {

        // aux = Lista_Comenzi->Comanda;
        aux = aux->next;
    }
    printf("Pretul total este: %d", aux->pret);
    printf("\n");
    Articol *aux2 = aux->articole;
    while (aux2 != NULL)
    {
        printf("Produs: %s\n", aux2->nume);
        printf("Pret: %d\n", aux2->pret);
        aux2 = aux2->next;
    }
}

Lista_Comenzi *adaugarecomanda(Lista_Comenzi *listacomanda, Meniu *meniu)
{
    printf("%d nr comanda", listacomanda->nr_comenzi);
    listacomanda->nr_comenzi = listacomanda->nr_comenzi + 1;

    Comanda *aux = listacomanda->Comanda;
    if (listacomanda->Comanda != NULL)
        while (aux->next != NULL)
            aux = aux->next;

    printf("%d nr comanda ba", listacomanda->nr_comenzi);
    Comanda *newcommand = plasare();
    printf("%d nr comanda", listacomanda->nr_comenzi);
    while (1)
    {
        char *c = malloc(sizeof(4));
        printf("mai doresti cv bossule:\n");
        scanf("%s", c);

        if (strcmp(c, "nu") == 0)
            break;
        printf("ce ti dau");
        int *b = malloc(sizeof(int));
        scanf("%d", b);
        printf("%d nr comanda", listacomanda->nr_comenzi);
        newcommand = adaugarearticol(newcommand, *b, meniu);
        printf("%d nr comanda", listacomanda->nr_comenzi);
        free(b);
    }
    printf("%d nr comanda", listacomanda->nr_comenzi);
    if (listacomanda->Comanda != NULL)
        aux->next = newcommand;
    else
        listacomanda->Comanda = newcommand;
    // printf("%d", newcommand->articole->pret);
    return listacomanda;
}

Comanda *plasare()
{

    Comanda *newcommand = (Comanda *)malloc(sizeof(Comanda));
    newcommand->status = 0;
    newcommand->pret = 0;
    newcommand->articole = NULL;
    return newcommand;
}

Comanda *adaugarearticol(Comanda *comanda, int k, Meniu *meniu)
{
    Articol *articol = meniu->articole;
    while (k > 0)
    {
        articol = articol->next;
        k--;
    }
    // if(meniu->articole == NULL) printf("Da");

    Articol *newarticol = (Articol *)malloc(sizeof(Articol));

    if (meniu->articole != NULL)
    {
        newarticol->pret = articol->pret;
        newarticol->nume = malloc(sizeof(20));
        strcpy(newarticol->nume, articol->nume);
        newarticol->numar = articol->numar;
    }
    // int counter = 0;

    Articol *finalarticole = comanda->articole;
    while (comanda->articole != NULL && finalarticole->next != NULL)
    {
        finalarticole = finalarticole->next;
        //    counter++;
    }
    if (comanda->articole != NULL)
        finalarticole->next = newarticol;
    else
        comanda->articole = newarticol;
    comanda->pret = comanda->pret + newarticol->pret;
    printf("%s", comanda->articole->nume);
    return comanda;
}
Lista_Comenzi *anulare_comanda(Lista_Comenzi *Lista_de_comenzi, int nr_comanda)
{
    Comanda *aux = Lista_de_comenzi->Comanda;
    Comanda *aux2;
    Comanda *aux3;
    if (nr_comanda + 1 == Lista_de_comenzi->nr_comenzi)
    {
        while (aux->next != NULL)
        {
            aux2 = aux;
            aux = aux->next;
        }
        while (aux->articole != NULL)
        {
            Articol *aux_articol = aux->articole;
            aux->articole = aux->articole->next;
            if (aux_articol != NULL)
                free(aux_articol);
        }
        Lista_de_comenzi->nr_comenzi--;
        aux2->next = NULL;
        return Lista_de_comenzi;
    }
    else if (nr_comanda == 0)
    {
        aux2 = aux;
        aux = aux->next;
        Lista_de_comenzi->Comanda = aux;
        while (aux2->articole != NULL)
        {
            Articol *aux_articol = aux2->articole;
            aux2->articole = aux2->articole->next;
            if (aux_articol != NULL)
                free(aux_articol);
        }
        if (aux2 != NULL)
            free(aux2);
        Lista_de_comenzi->nr_comenzi--;
        return Lista_de_comenzi;
    }
    Lista_de_comenzi->nr_comenzi--;
    for (int i = 0; i < nr_comanda; i++)
    {
        aux2 = aux;
        aux = aux->next;
        // if (i == nr_comanda - 1)
        //   aux2 = aux;
    }
    aux3 = aux;
    aux = aux->next;
    aux2->next = aux;
    while (aux3->articole != NULL)
    {
        Articol *aux_articol = aux3->articole;
        aux3->articole = aux->articole->next;
        if (aux_articol != NULL)
            free(aux_articol);
    }
    if (aux3 != NULL)
        free(aux3);

    return Lista_de_comenzi;
}
