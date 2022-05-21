//
// Created by wx on 22/05/2022.
//

#include "../include/mes_libs.h"


void head(char * fichier){
    char str[256];
    int i = 0;
    int n = atoi(separateur_option(fichier,1));
    if(n==0){
        n=10;
    }
    //printf("[%s] [%d]\n",separateur_commande(fichier,0),n);
    int boolean = 0;

    DIR *rep = opendir ("." );
    //printf("[%s]\n",option);
    if (rep != NULL){
        struct dirent *lecture;
        while ((lecture = readdir(rep))){
            struct stat st;
            stat (lecture->d_name, &st);{
                if(compare(lecture->d_name,separateur_option(fichier,0)) == 0){
                    boolean = 1;
                }
                if(boolean == 1){
                    FILE* ptr = fopen(separateur_option(fichier,0), "r");
                    //printf("normalement\n");
                    while (fgets(str, sizeof(str), ptr)) {
                        printf("%s", str);
                        i++;
                        if(n==i){
                            break;
                        }
                    }
                    //printf("fin\n");
                    fclose(ptr);
                    break;
                }
            }
        }
        if(boolean == 0){
            printf("le fichier entré, n'existe pas où ne se toruve pas dans le directoire \n");
        }
    }
}

void history(){
    //printf("%s\n",pwd());
    char str[256];
    int i = 0;
    FILE* ptr = fopen("my_history.txt", "r");
    //printf("normalement\n");
    while (fgets(str, sizeof(str), ptr)) {
        printf("%s", str);
        i++;
        if(10==i){
            break;
        }
    }
    //printf("fin\n");
    fclose(ptr);
}