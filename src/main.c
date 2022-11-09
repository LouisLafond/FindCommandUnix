#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

int main(int argc,char *argv[]) {
    char *name = strdup(".");
    
    find_all_paths(name);
    
    free(name);
    return 0;

}
