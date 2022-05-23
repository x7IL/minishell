//
// Created by wx on 22/05/2022.
//

#include "../include/mes_libs.h"

void echo_help(){
    printf("\n----------------------------\n"
           "\nNOM\n"
           "     echo - écrit les arguments sur la sortie standard\n"
           "\n"
           "SYNOPSIS\n"
           "     echo [chaîne de caractères...]\n"
           "\n"
           "DESCRIPTION\n"
           "     L'utilitaire echo écrit les opérandes spécifiés, séparés par des caractères blancs (' ') et suivis d'un caractère de retour à la ligne ('\\n'), sur la sortie standard.\n");
}

void pwd_help(){
    printf("\n----------------------------\n"
           "\nNOM\n"
           "     pwd - renvoie le nom du répertoire de travail\n"
           "\n"
           "SYNOPSIS\n"
           "     pwd\n"
           "\n"
           "DESCRIPTION\n"
           "     L'utilitaire pwd écrit le chemin d'accès absolu du répertoire de travail actuel sur la sortie standard.\n");

}

void cd_help(){
    printf("\n----------------------------\n"
           "\nNOM\n"
           "cd - changer le répertoire de travail\n"
           "\n"
           "SYNOPSIS\n"
           "    cd [répertoire]\n"
           "\n"
           "DESCRIPTION\n"
           "    L'utilitaire cd modifie le répertoire de travail de l'environnement d'exécution de l'interpréteur de commandes actuel (voir Environnement d'exécution de l'interpréteur de commandes ) en exécutant les étapes suivantes dans l'ordre. (Dans les étapes suivantes, le symbole curpath représente une valeur intermédiaire utilisée pour simplifier la description de l'algorithme utilisé par cd. Il n'est pas nécessaire que curpath soit rendu visible par l'application).\n"
           "    Si aucun opérande de répertoire n'est donné et que la variable d'environnement HOME est vide ou indéfinie, le comportement par défaut est défini par l'implémentation et aucune autre étape ne doit être effectuée.\n"
           "    Si aucun opérande de répertoire n'est donné et que la variable d'environnement HOME est définie sur une valeur non vide, l'utilitaire cd se comporte comme si le répertoire nommé dans la variable d'environnement HOME était spécifié comme opérande de répertoire.\n"
           "    .. pour reculer d'un repertoire\n");
}

void date_help(){
    printf("\n----------------------------\n"
           "\nNOM\n"
           "date - écrit la date et l'heure\n"
           "\n"
           "SYNOPSIS\n"
           "    date\n"
           "\n"
           "DESCRIPTION\n"
           "    L'utilitaire date écrit la date et l'heure sur la sortie standard ou tente de définir la date et l'heure du système. Par défaut, la date et l'heure actuelles sont écrites. Si un opérande commençant par '+' est spécifié, le format de sortie de la date sera contrôlé par les spécifications de conversion et les autres textes de l'opérande.\n");
}

void mkdir_help(){
    printf("\n----------------------------\n"
           "\nNOM\n"
           "    mkdir - créer des répertoires\n"
           "\n"
           "SYNOPSIS\n"
           "    mkdir [PATH]/[nom du fichier]\n"
           "\n"
           "DESCRIPTION\n"
           "    L'utilitaire mkdir crée les répertoires spécifiés par les opérandes, dans l'ordre indiqué.\n");
}

void head_help(){
    printf("\n----------------------------\n"
           "\nNOM\n"
           "head - copie la première partie des fichiers\n"
           "\n"
           "SYNOPSIS\n"
           "    head [fichier...] [-n nombre] \n"
           "\n"
           "DESCRIPTION\n"
           "    L'utilitaire head copie ses fichiers d'entrée sur la sortie standard, en terminant la sortie de chaque fichier à un point donné.\n"
           "\n"
           "    La copie se termine à l'endroit de chaque fichier d'entrée indiqué par l'option -n nombre. Le nombre d'arguments de l'option est compté en unités de lignes.\n");
}

void history_help(){
    printf("\n----------------------------\n"
           "\nNOM\n"
           "    history - Afficher ou manipuler la liste de l'historique.\n"
           "\n"
           "SYNOPSIS\n"
           "    history\n"
           "\n"
           "DESCRIPTION\n"
           "    Affiche la liste des 10 dernieres commandes passé\n");
}

void clear_help(){
    printf("\n----------------------------\n"
           "\nNOM\n"
           "clear - effacer l'écran du terminal.\n"
           "\n"
           "SYNOPSIS\n"
           "    clear\n"
           "\n"
           "DESCRIPTION\n"
           "    clear efface votre écran si c'est possible.\n");
}

void exit_help(){
    printf("\n----------------------------\n"
           "\nNOM\n"
           "       exit - provoque la fin normale du processus\n"
           "SYNOPSIS\n"
           "\n"
           "    exit\n"
           "\n"
           "DESCRIPTION\n"
           "       La fonction exit() provoque l'arrêt normal du processus et le\n");
}

void prompt(){
    printf("\n----------------------------\n"
           "\nNOM\n"
           "       le prompt : PS1\n"
           "SYNOPSIS\n"
           "\n"
           "    PS1=[ce que vous voulez]\n"
           "\n"
           "DESCRIPTION\n"
           "       la fonction PS1=[ce que vous voulez] vous permet de changer le prompt\n");
}

void Helpp(char *option){
    if(option[0] != '\0') {
        if (compare(option, "echo") == 0) {
            echo_help();
        } else if (compare(option, "pwd") == 0) {
            pwd_help();
        } else if (compare(option, "cd") == 0) {
            cd_help();
        } else if (compare(option, "date") == 0) {
            date_help();
        } else if (compare(option, "mkdir") == 0) {
            mkdir_help();
        } else if (compare(option, "head") == 0) {
            head_help();
        } else if (compare(option, "history") == 0) {
            history_help();
        } else if (compare(option, "clear") == 0) {
            clear_help();
        } else if (compare(option, "exit") == 0) {
            exit_help();
        } else if (compare(option, "PS1") == 0) {
            prompt();
        } else {
            printf("help [%s] n'existe pas", option);
        }
    }
    else{
        echo_help();
        pwd_help();
        cd_help();
        date_help();
        mkdir_help();
        head_help();
        history_help();
        clear_help();
        exit_help();
        prompt();
    }
    //echo_help();
}


