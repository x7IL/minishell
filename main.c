#include "include/mes_libs.h"

//gcc -O3 -Wall main.c mes_libs/checker.c mes_libs/mon_string.c mes_libs/pwdd.c mes_libs/spliter.c
//gcc -O3 -Wall main.c mes_libs/checker.c mes_libs/mon_string.c mes_libs/pwdd.c mes_libs/spliter.c mes_libs/executeur.c mes_libs/echoo.c
//gcc -O3 -Wall main.c mes_libs/checker.c mes_libs/mon_string.c mes_libs/pwdd.c mes_libs/spliter.c mes_libs/executeur.c mes_libs/echoo.c mes_libs/cdd.c
//gcc -O3 -Wall main.c mes_libs/checker.c mes_libs/mon_string.c mes_libs/pwdd.c mes_libs/spliter.c mes_libs/executeur.c mes_libs/echoo.c  mes_libs/userr.c mes_libs/lss.c mes_libs/date.c


void shell_loop(void){

//    FILE *f = fopen("my_history.txt", "w");
//
//    if(f==NULL){
//        printf("le fichier my_history n'est pas dans le repertoire du main.c");
//    }

    char PS1[] = "Esiea_shell_> ";

    char *buffer;
    size_t bufsize = 32;


    buffer = (char *)malloc(bufsize * sizeof(char));

    do {
        char cmd[256];
        char reste[500];
        char fulloption[500];

        printf("%s",PS1);
        getline(&buffer,&bufsize,stdin);
        //printf("cmd : [%s] option : [%d]\n", separateur_commande(buffer,0,buffer),verifi(separateur_commande(buffer,0,buffer)));

        if(verifi(separateur_commande(buffer,0,buffer)) == 1 ){

            mon_strcpy(cmd,separateur_commande(buffer,0,buffer), mon_len(separateur_commande(buffer,0,buffer))+1);
            mon_strcpy(fulloption,separateur_option(buffer,1,buffer), mon_len(separateur_option(buffer,1,buffer))+1);

            for(int i = 2 ; i < separateur_compteur_option(buffer)+1;i++){
                mon_strcpy(reste,separateur_option(buffer,i,buffer), mon_len(separateur_option(buffer,i,buffer))+1);
                //printf("option %d :%s\n",i,reste);
                //reste[mon_len(reste)-1] = '\0';
                //printf("1--[%s]",reste);
                mon_strcat(fulloption,reste);
                //fulloption[mon_len(fulloption)-1] = '\0';
                //printf("--2--[%s]\n",reste);
                //mon_strcpy(reste,"",256);
            }
            fulloption[mon_len(fulloption)-1] = '\0';
            //printf("optionnnn : [%s]\n",fulloption);

            if(execute_cmd(cmd, fulloption) == 0){
                //printf("ici que ca break?");
                break;
            }

        }
        else{
            printf("!!! COMMANDE INVALIDE !!!\n");
        }

        mon_strcpy(fulloption,"",500);

        //free(args);
    } while (1);
    //fclose(f);
}


int main(){

// Chargement des fichiers de configurations si besoin.
    printf("\nMini SHELL - exit pour Quitter \n\n");
// Run command loop.
    shell_loop();
    printf("\nFin du Mini SHELL \n");




    return EXIT_SUCCESS;
}