#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>


void find_all_paths(char *name) {
    DIR *dirp;
    struct dirent *dp;
    
    dirp = opendir(name);
    

    //printf("%s\n",name);
    
    while((dp = readdir(dirp)) != NULL) {
        if ((strcmp(dp->d_name,".") != 0)&&(strcmp(dp->d_name,"..") != 0)) {
            char *n = strdup(dp->d_name);
                
            size_t l = strlen(name) + 1 + strlen(n) + 2;
            char *path = malloc(l*sizeof(char));
            if (strcmp(name,"/") == 0) {
                strcpy(path,name);
                strcat(path,n);
                printf("%s\n",path);

            }
            else {
                strcpy(path,name);
                strcat(path,"/");
                strcat(path,n);
                printf("%s\n",path);

            }

            
            
            if ((dp->d_type == DT_DIR)) {
                
                find_all_paths(path);
                free(n);
                free(path);

            }
            else {
                free(n);
                free(path);

            }

        }
        
    
    }
    closedir(dirp);
    

}

int main() {
    char *name = strdup(".");
    
    find_all_paths(name);
    
    free(name);
    return 0;

}