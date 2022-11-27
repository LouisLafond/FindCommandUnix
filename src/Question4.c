#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include "Question1.h"


Pile * comparerPiles(Pile *pile1, Pile *pile2){
    Pile *P_resultat = calloc(1,sizeof(Pile));

    Element *courant1;
    courant1 = pile1->debut;

    for(int i=0;i<pile1->taille;++i){
        Element *courant2;
        courant2 = pile2->debut;
        
        for(int i=0;i<pile2->taille;++i){
            if (strcmp(courant1->donnee,courant2->donnee) == 0) {
                empiler(P_resultat,courant1->donnee);
                }

            courant2 = courant2->suivant;            
        }

        courant1 = courant1->suivant;
    }

    return P_resultat;
}

int fonction_ET(int argc, char* argv[]) {

    Pile *P_date = calloc(1,sizeof(Pile));
    Pile *P_size = calloc(1,sizeof(Pile));
    Pile *P_regex = calloc(1,sizeof(Pile));

    Pile *P_result = calloc(1,sizeof(Pile));

    /* TODO : ecrire un exit_failure pour le cas où pas de starting-point ?*/

    // argv[1] est le starting point


    if (strcmp(argv[3],"-name") == 0) {
           
        find_by_regex(argv[1],argv[4], P_regex);
        P_result = P_regex;

    }
    else if (strcmp(argv[3],"-size") == 0) {  

        find_by_taille(argv[1],argv[4],P_size);
        P_result = P_size;

    }
    else if (strcmp(argv[3],"-date") == 0) {  

        find_by_date(argv[1],argv[4],P_date);
        P_result = P_date;

    }
    

    for (int i =5;i<argc-1;i++){
        //executer la commande éventuellement
        if (strcmp(argv[i],"-name") == 0) {
            
            //find_by_name(argv[i-1],argv[i+1]);
  
            find_by_regex(argv[1],argv[i+1], P_regex);
            P_result = comparerPiles(P_regex,P_result);
            //affiche(P_regex);


        }
        else if (strcmp(argv[i],"-size") == 0) { 

            find_by_taille(argv[1],argv[i+1],P_size);
            P_result = comparerPiles(P_result,P_size);
            

        }
        else if (strcmp(argv[i],"-date") == 0) {   

            find_by_date(argv[1],argv[i+1],P_date);
            P_result = comparerPiles(P_result,P_date);

        }

        /* TODO: à enlever, faire cas d'erreur*/
        // else {
        //     printf("Le flag %s n'est pas correct",argv[i+1]);
        // }
        }

    affiche(P_result);

    free(P_date);
    free(P_regex);
    free(P_size);
    free(P_result);

    return 0;

}