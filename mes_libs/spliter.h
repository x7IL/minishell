//
// Created by wx on 15/05/2022.
//

#ifndef MINISHELL_SPLITER_H
#define MINISHELL_SPLITER_H

char *separateur_option(char * tab1, int l);
char *separateur_commande(char * tab1, int l);
int separateur_compteur_option(char *tab1);
int sep_egale_compteur(const char *tab1);
char *sep_egale(char * tab1, int l);

#endif //MINISHELL_SPLITER_H
