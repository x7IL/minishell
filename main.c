#include "include/mes_libs.h"

//gcc -O3 -Wall main.c mes_libs/checker.c mes_libs/mon_string.c mes_libs/pwdd.c mes_libs/spliter.c
//gcc -O3 -Wall main.c mes_libs/checker.c mes_libs/mon_string.c mes_libs/pwdd.c mes_libs/spliter.c mes_libs/executeur.c mes_libs/echoo.c
//gcc -O3 -Wall main.c mes_libs/checker.c mes_libs/mon_string.c mes_libs/pwdd.c mes_libs/spliter.c mes_libs/executeur.c mes_libs/echoo.c mes_libs/cdd.c
//gcc -O3 -Wall main.c mes_libs/checker.c mes_libs/mon_string.c mes_libs/pwdd.c mes_libs/spliter.c mes_libs/executeur.c mes_libs/echoo.c  mes_libs/userr.c mes_libs/lss.c mes_libs/date.c
//gcc -O3 -Wall main.c mes_libs/checker.c mes_libs/mon_string.c mes_libs/pwdd.c mes_libs/spliter.c mes_libs/executeur.c mes_libs/echoo.c  mes_libs/userr.c mes_libs/lss.c mes_libs/date.c mes_libs/mkdirr.c
//gcc -O3 -Wall main.c mes_libs/checker.c mes_libs/mon_string.c mes_libs/pwdd.c mes_libs/spliter.c mes_libs/executeur.c mes_libs/echoo.c  mes_libs/userr.c mes_libs/lss.c mes_libs/date.c mes_libs/mkdirr.c mes_libs/headd.c
//gcc -O3 -Wall main.c mes_libs/checker.c mes_libs/mon_string.c mes_libs/pwdd.c mes_libs/spliter.c mes_libs/executeur.c mes_libs/echoo.c  mes_libs/userr.c mes_libs/lss.c mes_libs/date.c mes_libs/mkdirr.c mes_libs/headd.c mes_libs/help.c
//gcc -O3 -Wall main.c mes_libs/checker.c mes_libs/mon_string.c mes_libs/pwdd.c mes_libs/spliter.c mes_libs/executeur.c mes_libs/echoo.c  mes_libs/userr.c mes_libs/lss.c mes_libs/date.c mes_libs/mkdirr.c mes_libs/headd.c mes_libs/help.c mes_libs/catt.c mes_libs/wcc.c mes_libs/rmm.c

//◦ my_cd                                                           ok
//◦ my_history (liste des commandes passé, history 10 : )           ok
//◦ my_pwd ( pas avec get)                                          ok          demander prof, getenv static pas possible
//◦ my_ls (avec option -a -l et autres)                             ok          besoin d'option
//◦ my_date                                                         ok          à modifier
//◦ my_echo (pas de printf pour echo)                               ok
//◦ my_head                                                         ok
//◦ my_mkdir                                                        ok
//◦ my_help (Cette commande donne les commandes intégrés dans le mini shell)        ok
//◦ my_exit                                                         ok
//◦ clear                                                           ok
//◦ cat
//◦ wc
//◦ rm
//◦ Bonus : Toutes autres commandes
// Variables d’environnement à intégrer :
//◦ HOME
//◦ SHELL
//◦ PS1                                                             ok
//◦ … autres
// Gestion de l’history
// Bonus :
//◦ my_bashrc
//◦ Gestion des Alias
//◦ pipe
//◦ redirection

void shell_loop(void){

//    FILE *f = fopen("my_history.txt", "w");
//
//    if(f==NULL){
//        printf("le fichier my_history n'est pas dans le repertoire du main.c");
//    }

    char PS1[256] = "Esiea_shell_>";
    char *HOME = malloc(sizeof (getenv("HOME")) + 1);
    HOME = getenv("HOME");
//    char *SHELL = malloc(sizeof (getenv("SHELL")) + 1);
//    SHELL = getenv("SHELL");

    char *buffer;
    size_t bufsize = 556;


    char homee[200];
    mon_strcpy(homee,getenv("PWD"));
    mon_strcat3(homee,"/my_history.txt ");
    //printf("[%s]\n",homee);



    do {
        char cmd[256];
        char reste[500];
        char fulloption[500];
        buffer = malloc(bufsize * sizeof(char));


        printf("%s ",PS1);
        //printf("[%s]\n",sep_egale(buffer,0));
        getline(&buffer,&bufsize,stdin);

        int m = 0;
        int l = 0;

        if(compare(separateur_commande(buffer,0),"echo") != 0) {
            while (buffer[m] != '\0') {
                if (((buffer[m] == ' ' && buffer[m + 1] == ' ') || (buffer[m] == ' ' && buffer[m + 1] == '\0')) != 1) {
                    buffer[l] = buffer[m];
                    l++;
                }
                m++;
            }
            buffer[l] = '\0';
        }
        //printf("cmd : [%s] option : [%d]\n", separateur_commande(buffer,0,buffer),verifi(separateur_commande(buffer,0,buffer)));
        if(compare(buffer,"\n")==0){
            printf("\n");
        }
        else if((verifi(separateur_commande(buffer,0)) == 1) || (verifi(sep_egale(buffer,0)) == 1)){

            FILE* fp = fopen(homee, "a");
            fseek(fp, 0, SEEK_END);
            fwrite(buffer, sizeof(char) * mon_len(buffer), sizeof(char), fp);
            fclose(fp);

            if((verifi(sep_egale(buffer,0)) != 1)) {
                mon_strcpy(cmd,separateur_commande(buffer,0));
                mon_strcpy(fulloption,separateur_option(buffer,1));
                for (int i = 2; i < separateur_compteur_option(buffer)+1; i++) {
                    mon_strcpy(reste, separateur_option(buffer, i));
                    mon_strcat(fulloption, separateur_option(buffer, i));
                }
                fulloption[mon_len(fulloption)-1] = '\0';
            }
            else{
                mon_strcpy(cmd,sep_egale(buffer,0));
                mon_strcpy(fulloption, sep_egale(buffer, 1));
                fulloption[mon_len(fulloption)-1] = '\0';
            }
            int temp = execute_cmd(cmd, fulloption,HOME);
            //printf("[%s]\n",sep_egale(buffer,1));
            if(temp == 0){
                break;
            }
            else if(temp == 741){
                mon_strcpy(PS1,"");
                fulloption[mon_len(fulloption)] = sep_egale(buffer, 1)[mon_len(sep_egale(buffer, 1))-1];        //long truc, pck ca prend pas le last caractere
                mon_strcpy(PS1,fulloption);
            }
            else if(temp == 742){
                mon_strcpy(HOME,"");
                fulloption[mon_len(fulloption)] = sep_egale(buffer, 1)[mon_len(sep_egale(buffer, 1))-1];        //long truc, pck ca prend pas le last caractere
                mon_strcpy(HOME,fulloption);
            }
        }
        else{
            printf("!!! COMMANDE INVALIDE !!!\n");
        }
        mon_strcpy(fulloption,"");
        mon_strcpy(buffer,"");
        free(buffer);
        //free(args);
        reset();
    } while (1);
    //
}


int main(){

// Chargement des fichiers de configurations si besoin.
    printf("\nMini SHELL - exit pour Quitter \n\n");
// Run command loop.
    shell_loop();
    printf("\nFin du Mini SHELL \n");

    return EXIT_SUCCESS;
}

