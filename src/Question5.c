
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

//recuperer les fichiers dont le dernier acces est entre la date actuelle - temps rentré en param 
int get_sign(char *param) {
    if (param[0] == '+') {
        return 1;
    }
    else {
        return 0;
    }
}



long double convert_to_seconds(char *param) {
    size_t l = strlen(param) - 1;
    char u = param[l];
    
    int temps = 0;
    
    if (get_sign(param) == 0) {
        temps = atoi(param);
       
    }
    else {
        temps = atoi(param + 1);
       

    }
    long double res = 0;
    if (u == 'm') {
        res = 60 * temps;
        return res;

    }
    else if (u == 'h') {
        res =  60 * 60 * temps;
        return (long double)res;

            
    }
    else if (u == 'j') {
        res = 24 * 60 * 60 * temps;
        return (long double)res;
    }
    else {
        
        
        printf("Entrer l'unité/la bonne unité\n");
        return 0;
        
    }
}


void find_by_date(char *dir,char *param) {
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
                long double temps_param = convert_to_seconds(param);
                long double temps_actuel = time(NULL);
                struct stat sb;
                if (get_sign(param) == 1) {
                    //fichier dont date acces > param
                    if (temps_param >0) {
                        //chercher date acces fichier path
                        if (stat(path,&sb)!= -1) {
                            long double tfichier = (long double) sb.st_atime;
                            long double diff_time = temps_actuel-tfichier;
                            
                            if (diff_time > temps_param) {
                                
                                printf("%s\n",path);

                            }

                        }

                    }
                    

                }
                
                else {
                    if (temps_param >0) {
                        if (stat(path,&sb)!= -1) {
                            //fichier temps =<
                            long double tfichier = (long double) sb.st_atime;
                            long double diff_time = temps_actuel-tfichier;
                            
                            if (diff_time <= temps_param) {
                                
                                printf("%s\n",path);

                            }

                            
                        }    
                    }
                }
            }
            //sinon dossier
            else {
                find_by_date(path,param);
                free(n);
                free(path);
            }
        }
    }
}
