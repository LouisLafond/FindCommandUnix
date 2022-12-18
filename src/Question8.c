#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <regex.h>

#include "Question8.h"


int suit_regex_ctc(char *n,char *param) {
    int v;
    regex_t re;
    v = regcomp(&re,param,0);
    v = regexec(&re,n,0,NULL,0);
    return v;
}

int search_in_file(char * filename,char *param) {
    FILE *f = fopen(filename,"r");
    struct stat sb;
    if (stat(filename,&sb)!= -1) {
        char *tampon = malloc(sb.st_size);
        size_t size = sb.st_size / sizeof(char);
        while (!feof(f)) {
            fgets(tampon,size,f);
            
            if (suit_regex_ctc(tampon,param) == 0) {
                    
                    fclose(f);
                    return 1;
            }
        }
        free(tampon);
    }
      
    fclose(f);
    return 0;
    
}



void find_by_ctc(char *dir,char *param,Pile *P) {
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
                int v =  search_in_file(path,param);  
                if (v == 1) {
                    
                    empiler(P,path);
                }
            }
            //sinon dossier
            else {
                
                find_by_ctc(path,param,P);
                free(n);
                free(path);
            }
        }
    }
    closedir(dirp);
}


