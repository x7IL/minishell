//
// Created by wx on 19/05/2022.
//

#include"../include/mes_libs.h"

void Mkdir(char *option) {
    //printf("[%s]\n",option);

    int boolean = 0;

    DIR *rep = opendir ("." );
    //printf("[%s]\n",option);
    if (rep != NULL){
        struct dirent *lecture;
        while ((lecture = readdir(rep))){
            struct stat st;
            stat (lecture->d_name, &st);{
                if(compare(lecture->d_name,option) == 0){
                    boolean = 1;
                }
                if(boolean == 1){
                    printf("Le nom du fichier existe deja\n");
                    break;
                }
            }
        }
        if(boolean == 0){
            FILE *fp;
            fp  = fopen (option, "w");
            fclose(fp);
        }
        closedir(rep), rep = NULL;
    }
}