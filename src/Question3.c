#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
//si le fichier est dans l'aborescence return 1 sinon 0
int find_by_name(char *dir,char *name) { 
    DIR *dirp;
    struct dirent *dp;
    dirp = opendir(dir);
    if (strcmp(dir,name) == 0) {
        
        return 1;
    }
    while ((dp = readdir(dirp)) != NULL) {
        if ((strcmp(dp->d_name,".") != 0)&&(strcmp(dp->d_name,"..") != 0)&&((dp->d_type == DT_REG)||(dp->d_type == DT_DIR))) {
            char *n = strdup(dp->d_name);
            if (dp->d_type == DT_DIR) {
                
                size_t l = strlen(dir) + 1 + strlen(n) + 2;
                char *path = malloc(l*sizeof(char));
                if (strcmp(dir,"/") == 0) {
                    strcpy(path,dir);
                    strcat(path,n);
                }
                else {
                    strcpy(path,dir);
                    strcat(path,"/");
                    strcat(path,n);
                
                }
                //printf("%s\n",path);
                int res = find_by_name(path,name);
                
                if (res == 1) {
                    printf("%s\n",path);
                    return 1;
                }
                free(n);
                free(path);
                
            }
            else {
                if (dp->d_type == DT_REG) {
                    if (strcmp(n,name) == 0) {
                        return 1;
                    }

                }
                free(n);
            }
        }
        
    }
    return 0;


}

//int find_by_taille(char *taille) {

//}

int main() {
    char * dir = strdup("..");
    char * name = strdup("Jeu.java");
    int res = find_by_name(dir,name);
    //printf("%d\n",res);
    if (res == 1) {
        printf("Le fichier existe\n");

    }
    else {
        printf("Le fichier n'existe pas\n");

    }
    free(dir);
    free(name);
    return 0;

    
}



