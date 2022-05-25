//
// Created by wx on 13/05/2022.
//
#include "../include/mes_libs.h"


char * pwd(){
    char lepath[1000];
    char *result;
    result = getwd(lepath);
    return result;
}

// pwd static, c'est nul.
//char * pwd(){
//    return getenv("PWD")
//}

//char * pwd(){
//    char buffer[500];
//    FILE *output;
//    output = popen("/bin/pwd", "r");
//    char *pwd = fgets(buffer, sizeof(buffer), output);
//    pwd[mon_len(pwd)-1 ] = '\0';
//    return pwd;
//}

void * clear(){
    for(int i =0; i<1000;i++){
        printf("\n");
    }
    return 0;
}