#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <regex.h>

#include "Question6.h"


int suit_regex(char *filename,char *param) {
    int v;
    regex_t re;
    v = regcomp(&re,param,0);
    v = regexec(&re,filename,0,NULL,0);
    
    return v;
}
void find_by_regex(char *dir,char *param,Pile *P) {
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
            if (dp->d_type == DT_REG) {
                int v = suit_regex(n,param);
                if (v == 0) {
                    printf("%s\n",path);
                    empiler(P,path);

                }
                //printf("%s\n",path);

            }
            //sinon dossier
            else {
                find_by_regex(path,param,P);
                free(n);
                free(path);
            }
        }
    }
}

