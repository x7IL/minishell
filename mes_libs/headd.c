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
    FILE* ptr = fopen(separateur_option(fichier,0), "r");
    //printf("normalement\n");
    if(ptr != NULL) {
        while (fgets(str, sizeof(str), ptr)) {
            printf("%s", str);
            i++;
            if (n == i) {
                break;
            }
        }
    }
    else{
        printf("fichier introuvable ou pas dans le repertoire");
    }
    //printf("fin\n");
    fclose(ptr);
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