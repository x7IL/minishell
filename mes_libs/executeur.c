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


int execute_cmd(char *cmd, char *option, char *HOME, char *USER){
//    printf("cmd ==> |%s|\n",cmd);
//    printf("option :[%s]\n",option);
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
    else if(compare(cmd,"HOME=") == 0){
        return 742;
    }
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
            cd(option, HOME);
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
    }
    else if(compare(cmd,"cat") == 0){
        if(separateur_compteur_option(option) > 1) {
            printf("Trop de parametres\n");
        }
        else{
            cat(option);
        }
    }
    else if(compare(cmd,"wc") == 0){
        if(separateur_compteur_option(option) > 3) {
            printf("Trop de parametres\n");
        }
        else{
            wc(option);
        }
    }
    else if(compare(cmd,"rm") == 0){
        if(separateur_compteur_option(option) > 1) {
            printf("Trop de parametres\n");
        }
        else{
            rmm(option);
        }
    }
    else if(compare(cmd,"touch") == 0){
        if(separateur_compteur_option(option) > 1) {
            printf("Trop de parametres\n");
        }
        else{
            touch(option);
        }
    }
    else if(compare(cmd,"rmdir") == 0){
        if(separateur_compteur_option(option) > 1) {
            printf("Trop de parametres\n");
        }
        else{
            Rmdir(option);
        }
    }
    else if(compare(cmd,"su") == 0){
        if(separateur_compteur_option(option) > 2) {
            printf("Trop de parametres\n");
        }
        else if(separateur_option(option,0)[0] == '\0'){
            printf("manque l'utilisateur\n");
        }
        else if(separateur_option(option,1)[0] == '\0'){
            printf("manque le mot de passe\n");
        }
        else{
            return droit(option);
        }
    }
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
