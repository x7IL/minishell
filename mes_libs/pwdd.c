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