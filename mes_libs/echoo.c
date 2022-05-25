//
// Created by wx on 16/05/2022.
//

#include "../include/mes_libs.h"

//void echo(char *option){
//
//    char temp[256];
//    mon_strcpy(temp,option, mon_len(option)+1);
//    temp[mon_len(temp)-1]='\0';
//    printf("%s\n",temp);
//    mon_printf(option);
//}

void mon_write(char c){
    write(1, &c, 1);
}

void echo(char const *str){
    printf("[%s]\n",str);
    //printf("test [%s]\n",str);
    if(str[0]!='\0'){
        int nb = 0;
        while (str[nb] != '\0') {
            mon_write(str[nb]);
            nb++;
        }
        write(1,"\n",2);
        write(1,"\n",2);
    }
    reset();
}

//void echo(char const *str){
//    //printf("test [%s]\n",str);
//    puts(str);
//}