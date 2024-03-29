#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>


void find_all_paths(char *name) {
    DIR *dirp;
    struct dirent *dp;
    dirp = opendir(name);
    printf("%s\n",name);
    while((dp = readdir(dirp)) != NULL) {
        if ((strcmp(dp->d_name,".") != 0) && (strcmp(dp->d_name,"..") != 0)) {
            char *n = strdup(dp->d_name);
            size_t l = strlen(name) + 1 + strlen(n) + 2;
            char *path = malloc(l*sizeof(char));
            size_t m = strlen(name);

            if (name[m-1] == '/') { //former un path correct syntaxiquement
                strcpy(path,name);
                strcat(path,n);
            }
            else {
                strcpy(path,name);
                strcat(path,"/");
                strcat(path,n);
                
            }

            if (dp->d_type == DT_REG) {
                printf("%s\n",path);
                free(n);

            }
            else {
                find_all_paths(path);
                free(n);
                free(path);

            }
        } 
    }

    closedir(dirp);
    

}

