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
        
        for(int j=0;j<pile2->taille;++j){
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
    
    

    Pile *P_result;
    Pile *P_regex;
    Pile *P_date;
    Pile *P_size;
    Pile *P_dir;


    /* TODO : ecrire un exit_failure pour le cas où pas de starting-point ?*/

    // argv[1] est le starting point

    

    if (strcmp(argv[3],"-name") == 0) {
        
        P_regex = calloc(1,sizeof(Pile));
        find_by_regex(argv[1],argv[4], P_regex);
        P_result = P_regex;
        

    }
    else if (strcmp(argv[3],"-size") == 0) {  
        P_size = calloc(1,sizeof(Pile));
        find_by_taille(argv[1],argv[4],P_size);
        P_result = P_size;

    }
    else if (strcmp(argv[3],"-date") == 0) {  
        P_date = calloc(1,sizeof(Pile));
        find_by_date(argv[1],argv[4],P_date);
        P_result = P_date;

    }
    else if (strcmp(argv[3],"-dir") == 0) {  
        P_dir = calloc(1,sizeof(Pile));
        find_by_date(argv[1],argv[4],P_dir);
        P_result = P_dir;

    }

   
    //printf("%d\n",argc);

    for (int i = 5;i<argc;i++){
        
        //executer la commande éventuellement
        if (strcmp(argv[i],"-name") == 0) {
            
            
            Pile *P_regex = calloc(1,sizeof(Pile));
  
            find_by_regex(argv[1],argv[i+1], P_regex);
            P_result = comparerPiles(P_regex,P_result);
            //affiche(P_regex);


        }
        else if (strcmp(argv[i],"-size") == 0) { 
            
            Pile *P_size = calloc(1,sizeof(Pile));

            find_by_taille(argv[1],argv[i+1],P_size);
            P_result = comparerPiles(P_result,P_size);
            

        }
        else if (strcmp(argv[i],"-date") == 0) {
            
            
            Pile *P_date = calloc(1,sizeof(Pile));   

            find_by_date(argv[1],argv[i+1],P_date);
            P_result = comparerPiles(P_result,P_date);
            

        }
        else if (strcmp(argv[3],"-dir") == 0) {  
            Pile *P_dir = calloc(1,sizeof(Pile));
            find_by_dir(argv[1],argv[4],P_dir);
            P_result = comparerPiles(P_result,P_dir);
        }

        
    }

    if ((P_result)&&(P_result->debut)) {
        affiche(P_result);
        depiler(P_result); 

    }
    

    

    return 0;

}