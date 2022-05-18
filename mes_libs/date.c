//
// Created by wx on 16/05/2022.
//

#include "../include/mes_libs.h"

void date(){
    time_t now;
    time(&now);
    printf("%s\n",ctime(&now));
    time_t seconds;
    struct tm *timeStruct;
    seconds = time(NULL);
    timeStruct = localtime(&seconds);
    printf("Current time : %d:%d:%d : %d:%d:%d\n",timeStruct->tm_yday,timeStruct->tm_wday,timeStruct->tm_year, timeStruct->tm_hour, timeStruct->tm_min, timeStruct->tm_sec);

}

void cd(char * path){
    char temp[256];
    mon_strcpy(temp,path, mon_len(path)+1);
    temp[mon_len(temp)-1]='\0';
    //printf("%s\n",temp);
    if(temp[0] == '\0'){
        mon_strcpy(temp,getenv("HOME"), mon_len(getenv("HOME"))+1);
    }
    if(chdir(temp) != 0){
        printf("changement raté\n");
    }
    else {
        chdir(path);
    }
}

//            if(compare(cmd,"cd") == 0){
//                char temp[256];
//                mon_strcpy(temp,separateur_option(buffer,1), mon_len(separateur_option(buffer,1))+1);
//                temp[mon_len(temp)-1]='\0';
//                printf("%s\n",temp);
//                if(temp[0] == '\0'){
//                    mon_strcpy(temp,getenv("HOME"), mon_len(getenv("HOME"))+1);
//                }
//                if(chdir(temp) != 0){
//                    printf("changement raté\n");
//                }
//                else {
//                    chdir(separateur_option(buffer, 1));
//                }
//            }
//            else {