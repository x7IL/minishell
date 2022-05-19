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

void * mon_strcpy(void *dest, const void *src){                //str copy du mot ou phrase
    size_t len = sizeof(char) * mon_len(src) + 1;
    char *d = dest;
    const char *s = src;
    while (len--)
        *d++ = *s++;
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

char *mon_strcat_bis(char *s, const char *append){

    mon_strcat2(s," ");
    for (; *s; ++s);                    //on se met a la fin du tab
    while ((*s++ = *append++) != '\0');         //on attribue le debut de tab source append a tab dest
    return s;
}


char *mon_strcat(char *s, const char *append){
    int i = 0 ;
    mon_strcat2(s," ");
    while((s[i+ mon_len(s)] = append[i]) != '\0'){
        i++;
    }  //on attribue le debut de tab source append a tab dest
    return s;
}
