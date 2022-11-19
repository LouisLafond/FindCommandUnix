#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include "Question1.h"

int estDansListe(int len, char* mot, char* listeArg[]) {
    int r = 0;

    for (int i = 0; i < len; i++) {
        if (strcmp(listeArg[i],mot) == 0) {
            r = 1;
            break;
        }
    }
    return r;
    
}

int parse_command(int argc, char* argv[]) {

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

    if(argc < 3) { // cas d'erreur où pas assez d'arguments
        printf("Pas assez d'arguments ! Le format attendu est le suivant : ftc starting-point [-option [paramètre]]+ \n" );
        return EXIT_FAILURE;
    }

    /* TODO : ecrire un exit_failure pour le cas où pas de starting-point ?*/

    // argv[1] est le starting point

    int i = 2;
    if (strcmp(argv[i],"-test") == 0) {
        if (estDansListe(lenListArg,argv[i+1],listeArg) == 1) {
            printf("La valeur du flag %s est %s",argv[i+1],argv[i+2]);
        }
        else {
            printf("Le flag %s n'est pas correct",argv[i+1]);
        }
    }
    else {
        //executer la commande éventuellement
        if (strcmp(argv[i],"-name") == 0) {
            find_by_name(argv[i-1],argv[i+1]);

        }
        else if (strcmp(argv[i],"-size") == 0) {
            find_by_taille(argv[i-1],argv[i+1]);
            

        }
        else {
            printf("Le flag %s n'est pas correct",argv[i+1]);
        }
    }

    

    return 0;
}



// pour test:
/*

./Question1 
./Question1 starting_point
./Question1 starting_point -ctc 78 ;
./Question1 starting_point -test -name zdzcd -ctc dsfv
./Question1 starting_point -test -name -ctc
./Question1 starting_point -name 9985 -test 
./Question1 starting_point -test -name
./Question1 starting_point -test // prévoir quoi faire si juste -test (erreur ...)

*/
    
// les arguments à tester
/*
-test
-name
-size 
-date
-mime 
-ctc 
-dir 
*/