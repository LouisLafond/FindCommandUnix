#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "perm.h"


//conversion base 10 en octal
int val_to_octal(unsigned long mode) {
    unsigned long octal = 0;
    int i = 1;
    while (mode != 0) {
        octal += (mode % 8) * i;
        mode = mode / 8;
        i = i * 10;

    }
    
    int res = octal % 1000;
    return res;



}


void find_by_perm(char *dir,char *param,Pile *P) {
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
                struct stat sb;
                if (stat(path,&sb)!= -1) {
                    unsigned long mode = (unsigned long)sb.st_mode;
                    
                    int perm = val_to_octal(mode);
                    int comp = atoi(param);
                    
                    if (comp == perm) {
                        empiler(P,path);
                    }
                    
                    
                    
                }
                
            }
            //sinon dossier
            else {
                
                find_by_perm(path,param,P);
                free(n);
                free(path);
            }
        }
    }
    closedir(dirp);
}


