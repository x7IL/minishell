//
// Created by wx on 15/05/2022.
//

#ifndef MINISHELL_SPLITER_H
#define MINISHELL_SPLITER_H

char *separateur_option(char * tab1, int l, char * option);
char *separateur_commande(char * tab1, int l, char * option);
int separateur_compteur_option(char *tab1);

#endif //MINISHELL_SPLITER_H
