//
// Created by wx on 16/05/2022.
//

#include "../include/mes_libs.h"


void ls2(char * option){
    DIR *rep = opendir (".");
    //printf("[%s]\n",option);
    if (rep != NULL){
        struct dirent *lecture;
        while ((lecture = readdir(rep))){
            struct stat st;
            stat (lecture->d_name, &st);{
/* Modified time */
                time_t t = st.st_mtime;
                struct tm tm = *localtime (&t);
                char s[32];
                strftime(s, sizeof s, "%d/%m/%Y %H:%M:%S", &tm);
                printf("%-32s \t%s\n", lecture->d_name, s);
            }
        }
        closedir(rep), rep = NULL;
    }
}

int bytes(char *fichier){
    struct stat fileStat;
    stat(fichier, &fileStat);
    return fileStat.st_size;

}

int links(char *fichier){
    struct stat fileStat;
    stat(fichier, &fileStat);
    return fileStat.st_nlink;
}

//Black \033[0;30m
//Red \033[0;31m
//Green \033[0;32m
//Yellow \033[0;33m
//Blue \033[0;34m
//Purple \033[0;35m
//Cyan \033[0;36m
//White \033[0;37m

void black () {
    printf("\033[0;30m");
}

void red () {
    printf("\033[0;31m");
}

void green(){
    printf("\033[0;32m");
}

void yellow(){
    printf("\033[0;33m");
}

void blue(){
    printf("\033[0;34m");
}

void purple(){
    printf("\033[0;35m");
}

void cyan(){
    printf("\033[0;36m");
}

void white(){
    printf("\033[0;37m");
}

void reset () {
    printf("\033[0m");
}

void perm(char * fichier){
    struct stat fileStat;
    stat(fichier, &fileStat);
    printf(" ");
    red();
    printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    yellow();
    printf(" ");
    printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    purple();
    printf(" ");
    printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    green();
    printf(" ");
    printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
    reset();
    printf("\t");

    //printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
}

int ls(char * option){
    DIR *rep = NULL;
    char test[256];
    mon_strcpy(test, separateur_option(option,0));
    int option_a = 0;
    int option_l = 0;
    int aucun = 0;
    int  stop = 0;

    for(int i = 0; i < separateur_compteur_option(option)+1;i++) {
        if (compare("-l", separateur_option(option,i)) == 0) {
            option_l = 1;
        } else if (compare("-a", separateur_option(option,i)) == 0) {
            option_a = 1;
        }
        //printf("-->[%d][%d]\n",compare("-l", separateur_option(option,i)),compare("-a", separateur_option(option,i)));
    }
    //printf("[%d][%d]\n",option_a,option_l);
    if(option_a == 0 && option_l == 0){
        aucun = 1;
    }

    char path[256];
    mon_strcpy(path,pwd());
    //printf("-->[%s]<--\n",path);
    if(((compare(separateur_option(option,0),"-l") == 0) || (compare(separateur_option(option,0),"-a") == 0)) || (compare(separateur_option(option,0),"") == 0)) {
        rep = opendir(".");
    }
    else{
        //printf("[%s]\n",separateur_option(option,0));
        if (chdir(separateur_option(option,0)) != 0) {
            printf("le repertoire n'existe pas\n");
            return EXIT_FAILURE;
        }
        else {
            rep = opendir(pwd());
        }
    }
    struct dirent *lecture;
    while ((lecture = readdir(rep))) {
        struct stat st;
        stat(lecture->d_name, &st);
        {
            time_t t = st.st_mtime;
            struct tm tm = *localtime(&t);
            char s[32];
            strftime(s, sizeof s, "%d/%m/%Y %H:%M:%S", &tm);
            if ((lecture->d_name[0] == '.') && option_a == 1) {
                if(option_l == 1) {
                    perm(lecture->d_name);
                    printf("%-15d", links(lecture->d_name));
                    printf("%-20d", bytes(lecture->d_name));
                    printf("%-25s", s);
                }
                if (((lecture->d_name[0] == '.' && lecture->d_name[1] == '\0') ||
                     (lecture->d_name[0] == '.' && lecture->d_name[1] == '.' && lecture->d_name[2] == '\0'))) {
                    red();
                    printf("%-30s ", lecture->d_name);
                    reset();
                }
                else{
                    blue();
                    printf("%-30s ", lecture->d_name);
                    reset();
                }
            }
            else if((lecture->d_name[0] != '.')){
                stop = 1;
                if(option_l == 1) {
                    perm(lecture->d_name);
                    printf("%-15d", links(lecture->d_name));
                    printf("%-20d", bytes(lecture->d_name));
                    printf("%-25s", s);
                }
                printf("%-30s", lecture->d_name);
            }

            if(option_l == 1 && stop == 1){
                printf("\n");
            }
            else if(option_a == 1 && option_l == 0){
                printf("\t");
            }
            else if (aucun == 0 && stop == 1) {
                printf("\n");
            }
            else if(option_l == 0 && stop == 1){
                printf("\t");
            }
            else if(option_l == 1 && option_a == 1){
                printf("\n");
            }
            stop = 0;
        }


    }
    chdir(path);
    //printf("option -->[%s]\n",option);

    //int aa = 0;
    //int ll = 0;
    printf("\n");
    closedir(rep);
    return EXIT_SUCCESS;
}