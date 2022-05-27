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
  
   printf("INFO: Pentru a incheia programul folositi username-ul 'logout'\n\n ");
   while (1){
    
    printf("Introduceti username:\n");
    char *user = malloc(sizeof(7));
    scanf("%s", user);
    if(strcmp(user, "Client") == 0 || strcmp(user, "Staff") == 0) {
    if(strcmp(user, "Client") == 0){

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

     
        printf("Ce doriti sa faceti?\n");
        scanf("%d", &n);
        if (n == 1)
        {   printf("MENIU:\n");
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
            if(nrcomanda < Lista_de_comenzi->nr_comenzi && nrcomanda >= 0)
            afisarecomanda(Lista_de_comenzi, nrcomanda);
            else printf("Nu exista comanda.\n");
        }
        if(n == 5) {
            int nrcomanda;
            printf("Introduceti numarul comenzii:\n");
            scanf("%d", &nrcomanda);
            nrcomanda--;
            if(nrcomanda < Lista_de_comenzi->nr_comenzi && nrcomanda >= 0)
             {   anulare_comanda(Lista_de_comenzi, nrcomanda);
                printf("Comanda a fost anulata cu succes!\n");
             }
            else
            printf("Nu exista comanda.\n");


        }
    }
    }
    else{
        n=0;
        while(n != 4){
        printf("Bine ai revenit. Iata ce comenzi ai la dispozitie:\n");
        printf("Tasta 1 -Modificare status\n");
        printf("Tasta 2 - Modificare meniu\n");
        printf("Tasta 3 - Eliminare comanda\n");
        printf("Tasta 4 - Iesire\n");
        printf("\n\n");


        
      
        printf("\nCe doriti sa faceti?\n");
        scanf("%d", &n);
     
        if(n == 1){

        }

        if(n == 2){
            meniu->numar_articole = meniu->numar_articole + 1;
           
           Articol *newarticol = (Articol *) malloc(sizeof(Articol));
            newarticol->nume = (char*) malloc(sizeof(20));
           printf("Numele noului articol din meniu:\n");
           scanf("%s", newarticol->nume);
           printf("Pretul noului articol:");
         
           scanf("%d", &newarticol->pret);
           newarticol->next = NULL;
          
           newarticol->numar = meniu->numar_articole;

           Articol *auxiliar = meniu->articole;
           while(auxiliar->next != NULL){
               auxiliar = auxiliar->next;
           }
            auxiliar->next = newarticol;
            
            printf("Articolul a fost adaugat.\n");
        }
        

        }
    }
    }
    else {fclose(f); freemeniu(meniu); printf("Ati fost delogat.\n"); return 0;}
   
    
   }
    fclose(f);
    return 0;
}