#include "include/mes_libs.h"

void shell_loop(void){
    char PS1[256] = "Esiea_shell_>";
    int i;
    char *HOME;
    HOME = getenv("HOME");
    char *USER;
    USER = getenv("USER");

    char * buffer;
    size_t bufsize = 556;

    char homee[200];
    mon_strcpy(homee,getenv("PWD"));
    mon_strcat2(homee,"/my_history.txt");

    do {
        char cmd[256];
        char reste[500];
        char fulloption[500];
        buffer = malloc(bufsize * sizeof(char));
        printf("%s ",PS1);
        getline(&buffer,&bufsize,stdin);

        if(compare(buffer,"\n")==0){
            printf("\n");
        }
        else if((verifi(separateur_commande(buffer,0)) == 1) || (verifi(sep_egale(buffer,0)) == 1)){

            FILE* fp = fopen(homee, "a");
            fseek(fp, 0, SEEK_END);
            fwrite(buffer, sizeof(char) * mon_len(buffer), sizeof(char), fp);
            fclose(fp);

            if((verifi(sep_egale(buffer,0)) != 1)) {
                mon_strcpy(cmd,separateur_commande(buffer,0));
                mon_strcpy(fulloption,separateur_option(buffer,1));
                for (i = 2; i < separateur_compteur_option(buffer)+1; i++) {
                    mon_strcpy(reste, separateur_option(buffer, i));
                    mon_strcat(fulloption, separateur_option(buffer, i));
                }
                fulloption[mon_len(fulloption)-1] = '\0';
            }
            else{
                mon_strcpy(cmd,sep_egale(buffer,0));
                mon_strcpy(fulloption, sep_egale(buffer, 1));
                fulloption[mon_len(fulloption)-1] = '\0';
            }
            int temp = execute_cmd(cmd, fulloption,HOME,USER);
            if(temp == 0){
                break;
            }
            else if(temp == 741){
                mon_strcpy(PS1,"");
                fulloption[mon_len(fulloption)] = sep_egale(buffer, 1)[mon_len(sep_egale(buffer, 1))-1];
                mon_strcpy(PS1,fulloption);
            }
            else if(temp == 742){
                mon_strcpy(HOME,"");
                fulloption[mon_len(fulloption)] = sep_egale(buffer, 1)[mon_len(sep_egale(buffer, 1))-1];
                mon_strcpy(HOME,fulloption);
            }
            else if(temp == 743){
                mon_strcpy(USER,"");
                mon_strcpy(USER, separateur_option(fulloption,0));
            }
            else if(temp == 778){
                printf("superviseur introuvable\n");
            }
            else if(temp == 999){
                printf("vous n'avez pas les droits suffisant pour utiliser la commande\n");
            }
        }
        else{
            printf("!!! COMMANDE INVALIDE !!!\n");
        }
        mon_strcpy(fulloption,"");
        free(buffer);
        reset();

    } while (1);
}


int main(){

    printf("\nMini SHELL - exit pour Quitter \n\n");

    shell_loop();
    printf("\nFin du Mini SHELL \n");

    return EXIT_SUCCESS;
}

