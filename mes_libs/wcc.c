//
// Created by wx on 23/05/2022.
//

#include "../include/mes_libs.h"

int wc(char *option){

    char str[256];
    FILE* ptr = fopen(separateur_option(option,0), "r");
    int caractere = 0;
    int lignes = 0;

    if(ptr != NULL) {
        int word = 0;

        while (fgets(str, sizeof(str), ptr)) {
            for(int j = 0; str[j]!='\0';j++){
                caractere++;
                if (str[j] == ' ' && str[j+1] != ' ')
                    word++;
            }
            lignes++;
        }
        //printf("caracteres : %d     lignes : %d    mot : %d\n",caractere,lignes,word);
        if(separateur_compteur_option(option)>=1) {
            for (int i = 1; i < separateur_compteur_option(option) + 1; i++) {
                //printf("[%s]\n", separateur_option(option,i));
                if (compare(separateur_option(option, i), "-l") == 0) {
                    //printf("%d ", lignes);
                    return lignes;
                } else if (compare(separateur_option(option, i), "-w") == 0) {
                    //printf("%d ", word);
                    return word;
                } else if (compare(separateur_option(option, i), "-c") == 0) {
                    //printf("%d", caractere);
                    return caractere;
                } else {
                    printf("l'option n'existe pas");
                }
            }
        }
        else{
            printf("lignes : %d ", lignes);
            printf("mots : %d ", word);
            printf("caracteres : %d \n", caractere);

        }
        printf("\n");
    }
    else{
        printf("le fichier n'a pas été trouvé\n");
    }
    return 0;
    //printf("fin\n");
    fclose(ptr);


}