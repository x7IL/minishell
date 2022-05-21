//
// Created by wx on 15/05/2022.
//

#ifndef MES_LIBS_H
#define MES_LIBS_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#include "../mes_libs/checker.h"
#include "../mes_libs/spliter.h"
#include "../mes_libs/mon_string.h"
#include "../mes_libs/executeur.h"
#include "../mes_libs/date.h"
#include "../mes_libs/pwdd.h"
#include "../mes_libs/echoo.h"
#include "../mes_libs/userr.h"
#include "../mes_libs/lss.h"
#include "../mes_libs/headd.h"
void date();

int compare(const char *tab1, const char *tab2);
int verifi(const char *tab);
int mon_len(const char *b);
void * mon_strcpy(char *dest, const char *src);
char * mon_strcat(char *s, const char *append);

char * separateur_option(char * tab1, int l);
char * separateur_commande(char * tab1, int l);
int sep_egale_compteur(const char *tab1);
char *sep_egale(char * tab1, int l);

int execute_cmd(char *cmd, char * option);
//void mon_printf(char const *str);
void echo(char const *str);
void mon_write(char c);
char * pwd();
char * user();
char * shell();
char * home();
void ls(char * option);
void cd(char * path);
void Mkdir(char *option);
void head(char * fichier);
void history();

#endif //MES_LIBS_H
