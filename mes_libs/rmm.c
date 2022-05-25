//
// Created by wx on 24/05/2022.
//

#include "../include/mes_libs.h"

void rmm(char * option){
    FILE * file = fopen(option,"r");
    printf("[%s]\n",option);
    if(file == NULL){
        printf("le fichier n'existe pas\n");
    }
    else{
        remove(option);
    }
    fclose(file);
}

void Rmdir(char * option){
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
                    rmdir(option);
                    break;
                }
            }
        }
        if(boolean == 0){
            printf("le dossier n'existe pas\n");
        }
    }
}