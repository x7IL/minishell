//
// Created by wx on 16/05/2022.
//


#include "../include/mes_libs.h"

char * user(){
    return getenv("USER");
}

char * shell(){
    return getenv("SHELL");
}

char * home(){
    return getenv("HOME");
}
