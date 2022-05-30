#include "include/mes_libs.h"

void shell_loop(void){
    char PS1[256] = "Esiea_shell_>";
    int i;
    char *HOME;
    HOME = getenv("HOME");
    char *USER;
    USER = getenv("USER");


    size_t bufsize = 556;

    char homee[200];
    mon_strcpy(homee,getenv("PWD"));
    mon_strcat2(homee,"/my_history.txt");
    do {
        int status;
        char cmd[256];
        char reste[500];
        char fulloption[500];
        char * buffer = malloc(bufsize * sizeof(char));
        int oui = 0;
        printf("%s ",PS1);
        getline(&buffer,&bufsize,stdin);

        /*printf("cmd [%s]\n",separateur_commande(buffer,0));*/

        DIR *rep = NULL;
        rep = opendir("/bin");
        struct dirent *lecture;
        while ((lecture = readdir(rep))) {
            struct stat st;
            stat(lecture->d_name, &st);{
                if(compare(lecture->d_name, separateur_commande(buffer,0)) == 0){
                    oui = 1;
                    break;
                }
            }
        }

        if(oui == 0 || (compare(user(),"root") == 0)) {
            if (compare(buffer, "\n") == 0) {
                printf("\n");
            }
            else if ((verifi(separateur_commande(buffer, 0)) == 1) || (verifi(sep_egale(buffer, 0)) == 1)) {

                FILE *fp = fopen(homee, "a");
                fseek(fp, 0, SEEK_END);
                fwrite(buffer, sizeof(char) * mon_len(buffer), sizeof(char), fp);
                fclose(fp);

                if ((verifi(sep_egale(buffer, 0)) != 1)) {
                    mon_strcpy(cmd, separateur_commande(buffer, 0));
                    mon_strcpy(fulloption, separateur_option(buffer, 1));
                    for (i = 2; i < separateur_compteur_option(buffer) + 1; i++) {
                        mon_strcpy(reste, separateur_option(buffer, i));
                        mon_strcat(fulloption, separateur_option(buffer, i));
                        fulloption[mon_len(fulloption)] = '\0';
                    }
                    fulloption[mon_len(fulloption) - 1] = '\0';
                    printf("option[%s]\n", fulloption);
                } else {
                    mon_strcpy(cmd, sep_egale(buffer, 0));
                    mon_strcpy(fulloption, sep_egale(buffer, 1));
                    fulloption[mon_len(fulloption) - 1] = '\0';
                }
                printf("cmd 2 [%s]\n", separateur_commande(buffer,0));

                int temp = execute_cmd(cmd, fulloption, HOME, USER);

                if (temp == 0) {
                    printf("\nFin du Mini SHELL \n");
                    break;
                } else if (temp == 741) {
                    mon_strcpy(PS1, "");
                    fulloption[mon_len(fulloption)] = sep_egale(buffer, 1)[mon_len(sep_egale(buffer, 1)) - 1];
                    mon_strcpy(PS1, fulloption);
                } else if (temp == 742) {
                    mon_strcpy(HOME, "");
                    fulloption[mon_len(fulloption)] = sep_egale(buffer, 1)[mon_len(sep_egale(buffer, 1)) - 1];
                    mon_strcpy(HOME, fulloption);
                } else if (temp == 743) {
                    mon_strcpy(USER, "");
                    mon_strcpy(USER, separateur_option(fulloption, 0));
                } else if (temp == 778) {
                    printf("superviseur introuvable\n");
                } else if (temp == 779) {
                    printf("vous n'avez pas les droits suffisant pour utiliser la commande\n");
                }
            } else {
                printf("!!! COMMANDE INVALIDE !!!\n");
            }
        }
        else{
            FILE *fp = fopen(homee, "a");
            fseek(fp, 0, SEEK_END);
            fwrite(buffer, sizeof(char) * mon_len(buffer), sizeof(char), fp);
            fclose(fp);

            char temp [ 500];
            printf("option 2\n");
            int j;
            char *temp_av[] = {
                    add(my_split(buffer, 0), "/bin/"),
                    (my_split(buffer,1) != NULL)? my_split(buffer, 1) : NULL,
                    (my_split(buffer,2) != NULL)? my_split(buffer, 2) : NULL,
                    (my_split(buffer,3) != NULL)? my_split(buffer, 3) : NULL,
                    (my_split(buffer,4) != NULL)? my_split(buffer, 4) : NULL,
                    (my_split(buffer,5) != NULL)? my_split(buffer, 5) : NULL,
                    (my_split(buffer,6) != NULL)? my_split(buffer, 6) : NULL,
                    (my_split(buffer,7) != NULL)? my_split(buffer, 7) : NULL,
                    (my_split(buffer,8) != NULL)? my_split(buffer, 8) : NULL,
                    (my_split(buffer,9) != NULL)? my_split(buffer, 9) : NULL,
                    (my_split(buffer,10) != NULL)? my_split(buffer, 10) : NULL,
                    (my_split(buffer,11) != NULL)? my_split(buffer, 11) : NULL,
                    (my_split(buffer,12) != NULL)? my_split(buffer, 12) : NULL,
                    (my_split(buffer,13) != NULL)? my_split(buffer, 13) : NULL,
                    (my_split(buffer,14) != NULL)? my_split(buffer, 14) : NULL,
                    (my_split(buffer,15) != NULL)? my_split(buffer, 15) : NULL,
                    (my_split(buffer,16) != NULL)? my_split(buffer, 16) : NULL,
                    (my_split(buffer,17) != NULL)? my_split(buffer, 17) : NULL,
                    (my_split(buffer,18) != NULL)? my_split(buffer, 18) : NULL,
                    (my_split(buffer,19) != NULL)? my_split(buffer, 19) : NULL,
                    (my_split(buffer,20) != NULL)? my_split(buffer, 20) : NULL,
                    NULL

            };
            *temp_av = malloc(sizeof(char **)* mon_len(buffer) + 1);

            for(j = 1; j < separateur_compteur_option(buffer) + 1; j++) {
                temp_av[j] = my_split(buffer, j);
                /*printf("[%s]\n",temp_av[j]);*/
            }
            temp_av[separateur_compteur_option(buffer)][mon_len(temp_av[separateur_compteur_option(buffer)]) -1] = '\0';
            /*printf("[%s]\n",temp_av[separateur_compteur_option(buffer)]);*/
            pid_t pid = fork();
            if (pid == 0) {
                access(buffer, F_OK);
                if(buffer[0] == 'c' && buffer[1] == 'd'){
                    chdir(my_split(buffer,1));
                } else {

                    mon_strcpy(temp, "/bin/");
                    mon_strcat2(temp,my_split(buffer, 0));
                    if(separateur_compteur_option(buffer) <1) {
                        temp[mon_len(temp) - 1] = '\0';
                    }
                    for(j = 1; j < separateur_compteur_option(buffer) + 1; j++) {
                        printf("[%s]\n",temp_av[j]);
                    }
                    /*printf("bin [%s]\n",temp);
                    printf("option [%s]\n",temp_av[1]);
                    printf("option [%s]\n",temp_av[2]);*/
                    execv(temp, temp_av);
                }
                break;
            }

        }
        wait(&status);
        free(buffer);
        reset();

    } while (1);
}


int main(){

    printf("\nMini SHELL - exit pour Quitter \n\n");
    shell_loop();

    return EXIT_SUCCESS;
}

