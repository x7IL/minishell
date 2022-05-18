//
// Created by wx on 15/05/2022.
//

#ifndef MINISHELL_MON_STRING_H
#define MINISHELL_MON_STRING_H


int mon_len(const char *b);
void * mon_strcpy(void *dest, const void *src, size_t len);
char * mon_strcat(char *s, const char *append);

//void mon_printf(char const *str);

#endif //MINISHELL_MON_STRING_H
