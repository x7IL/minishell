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
        printf("%s\n",pwd());
    }
    else if(compare(cmd,"user") == 0){
        printf("%s\n",user(option));
    }
    else if(compare(cmd,"ls") == 0){
        ls(option);
    }
    else if(compare(cmd,"date") == 0){
        date();
    }
    else if(compare(cmd,"echo") == 0){
        //printf("[%s]\n",option);
        echo(option);
    }
    else if(compare(cmd,"cd") == 0){
        cd(option);
    }
    if(compare(cmd, "exit") == 0){
        return 0;
    }
    else{
        return 1;
    }
}
