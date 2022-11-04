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

int main(int argc, char* argv[]) {

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

    if(argc < 2) {
        fprintf(stdout, "Pas assez d'arguments ! Le format attendu est le suivant : ftc starting-point [-option [paramètre]] \n" );
        return EXIT_FAILURE;
    }

    /* TODO : ecrire un exit_failure pour le cas où pas de starting-point ?*/

    for (int j = 1; j < argc; j++) {
        // printf("Argument %d is: %s\n", i, argv[i]);

        if (strcmp(argv[j],"-test") == 0 ) {
            for (int i = 1; i < argc-1; i++) { /* i < argc-1 car on veut pas que le dernier arg soit pris pour option, ie meme si option, sera consiéré comme valeur du flag, voir test ./main1 -test -name -ctc*/
                
                if ((strcmp(argv[i],"-name") == 0) && !estDansListe(lenListArg, argv[i+1],listeArg)) {
                fprintf(stdout, "La valeur du flag %s est %s. \n", argv[i],argv[i+1]); /* afficher "La valeur du flag -xxxx est yyyy" , en vérifiant qu'un argument est bien passé*/

                }

                if ((strcmp(argv[i],"-size") == 0) && !estDansListe(lenListArg, argv[i+1],listeArg)) {
                fprintf(stdout, "La valeur du flag %s est %s. \n", argv[i],argv[i+1]); /* afficher "La valeur du flag -xxxx est yyyy" */

                }

                if ((strcmp(argv[i],"-date") == 0) && !estDansListe(lenListArg, argv[i+1],listeArg)) {
                fprintf(stdout, "La valeur du flag %s est %s. \n", argv[i],argv[i+1]); /* afficher "La valeur du flag -xxxx est yyyy" */

                }

                if ((strcmp(argv[i],"-mime") == 0) && !estDansListe(lenListArg, argv[i+1],listeArg)) {
                fprintf(stdout, "La valeur du flag %s est %s. \n", argv[i],argv[i+1]); /* afficher "La valeur du flag -xxxx est yyyy" */

                }   

                if ((strcmp(argv[i],"-ctc") == 0) && !estDansListe(lenListArg, argv[i+1],listeArg)) {
                fprintf(stdout, "La valeur du flag %s est %s. \n", argv[i],argv[i+1]); /* afficher "La valeur du flag -xxxx est yyyy" */

                }    

                if ((strcmp(argv[i],"-dir") == 0) && !estDansListe(lenListArg, argv[i+1],listeArg)) {
                fprintf(stdout, "La valeur du flag %s est %s. \n", argv[i],argv[i+1]); /* afficher "La valeur du flag -xxxx est yyyy" */

                }    



                /* cas d'erreur ./main1 -test -name -ctc */
                if ((strcmp(argv[i],"-test") != 0) && estDansListe(lenListArg, argv[i],listeArg) && estDansListe(lenListArg, argv[i+1],listeArg)) {
                    fprintf(stdout," Il manque un paramètre entre deux options !"); 
                    return EXIT_FAILURE;
                }  
        /* cas d'erreur ./main1 -test */
        if ((strcmp(argv[j],"-test") == 0) && (argc<4)) {
            fprintf(stdout," Il manque une option ou un paramètre d'option!"); 
            return EXIT_FAILURE;
        }
            }

        }
    }

    if(!estDansListe(argc,"-test", argv)) {  /* pour executer instructions si il n'y a pas le -test*/
        printf("L'option -test n'est pas saisie. \n");
    }

    return 0;
}

/*
-test
-name
-size 
-date
-mime 
-ctc 
-dir 
*/