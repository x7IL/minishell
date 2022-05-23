//
// Created by wx on 15/05/2022.
//

#include "../include/mes_libs.h"

//my_cd
//◦ my_history (liste des commandes passé, history 10 : )
//◦ my_pwd ( pas avec get)
//◦ my_ls (avec option -a -l et autres)
//◦ my_date
//◦ my_echo (pas de printf pour echo)
//◦ my_head
//◦ my_mkdir
//◦ my_help (Cette commande donne les commandes intégrés dans
//le mini shell)
//◦ my_exit
//◦ Bonus : Toutes autres commandes
// Variables d’environnement à intégrer :
//◦ HOME
//◦ SHELL
//◦ PS1
//◦ … autres
// Gestion de l’history
// Bonus :
//◦ my_bashrc
//◦ Gestion des Alias
//◦ pipe
//◦ redirection
int execute_cmd(char *cmd, char *option){
    //printf("cmd ==> |%s|\n",cmd);

    //printf("cmd :%s\n",cmd);
    //printf("option :[%s]\n",option);
    if(compare(cmd, "pwd") == 0){
        if(separateur_compteur_option(option) > 0) {
            printf("Trop de parametres\n");
        }
        else{
            printf("%s\n",pwd());
        }
    }               //ko
    else if(compare(cmd,"user") == 0){
        printf("%s\n",user());
    }
    else if(compare(cmd,"home") == 0){
        printf("%s\n",home());
    }
    else if(compare(cmd,"shell") == 0){
        printf("%s\n",shell());
    }
    else if(compare(cmd,"PS1=") == 0){
        return 741;
    }           //ok
    else if(compare(cmd,"ls") == 0){
        ls(option);
    }
    else if(compare(cmd,"date") == 0){
        if(separateur_compteur_option(option) > 1) {
            printf("Trop de parametres\n");
        }
        else{
            date();
        }
    }           //ok
    else if(compare(cmd,"echo") == 0){
        printf("[%s]\n",option);
        echo(option);
    }           //ok
    else if(compare(cmd,"cd") == 0){
        if(separateur_compteur_option(option) > 1) {
            printf("Trop de parametres\n");
        }
        else{
            cd(option);
        }
    }             //ok
    else if(compare(cmd,"mkdir") == 0){
        if(separateur_compteur_option(option) > 1) {
            printf("Trop de parametres\n");
        }
        else{
            Mkdir(option);
        }
    }          //ok
    else if(compare(cmd,"help") == 0){
        if(separateur_compteur_option(option) > 2) {
            printf("Trop de parametres\n");
        }
        else{
            Helpp(option);
        }
    }
    else if(compare(cmd,"head") == 0){
        if(separateur_compteur_option(option) > 2) {
            printf("Trop de parametres\n");
        }
        else{
            head(option);
        }
    }           //ok
    else if(compare(cmd,"history") == 0){
        if(separateur_compteur_option(option) > 1) {
            printf("Trop de parametres\n");
        }
        else{
            history(option);
        }
    }        //ok
    else if(compare(cmd,"clear") == 0){
        if(separateur_compteur_option(option) > 1) {
            printf("Trop de parametres\n");
        }
        else{
            clear(option);
        }
    }          //ok
    if(compare(cmd, "exit") == 0){
        if(separateur_compteur_option(option) > 0) {
            printf("Trop de parametres\n");
        }
        else{
            return 0;
        }
    }               //ok
    return 1;
}
