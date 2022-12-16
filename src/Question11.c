#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "Question11.h"

char * val_octal(unsigned long mode) {
    char *perm = malloc(3*sizeof(char));
    int decg = 1;
    while (decg < 4) {
        int dec_in = 1;
        char bitg[4];
        
        while (dec_in < 4) {
            int res = mode && 1;
            char num[3];
            sprintf(num,"%d",res); //conversion int en char*
            
            bitg[dec_in - 1] = num[0];
            mode = mode >> 1; 
            dec_in++;

        }
       
        //recup valeur octale
        int valg = 0;
        for (int i = 0;i<strlen(bitg);i++) {
            if (bitg[i] == '1') {
                //puissance de 2
                int p = 1;
                for (int y=0;y<i;y++) {
                    p *= 2;

                }

                valg += p;
                
            }
        }
        //printf("%d\n",valg);
        char resg[3];
        sprintf(resg,"%d",valg);//conversion int en char*
        //printf("%s\n",resg);
        perm[3-decg]  = resg[0];
        decg++;
        
    }
    return perm;
    
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
                    //printf("Mode: %lo (octal)\n",mode);
                    char* perm = val_octal(mode);
                    
                    if (strcmp(perm,param) == 0) {
                        empiler(P,path);
                    }
                    free(perm);
                    
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


