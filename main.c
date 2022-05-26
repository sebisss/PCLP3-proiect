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
    printf("cacat");
    printf("\n\n");
    afisaremeniu(meniu);
    return 0;
}