//
// Created by wx on 16/05/2022.
//

#include "../include/mes_libs.h"

char *perm(char * fichier){
    struct stat fileStat;
    if(stat(fichier, &fileStat) < 0){
        return "rien";
    }
    char *droit;
    droit = malloc(sizeof (char) * 20 + 1);
    mon_strcat(droit,(S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    mon_strcat(droit,(fileStat.st_mode & S_IRUSR) ? "r" : "-");
    mon_strcat(droit,(fileStat.st_mode & S_IWUSR) ? "w" : "-");
    mon_strcat(droit,(fileStat.st_mode & S_IXUSR) ? "x" : "-");
    mon_strcat(droit,(fileStat.st_mode & S_IRGRP) ? "r" : "-");
    mon_strcat(droit,(fileStat.st_mode & S_IWGRP) ? "w" : "-");
    mon_strcat(droit,(fileStat.st_mode & S_IXGRP) ? "x" : "-");
    mon_strcat(droit,(fileStat.st_mode & S_IROTH) ? "r" : "-");
    mon_strcat(droit,(fileStat.st_mode & S_IWOTH) ? "w" : "-");
    mon_strcat(droit,(fileStat.st_mode & S_IXOTH) ? "x" : "-");
    return droit;
    //printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
}

void ls(char * option){
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