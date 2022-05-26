//
// Created by wx on 26/05/2022.
//

#include "../include/mes_libs.h"

int droit(char * option){
    if(option[0] != '\0') {
        char homee[200];
        mon_strcpy(homee, getenv("PWD"));
        mon_strcat3(homee, "/passwd.txt");
        homee[mon_len(homee)-1] = '\0';
        //printf("[%s]\n", homee);
        FILE *pass = fopen(homee, "r");
        char str[256];
        while (fgets(str, sizeof(str), pass)) {
            if (compare(separateur_option(str, 0), separateur_option(option, 0)) == 0) {
                if (compare(separateur_option(str, 1), separateur_option(option, 1)) == 0) {
                    return 743;
                } else {
                    printf("mot de passe incorrecte\n");
                    return 84;
                }
            }
        }
    }
    return 778;
}