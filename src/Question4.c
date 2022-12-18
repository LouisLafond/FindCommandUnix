#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include "Question1.h"


char* listeArg[] = {
        "-test",
        "-name",
        "-size",
        "-date",
        "-mime", 
        "-ctc",
        "-dir ",
        "-color",
        "-perm",
        "-link",
        "-threads",
        "-ou"
    };
    
int lenListArg = 12;


Pile * comparerPilesET(Pile *pile1, Pile *pile2){
    Pile *P_resultat = calloc(1,sizeof(Pile));

    Element *courant1;
    courant1 = pile1->debut;

    for(int i=0;i<pile1->taille;i++){
        Element *courant2;
        courant2 = pile2->debut;
        
        for(int j=0;j<pile2->taille;j++){
            if (strcmp(courant1->donnee,courant2->donnee) == 0) {
                empiler(P_resultat,courant1->donnee);
            }

            courant2 = courant2->suivant;            
        }

        courant1 = courant1->suivant;
    }

    return P_resultat;
}

Pile * comparerPilesOU(Pile *pile1, Pile *pile2){
    Pile *P_resultat = calloc(1,sizeof(Pile));

    Element *courant1;
    courant1 = pile1->debut;
    for (int i=0;i<pile1->taille;i++){
        empiler(P_resultat,courant1->donnee);
        courant1 = courant1->suivant;
    }
    
    Element *courant2;
    courant2 = pile2->debut;
    for(int j=0;j<pile2->taille;j++){
        
        if (contain(P_resultat, courant2->donnee) == 0) {
            
            empiler(P_resultat,courant2->donnee);

        }
        courant2 = courant2->suivant;            
    }
    
    
    return P_resultat;
}


int fonction_ET(int argc, char* argv[]) {

    Pile *P_result;
    Pile *P_regex;
    Pile *P_date;
    Pile *P_size;
    Pile *P_ctc;
    Pile *P_mime;
    Pile *P_perm;

    if (strcmp(argv[3],"-name") == 0) {
        
        if ((4 < argc)&&(estDansListe(lenListArg,argv[4],listeArg) == 0)) {
            P_regex = calloc(1,sizeof(Pile));
            find_by_regex(argv[1],argv[4],P_regex);
            P_result = P_regex;
        }
        else {
            printf("Entrez un paramètre pour le flag regex!\n");
            return 0;
        }   

    }
    else if (strcmp(argv[3],"-size") == 0) {  
        if ((4 < argc)&&(estDansListe(lenListArg,argv[4],listeArg) == 0)) {
            P_size = calloc(1,sizeof(Pile));
            find_by_taille(argv[1],argv[4],P_size);
            P_result = P_size;
        }
        else {
            printf("Entrez un paramètre pour le flag size!\n");
            return 0;
        } 

    }
    else if (strcmp(argv[3],"-date") == 0) {
        if ((4 < argc)&&(estDansListe(lenListArg,argv[4],listeArg) == 0)) {
            P_date = calloc(1,sizeof(Pile));
            find_by_date(argv[1],argv[4],P_date);
            P_result = P_date;
        }
        else {
            printf("Entrez un paramètre pour le flag date!\n");
            return 0;
        } 
    }
    else if (strcmp(argv[3],"-mime") == 0) {  
        if ((4 < argc)&&(estDansListe(lenListArg,argv[4],listeArg) == 0)) {
            P_mime = calloc(1,sizeof(Pile));
            find_by_mime(argv[1],argv[4],P_mime);
            P_result = P_mime;
        }
        else {
            printf("Entrez un paramètre pour le flag mime!\n");
            return 0;
        } 

    }
    else if (strcmp(argv[3],"-perm") == 0) {  
        if ((4 < argc)&&(estDansListe(lenListArg,argv[4],listeArg) == 0)) {
            P_perm = calloc(1,sizeof(Pile));
            find_by_perm(argv[1],argv[4],P_perm);
            P_result = P_perm;
        }
        else {
            printf("Entrez un paramètre pour le flag perm!\n");
            return 0;
        } 

    }
    else if (strcmp(argv[3],"-ctc") == 0) {  
       if ((4 < argc)&&(estDansListe(lenListArg,argv[4],listeArg) == 0)) {
            P_ctc = calloc(1,sizeof(Pile));
            find_by_ctc(argv[1],argv[4],P_ctc);
            P_result = P_ctc;
        }
        else {
            printf("Entrez un paramètre pour le flag ctc!\n");
            return 0;
        } 

    }


    for (int i = 5;i<argc;i++){
        if (strcmp(argv[i],"-name") == 0) {
            
            if ((i+1 < argc)&&(estDansListe(lenListArg,argv[i+1],listeArg) == 0)) {
                Pile *P_regex = calloc(1,sizeof(Pile));
                find_by_regex(argv[1],argv[i+1], P_regex);
                P_result = comparerPilesET(P_regex,P_result);
            }
            else {
                printf("Entrez un paramètre pour le flag regex!\n");
                depiler(P_result);
                return 0;
            } 
            
        }
        else if (strcmp(argv[i],"-size") == 0) { 
            if ((i+1 < argc)&&(estDansListe(lenListArg,argv[i+1],listeArg) == 0)) {
                Pile *P_size = calloc(1,sizeof(Pile));
                find_by_taille(argv[1],argv[i+1], P_size);
                P_result = comparerPilesET(P_size,P_result);
            }
            else {
                printf("Entrez un paramètre pour le flag size!\n");
                depiler(P_result);
                return 0;
            }
            
        }
        else if (strcmp(argv[i],"-date") == 0) {
            
            if ((i+1 < argc)&&(estDansListe(lenListArg,argv[i+1],listeArg) == 0)) {
                Pile *P_date = calloc(1,sizeof(Pile));
                find_by_date(argv[1],argv[i+1], P_date);
                P_result = comparerPilesET(P_date,P_result);
            }
            else {
                printf("Entrez un paramètre pour le flag date!\n");
                depiler(P_result);
                return 0;
            }
            
        }
        else if (strcmp(argv[i],"-mime") == 0) {
            
            if ((i+1 < argc)&&(estDansListe(lenListArg,argv[i+1],listeArg) == 0)) {
                Pile *P_mime = calloc(1,sizeof(Pile));
                find_by_mime(argv[1],argv[i+1], P_mime);
                P_result = comparerPilesET(P_mime,P_result);
            }
            else {
                printf("Entrez un paramètre pour le flag mime!\n");
                depiler(P_result);
                return 0;
            }
            
        }        
        else if (strcmp(argv[i],"-perm") == 0) {
            if ((i+1 < argc)&&(estDansListe(lenListArg,argv[i+1],listeArg) == 0)) {
                Pile *P_perm = calloc(1,sizeof(Pile));
                find_by_perm(argv[1],argv[i+1], P_perm);
                P_result = comparerPilesET(P_perm,P_result);
            }
            else {
                printf("Entrez un paramètre pour le flag perm!\n");
                depiler(P_result);
                return 0;
            }
            
            
            
        }
        else if (strcmp(argv[i],"-ctc") == 0) {
            
            if ((i+1 < argc)&&(estDansListe(lenListArg,argv[i+1],listeArg) == 0)) {
                Pile *P_ctc = calloc(1,sizeof(Pile));
                find_by_ctc(argv[1],argv[i+1], P_ctc);
                P_result = comparerPilesET(P_ctc,P_result);
            }
            else {
                printf("Entrez un paramètre pour le flag ctc!\n");
                depiler(P_result);
                return 0;
            }
            
        }

        
        
    }

    if ((P_result)&&(P_result->debut)) {
        affiche(P_result);
        depiler(P_result); 

    }
    

    return 1;

}



int fonction_OU(int argc, char* argv[]) {
    
    

    Pile *P_result;
    Pile *P_regex;
    Pile *P_date;
    Pile *P_size;
    Pile *P_ctc;
    Pile *P_mime;
    Pile *P_perm;
    if (strcmp(argv[3],"-name") == 0) {
        
        if ((4 < argc)&&(estDansListe(lenListArg,argv[4],listeArg) == 0)) {
            P_regex = calloc(1,sizeof(Pile));
            find_by_regex(argv[1],argv[4],P_regex);
            P_result = P_regex;
        }
        else {
            printf("Entrez un paramètre pour le flag regex!\n");
            return 0;
        } 
        

    }
    else if (strcmp(argv[3],"-size") == 0) {  
        if ((4 < argc)&&(estDansListe(lenListArg,argv[4],listeArg) == 0)) {
            P_size = calloc(1,sizeof(Pile));
            find_by_taille(argv[1],argv[4],P_size);
            P_result = P_size;
            
        }
        else {
            printf("Entrez un paramètre pour le flag size!\n");
            return 0;
        } 

    }
    else if (strcmp(argv[3],"-date") == 0) {
        if ((4 < argc)&&(estDansListe(lenListArg,argv[4],listeArg) == 0)) {
            P_date = calloc(1,sizeof(Pile));
            find_by_date(argv[1],argv[4],P_date);
            P_result = P_date;
        }
        else {
            printf("Entrez un paramètre pour le flag date!\n");
            return 0;
        } 
       

    }
    else if (strcmp(argv[3],"-mime") == 0) {
        if ((4 < argc)&&(estDansListe(lenListArg,argv[4],listeArg) == 0)) {
            P_mime = calloc(1,sizeof(Pile));
            find_by_mime(argv[1],argv[4],P_mime);
            P_result = P_mime;
        }
        else {
            printf("Entrez un paramètre pour le flag mime!\n");
            return 0;
        } 
       

    }    
    else if (strcmp(argv[3],"-perm") == 0) {  
        if ((4 < argc)&&(estDansListe(lenListArg,argv[4],listeArg) == 0)) {
            P_perm = calloc(1,sizeof(Pile));
            find_by_perm(argv[1],argv[4],P_perm);
            P_result = P_perm;
        }
        else {
            printf("Entrez un paramètre pour le flag perm!\n");
            return 0;
        } 

    }
    else if (strcmp(argv[3],"-ctc") == 0) {  
       if ((4 < argc)&&(estDansListe(lenListArg,argv[4],listeArg) == 0)) {
            P_ctc = calloc(1,sizeof(Pile));
            find_by_ctc(argv[1],argv[4],P_ctc);
            P_result = P_ctc;
        }
        else {
            printf("Entrez un paramètre pour le flag ctc!\n");
            return 0;
        } 

    }


    for (int i = 5;i<argc;i++){
        
        //executer la commande éventuellement
        if (strcmp(argv[i],"-name") == 0) {
            
            if ((i+1 < argc)&&(estDansListe(lenListArg,argv[i+1],listeArg) == 0)) {
                Pile *P_regex = calloc(1,sizeof(Pile));
                find_by_regex(argv[1],argv[i+1], P_regex);
                P_result = comparerPilesOU(P_regex,P_result);
            }
            else {
                printf("Entrez un paramètre pour le flag regex!\n");
                depiler(P_result);
                return 0;
            } 
            
        }
        else if (strcmp(argv[i],"-size") == 0) { 
            if ((i+1 < argc)&&(estDansListe(lenListArg,argv[i+1],listeArg) == 0)) {
                Pile *P_size = calloc(1,sizeof(Pile));
                find_by_taille(argv[1],argv[i+1], P_size);
                P_result = comparerPilesOU(P_size,P_result);
            }
            else {
                printf("Entrez un paramètre pour le flag size!\n");
                depiler(P_result);
                return 0;
            }
            
        }
        else if (strcmp(argv[i],"-date") == 0) {
            
            if ((i+1 < argc)&&(estDansListe(lenListArg,argv[i+1],listeArg) == 0)) {
                Pile *P_date = calloc(1,sizeof(Pile));
                find_by_date(argv[1],argv[i+1], P_date);
                P_result = comparerPilesOU(P_date,P_result);
                
            }
            else {
                printf("Entrez un paramètre pour le flag date!\n");
                depiler(P_result);
                return 0;
            }
            
        }
        else if (strcmp(argv[i],"-mime") == 0) {
            
            if ((i+1 < argc)&&(estDansListe(lenListArg,argv[i+1],listeArg) == 0)) {
                Pile *P_mime = calloc(1,sizeof(Pile));
                find_by_mime(argv[1],argv[i+1], P_mime);
                P_result = comparerPilesOU(P_mime,P_result);
                
            }
            else {
                printf("Entrez un paramètre pour le flag mime!\n");
                depiler(P_result);
                return 0;
            }
            
        }        
        else if (strcmp(argv[i],"-perm") == 0) {
            if ((i+1 < argc)&&(estDansListe(lenListArg,argv[i+1],listeArg) == 0)) {
                Pile *P_perm = calloc(1,sizeof(Pile));
                find_by_perm(argv[1],argv[i+1], P_perm);
                P_result = comparerPilesOU(P_perm,P_result);
            }
            else {
                printf("Entrez un paramètre pour le flag perm!\n");
                depiler(P_result);
                return 0;
            }
            
            
            
        }
        else if (strcmp(argv[i],"-ctc") == 0) {
            
            if ((i+1 < argc)&&(estDansListe(lenListArg,argv[i+1],listeArg) == 0)) {
                Pile *P_ctc = calloc(1,sizeof(Pile));
                find_by_ctc(argv[1],argv[i+1], P_ctc);
                P_result = comparerPilesOU(P_ctc,P_result);
            }
            else {
                printf("Entrez un paramètre pour le flag ctc!\n");
                depiler(P_result);
                return 0;
            }
            
        }
        
        
    }

    if ((P_result)&&(P_result->debut)) {
        affiche(P_result);
        depiler(P_result); 

    }
    

    return 1;

}
