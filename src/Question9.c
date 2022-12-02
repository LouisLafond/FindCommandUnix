#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include "Question9.h"


void find_by_dir(char *dirname,char *dir, Pile *pileName) {
    DIR *dirp;
    struct dirent *dp;
    dirp = opendir(dirname);
    //empiler(pileName,dirname);
    while((dp = readdir(dirp)) != NULL) {
        if ((strcmp(dp->d_name,".") != 0) && (strcmp(dp->d_name,"..") != 0)) {
            char *n = strdup(dp->d_name);
            size_t l = strlen(dirname) + 1 + strlen(n) + 2;
            char *path = malloc(l*sizeof(char));
            size_t m = strlen(dirname);

            if (dirname[m-1] == '/') {
                strcpy(path,dirname);
                strcat(path,n);
                //printf("%s\n",path);

            }

            else {
                strcpy(path,dirname);
                strcat(path,"/");
                strcat(path,n);
                
            }

            if (dp->d_type == DT_DIR) {
               
                if (strcmp(n,dir) == 0) {
                    empiler(pileName,path);
                    

                }
                find_by_dir(path,dir,pileName);
                free(n);
                free(path);

                

            }
            
        } 
    }

    closedir(dirp);
    

}


void find_all_dirs(char *name,Pile *P) {
    DIR *dirp;
    struct dirent *dp;
    dirp = opendir(name);
    
    while((dp = readdir(dirp)) != NULL) {
        if ((strcmp(dp->d_name,".") != 0) && (strcmp(dp->d_name,"..") != 0)) {
            char *n = strdup(dp->d_name);
            size_t l = strlen(name) + 1 + strlen(n) + 2;
            char *path = malloc(l*sizeof(char));
            size_t m = strlen(name);

            if (name[m-1] == '/') {
                strcpy(path,name);
                strcat(path,n);
                //printf("%s\n",path);

            }

            else {
                strcpy(path,name);
                strcat(path,"/");
                strcat(path,n);
                //printf("%s\n",path);
            }

            if (dp->d_type == DT_DIR) {
                empiler(P,path);
                //printf("%s\n",path);
                find_all_dirs(path,P);
                free(n);
                
                

            }
            
        } 
    }

    closedir(dirp);
    

}
