#include <stdio.h>
typedef struct Comanda
{
    int status;        // statusul unei comenzi
    int pret;          // pretul unei comenzi
    Articol *articole; // primul articol al comenzii
} Comanda;

typedef struct Lista_Comenzi
{
    int nr_comenzi;   // numarul de comenzi
    Comanda *Comanda; // prima comanda
} Lista_Comenzi;

typedef struct Articol
{
    int pret;   // pretul unui articol
    char *nume; // numele articolului
    int numar;  // numarul articolului
    struct Articol *next;
} Articol;
typedef struct Meniu
{
    int numar_articole; // numarul de articole de pe meniu
    Articol *articole;
} Meniu;

Lista_Comenzi deschide_lista(int nr_comenzi);
void inchide_lista(Lista_Comenzi lista_comezi);
Meniu *init_meniu(FILE *f);
void afisaremeniu(Meniu *meniu);
