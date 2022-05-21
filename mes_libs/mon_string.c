//
// Created by wx on 13/05/2022.
//
#include "../include/mes_libs.h"

int mon_len(const char *b){
    int a = 0;
    for(int i = 0 ; b[i]!='\0';i++){
        a++;
    }
    return a;
}

void * mon_strcpy(char *dest, const char *src){                //str copy du mot ou phrase
    size_t len = sizeof(char) * mon_len(src) + 1;
    char *d = dest;
    const char *s = src;
    while (len--) {
        *d++ = *s++;
    }
    d[mon_len(d) -1] = '\0';
    return dest;
}


char *mon_strcat2(char *s, const char *append){
    //char *save = s;
    if(s[0]!='\0') {
        for (; *s; ++s);
        while ((*s++ = *append++) != '\0');
    }
    return s;
}

char * mon_strcat(char *s, const char *append){
    int i = 0;
    mon_strcat2(s," ");
    while(s[i] != '\0') i++;
    for(int j = 0; append[j]!='\0'; j++){
        s[i + j] = append[j];
    }

    return s;
}