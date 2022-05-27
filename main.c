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
    // fclose(f);
    printf("Introduceti username:\n");
    char *user = malloc(sizeof(7));
    scanf("%s", user);
    if (strcmp(user, "Client") == 0 || strcmp(user, "Staff") == 0)
    {
        if (strcmp(user, "Client") == 0)
        {
            while (n != 6 || n < 0 || n > 6)
            {
                printf("\n\n");
                printf("Buna ziua! Bine ati venit.\n");
                printf("Alegeti optiunea dorita:\n");
                printf("Tasta 1 - Afisati meniul\n");
                printf("Tasta 2 - Plasati o comanda\n");
                printf("Tasta 3 - Afisati o comanda\n");
                printf("Tasta 4 - Modificati o comanda\n");
                printf("Tasta 5 - Anulare comanda\n");
                printf("Tasta 6 - Iesire\n");
                printf("\n\n");

                scanf("%d", &n);
                if (n == 1)
                {
                    printf("MENIU:\n");
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
                    if (nrcomanda < Lista_de_comenzi->nr_comenzi && nrcomanda >= 0)
                        afisarecomanda(Lista_de_comenzi, nrcomanda);
                    else
                        printf("Nu exista comanda.\n");
                }
                if (n == 5)
                {
                    int nrcomanda;
                    printf("Introduceti numarul comenzii:\n");
                    scanf("%d", &nrcomanda);
                    nrcomanda--;
                    if (nrcomanda < Lista_de_comenzi->nr_comenzi && nrcomanda >= 0)
                    {
                        anulare_comanda(Lista_de_comenzi, nrcomanda);
                        printf("Comanda a fost anulata cu succes!\n");
                    }
                    else
                        printf("Nu exista comanda.\n");
                }
            }
        }
        else
        {
            printf("Bine ai revenit. Iata ce comenzi ai la dispozitie:\n");
            printf("Tasta 1 -Modificare status\n");
            printf("Tasta 2 - Modificare meniu\n");
            printf("Tasta 3 - Eliminare comanda\n");
            printf("Tasta 4 - Iesire\n");
            printf("\n\n");

            scanf("%d", &n);
            if (n == 1)
            {
            }

            if (n == 2)
            {
                meniu->numar_articole = meniu->numar_articole + 1;
                // adaugarearticol(meniu, meniu->numar_articole, )
                char *numenou = (char *)malloc(sizeof(20));
                printf("Numele noului articol din meniu:\n");
                scanf("%s\n", numenou);
                printf("Pretul noului articol:");
                int *pret = malloc(sizeof(int));
                scanf("%d\n", pret);
            }
        }
    }
    else
        printf("Username-ul  nu exista.\n");

    return 0;
}