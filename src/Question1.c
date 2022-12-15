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

//int check_starting_point(char *dir) {

//}

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

    
    
    


    if(argc < 3) { 
        // cas d'erreur ou pas assez d'arguments ou parcours arborescence
        if (argc == 2){ //parcours
            find_all_paths(argv[1]);
        }
        else {
            printf("Pas assez d'arguments ! Le format attendu est le suivant : ftc starting-point [-option [paramètre]]+ \n" );

        }
        
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
            Pile *P_regex = calloc(1,sizeof(Pile));
            //find_by_name(argv[i-1],argv[i+1]);
            find_by_regex(argv[i-1],argv[i+1], P_regex);
            affiche(P_regex);
            depiler(P_regex);


        }
        else if (strcmp(argv[i],"-size") == 0) {
            Pile *P_size = calloc(1,sizeof(Pile));
            find_by_taille(argv[i-1],argv[i+1],P_size);
            affiche(P_size);
            depiler(P_size);
            

        }
        else if (strcmp(argv[i],"-date") == 0) {
            Pile *P_date = calloc(1,sizeof(Pile));
            find_by_date(argv[i-1],argv[i+1],P_date);
            //affiche(P_date);
            depiler(P_date);

        }
        else if (strcmp(argv[i],"-et") == 0) {
            //printf("%d\n",argc);
            fonction_ET(argc,argv);
            
        }
        else if (strcmp(argv[i],"-dir") == 0) {
            Pile *P_dir = calloc(1,sizeof(Pile));
            
            if ((i+1 < argc)&&(estDansListe(lenListArg,argv[i+1],listeArg) == 0)) {
              
                find_by_dir(argv[i-1],argv[i+1],P_dir);

            }
            
            else {
               
                find_all_dirs(argv[i-1],P_dir);
            }
            affiche(P_dir);
            depiler(P_dir);


        }
        else if (strcmp(argv[i],"-mime") == 0) {
            Pile *P_mime = calloc(1,sizeof(Pile));
            find_by_mime(argv[i-1],argv[i+1],P_mime);
            affiche(P_mime);
            depiler(P_mime);
            

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