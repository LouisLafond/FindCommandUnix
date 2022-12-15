#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

/*
https://httpd.apache.org/docs/2.4/fr/mod/mod_mime_magic.html
https://github.com/kobbyowen/MegaMimes

*/
#include "MegaMimes.h"

#include "Question7.h"

int mime_type(char *type){  //retourne 1 si '/' dans nom donné, 0 si pas de '/'
    int val = 0;
    if(strchr(type, '/') != NULL)
    {
        val = 1;
    }
    return val;
};

char *type_only(const char *typemime){
    
    int t = strlen(typemime)-1;
    
    while (typemime[t] != '/')
    {
        t--;
    }
    
    char *res = malloc((t-1) * sizeof(char));
    
    for(int j=0; j<t; j++)
    {
        res[j]=typemime[j];
    }

    return res;

}


void find_by_mime(char *dir,char *param,Pile *P) {

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

                const char* mimetype = getMegaMimeType(path);
                if(mimetype != NULL){
                    if (mime_type(param)){ //si '/' dans le type donné

                        if (strcmp(mimetype,param) == 0){
                            empiler(P,path);
                        }
                    }                       
                            
                    else{
                        char *retour = type_only(mimetype);
                        if (strcmp(retour,param) == 0){
                            empiler(P,path);

                        }
                    }

                }
            }
            //sinon dossier
            else {
                
                find_by_mime(path,param,P);
                free(n);
                free(path);
            }

        }
    }
    closedir(dirp);
}
