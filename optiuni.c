#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "restaurant.h"

Meniu init_meniu(FILE *f)
{
    Meniu *meniu = (Meniu *)malloc(sizeof(Meniu));
    meniu->numar_articole = fscanf(f, "%d", 1);
}