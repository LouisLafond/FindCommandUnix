#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

int main(int argc,char *argv[]) {
    char *dir = strdup("..");
    char *n = strdup("Jeu.java");
    //find_all_paths(dir);
    int res = find_by_name(dir,n);
    printf("%d\n",res);
    free(n);
    free(dir);
    

    return 0;

}
