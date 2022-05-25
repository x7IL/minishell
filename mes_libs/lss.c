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
    printf("  ");
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
    printf("\t\t");

    //printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
}

void ls(char * option){
    DIR *rep = opendir ("./");
    printf("[%s]\n",option);

    //int aa = 0;
    //int ll = 0;

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
                perm(lecture->d_name);
                printf("%-15d", links(lecture->d_name));
                printf("%-20d", bytes(lecture->d_name));
                printf("%-25s", s);
                if((lecture->d_name[0] == '.' && lecture->d_name[1] == '\0') || (lecture->d_name[0] == '.' && lecture->d_name[1] == '.' && lecture->d_name[2] == '\0')){
                    red();
                    printf("%-30s\n", lecture->d_name);
                    reset();
                }
                else if(lecture->d_name[0] != '.' != 0) {
                    printf("%-30s\n", lecture->d_name);
                    //printf("%-15s", perm(lecture->d_name));

                }
                else{
                    blue();
                    printf("%-30s\n", lecture->d_name);
                    reset();
                }
            }
        }
        closedir(rep), rep = NULL;
    }
}