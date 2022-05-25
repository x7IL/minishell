//
// Created by wx on 23/05/2022.
//

#include "../include/mes_libs.h"

void cat(char * option){

        //printf("%s\n",pwd());
    char str[256];
    FILE* ptr = fopen(option, "r");
    if(ptr != NULL) {
        while (fgets(str, sizeof(str), ptr)) {
            printf("%s", str);
        }
    }
    else{
        printf("le fichier n'a pas été trouvé\n");
    }

    //printf("fin\n");
    fclose(ptr);

}