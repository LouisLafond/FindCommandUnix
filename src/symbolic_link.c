#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "symbolic_link.h"

void find_by_link(char *dir,Pile *P) {
    DIR *dirp;
    struct dirent *dp;
    dirp = opendir(dir);
    while ((dp = readdir(dirp)) != NULL) {
        if ((strcmp(dp->d_name,".") != 0)&&(strcmp(dp->d_name,"..") != 0)) {
            char *n = strdup(dp->d_name); 
            size_t l = strlen(dir) + 1 + strlen(n) + 2;
            char *path = malloc(l*sizeof(char));
            size_t m = strlen(dir);
            if (dir[m-1] =='/') {
                strcpy(path,dir);
                strcat(path,n);
            }
            else {
                strcpy(path,dir);
                strcat(path,"/");
                strcat(path,n);
                
            }
            
            //si fichier
            if (dp->d_type == DT_LNK) {
                
                empiler(P,path); 
            }
            //sinon dossier
            else if (dp->d_type == DT_DIR) {
                find_by_link(path,P);
                free(n);
                free(path);
            }
        }
    }
    closedir(dirp);
}

