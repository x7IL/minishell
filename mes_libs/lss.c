//
// Created by wx on 16/05/2022.
//

#include "../include/mes_libs.h"

void ls(char * option){
    DIR *rep = opendir ("." );
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