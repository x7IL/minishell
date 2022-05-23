//
// Created by wx on 13/05/2022.
//

#include "../include/mes_libs.h"

int compare(const char *tab1, const char *tab2){    // savoir si c'est exit ou pas
    int i = 0;

    if(mon_len(tab1) != (mon_len(tab2))){
        return 1;
    }
    //printf("[%s] - [%d]\n",tab1, mon_len(tab1));
    //printf("[%s] - [%d]\n",tab2, mon_len(tab2));
    while(tab1[i]!= '\0'){
        if(tab1[i] != tab2[i]){
            return 1;
        }
        i++;
    }
    return 0;
}

int verifi(const char *tab){ //regarde si le input est egale aux commande se trouvant dans le tab

    int mon_boolean = 0;
    //printf("test ici : %s",tab);
    char *commandes[] = {"exit",
                         "pwd",
                         "cd",
                         "history",
                         "ls",
                         "date",
                         "echo",
                         "head",
                         "mkdir",
                         "help",
                         "user",
                         "home",
                         "shell",
                         "PS1=",
                         "clear",
                         NULL
    };

    for(int i = 0; commandes[i] != NULL; i++){
        //printf("%d - %d\n",mon_len(commandes[i]),mon_len(tab));

        for(int j = 0; commandes[i][j]!= '\0'; j++){
            if(mon_len(commandes[i]) == mon_len(tab)) {
                if (commandes[i][j] == tab[j]) {
                    //printf("[%s] -- [%s]",commandes[i],tab);
                    //printf(" non %s\n",commandes[i]);
                    //printf("%c",tab[j]);
                    mon_boolean = 1;
                } else {
                    //printf(" ok %s\n",commandes[i]);
                    //printf("->%c",tab[j]);
                    mon_boolean = 0;
                    break;
                }
            }
            else{
                break;
            }
        }
        //printf("\n");
        //printf("suinvant %s\n",commandes[i]);
        if(mon_boolean == 1){
            //je dois rajouter une commande ici pour executer les commandes
            //printf("marche?\n");
            return 1;
        }

    }
    //printf("FUCK\n");
    return 0;
}