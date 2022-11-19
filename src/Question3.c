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
            if (dp->d_type == DT_DIR) {
                
            
                //printf("%s\n",path);
                int res = find_by_name(path,name);
                
                if (res == 1) {
                    
                    return 1;
                }
                free(n);
                free(path);
                
            }
            else {
                if (dp->d_type == DT_REG) {
                    if (strcmp(n,name) == 0) {
                        printf("%s\n",path);
                        free(n);
                        return 1;
                    }

                }
                free(n);
            }
        }
        
    }
    return 0;


}

int begin_by_sign(char *param) {
    if (param[0] == '+') {
        return 2;
    }
    else if (param[0] == '-') {
        return 1;
    }
    else {
        return 0;
    }
}



long double convert(char *param) {
    size_t l = strlen(param) - 1;
    char u = param[l];
    
    int size = 0;
    
    if (begin_by_sign(param) == 0) {
        size = atoi(param);
       
    }
    else {
        size = atoi(param + 1);
       

    }
    long double res = 0;
    if (u == 'k') {
        res = 1024 * size;
        return res;

    }
    else if (u == 'M') {
        res =  1024 * 1024 * size;
        return (long double)res;

            
    }
    else if (u == 'G') {
        res = 1024 * 1024 * 1024 * size;
        return (long double)res;
    }
    else {
        if (u == 'c') {
            res = (long double) size;
            return res;

        }
        else {
            printf("Entrer l'unité/la bonne unité\n");
            return 0;
        }
        

    }
    

}



void find_by_taille(char *dir,char *param) {
    DIR *dirp;
    struct dirent *dp;
    dirp = opendir(dir);
    
    while ((dp = readdir(dirp)) != NULL) {
        
        if ((strcmp(dp->d_name,".") != 0)&&(strcmp(dp->d_name,"..") != 0)) {
            char *n = strdup(dp->d_name);
           
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
            
            //si fichier
            if (dp->d_type == DT_REG) {
                //printf("%s\n",path);
                long double taille_param = convert(param);
                struct stat sb;
                if (begin_by_sign(param) == 2) {
                    //fichier dont taille >
                    if (taille_param >0) {
                        //chercher taille fichier path
                        if (stat(path,&sb)!= -1) {
                            long double tfichier = (long double) sb.st_size;
                            if (tfichier > taille_param) {
                                printf("%s\n",path);

                            }

                        }

                    }
                    

                }
                else if (begin_by_sign(param) == 1) {
                    //fichier taille <
                    if (taille_param >0) {
                        if (stat(path,&sb)!= -1) {
                            long double tfichier = (long double) sb.st_size;
                            if (tfichier < taille_param) {
                                printf("%s\n",path);

                            }

                        }

                        
                    }

                } 
                else {
                    if (taille_param >0) {
                        if (stat(path,&sb)!= -1) {
                            //fichier taille ==
                            long double tfichier = (long double) sb.st_size;
                            if (tfichier == taille_param) {
                                printf("%s\n",path);

                            }

                        }

                        
                    }

                }

            }
            //sinon dossier
            else {
                find_by_taille(path,param);
                free(n);
                free(path);


            }

        }

    }



}




