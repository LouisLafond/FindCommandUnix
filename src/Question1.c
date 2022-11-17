#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

int estDansListe(int len, char* mot, char* listeArg[]) {
    int r = 0;

    for (int i = 0; i < len; i++) {
        if (strcmp(listeArg[i],mot) == 0) {
            r+=1;
        };
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
        "-dir "
    };
    int lenListArg = 7;

    if(argc < 2) { // cas d'erreur où pas assez d'arguments
        printf("Pas assez d'arguments ! Le format attendu est le suivant : ftc starting-point [-option [paramètre]] \n" );
        return EXIT_FAILURE;
    }

    /* TODO : ecrire un exit_failure pour le cas où pas de starting-point ?*/

    // argv[1] est le starting point


    for (int j = 2; j < argc; j++) {
        // printf("Argument %d is: %s\n", i, argv[i]);

        if (strcmp(argv[j],"-test") == 0 ) {
            for (int i = 1; i < argc-1; i++) { /* i < argc-1 car on veut pas que le dernier arg soit pris pour option, ie meme si option, sera consiéré comme valeur du flag, voir test ./main1 -test -name -ctc*/
                
                if ((strcmp(argv[i],"-name") == 0) && !estDansListe(lenListArg, argv[i+1],listeArg)) {
                printf("La valeur du flag %s est %s", argv[i],argv[i+1]); /* afficher "La valeur du flag -xxxx est yyyy" , en vérifiant qu'un argument est bien passé*/

                }

                if ((strcmp(argv[i],"-size") == 0) && !estDansListe(lenListArg, argv[i+1],listeArg)) {
                printf("La valeur du flag %s est %s", argv[i],argv[i+1]); /* afficher "La valeur du flag -xxxx est yyyy" */

                }

                if ((strcmp(argv[i],"-date") == 0) && !estDansListe(lenListArg, argv[i+1],listeArg)) {
                printf("La valeur du flag %s est %s", argv[i],argv[i+1]); /* afficher "La valeur du flag -xxxx est yyyy" */

                }

                if ((strcmp(argv[i],"-mime") == 0) && !estDansListe(lenListArg, argv[i+1],listeArg)) {
                printf("La valeur du flag %s est %s", argv[i],argv[i+1]); /* afficher "La valeur du flag -xxxx est yyyy" */

                }   

                if ((strcmp(argv[i],"-ctc") == 0) && !estDansListe(lenListArg, argv[i+1],listeArg)) {
                printf("La valeur du flag %s est %s", argv[i],argv[i+1]); /* afficher "La valeur du flag -xxxx est yyyy" */

                }    

                if ((strcmp(argv[i],"-dir") == 0) && !estDansListe(lenListArg, argv[i+1],listeArg)) {
                printf("La valeur du flag %s est %s", argv[i],argv[i+1]); /* afficher "La valeur du flag -xxxx est yyyy" */

                }    



                /* cas d'erreur ./main1 -test -name -ctc */
                if ((strcmp(argv[i],"-test") != 0) && estDansListe(lenListArg, argv[i],listeArg) && estDansListe(lenListArg, argv[i+1],listeArg)) {
                    printf( "Il manque un paramètre entre deux options !"); 
                    return EXIT_FAILURE;
                }  
            }

         /* cas d'erreur ./main1 -test */
        if ((strcmp(argv[j],"-test") == 0) && (argc<4)) {
            printf( "Il manque une option ou un paramètre d'option!"); 
            return EXIT_FAILURE;
        }           

        if (estDansListe(lenListArg, argv[argc-1],listeArg)) {
            printf( "Il manque une option ou un paramètre d'option!"); 
            return EXIT_FAILURE;
        }  


        }
    }

    if(!estDansListe(argc,"-test", argv)) {  /* pour executer instructions si il n'y a pas le -test*/
        printf("L'option -test n'est pas saisie. \n");
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