#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "includes/user.h"
#include "includes/login.h"
#include "includes/logger.h"
#include "includes/date.h"

int main() {
  FILE *file = fopen("storage/users.csv", "r");
  int count_file_lines = 0;
  for (char c = getc(file); c != EOF; c = getc(file)){
    if (c == '\n'){
      count_file_lines++;
    }
  }
  rewind(file);
  int k = 1;
  system("clear");
  printf("BEM VINDO!\n\n");
  while (k) {
    User *authenticated_user = login();
    if (authenticated_user){
      int l = 1;
      while (l){
        int option;
        printf("ESCOLHA UMA OPCAO:\n");
        printf("\t(1): Listar usuarios do sistema\n");
        printf("\t(2): Listar apenas emails\n");
        printf("\t(3): Criar novo usuario (apenas para adms)\n");
        printf("\t(4): Ler a tabela de log\n");
        printf("\t(5): Atualizar dados do usuario\n");
        printf("\t(6): Ver logs de um usuario\n");
        printf("\t(7): Fazer logout\n");
        printf("\t(8): Sair do sistema\n");
        printf("Digite e pressione enter: ");
        scanf("%d", &option);
        logger(option, authenticated_user);
        system("clear");
        switch (option) {
          case 1:
            system("clear");
            print_list_users();
            break;
          case 2:
            system("clear");
            print_list_emails();
            break;
          case 3:
            system("clear");
            create_user(authenticated_user);
            break;
          case 4:
            system("clear");
            read_log_table();
            break;
          case 5:
            system("clear");
            update_user(authenticated_user);
            break;
          case 6:
            system("clear");
            user_logs(count_file_lines, file);
            rewind(file);
            break;
          case 7:
            system("clear");
            l=0;
            break;
          case 8:
            system("clear");
            l=0;
            k=0;
            break;
          default:
            system("clear");
            l=0;
            k=0;
            printf("Opcao invalida, escolha novamente\n");
            break;
        }
      }
    }
  }
  fclose(file);

  //test for list logs
  //FILE *file = fopen("storage/production.log", "r");
  //list_logs(file);
  //test for filter functions
  //char ***logs = list_logs(file);
  //filter_logs_id(logs, get_id_log, 10);
  // FILE *file = fopen("storage/users.csv", "r");
  // User *users = list_users(file);
  // rewind(file);
  // fclose(file);
  // filter_int_attributes(users, get_user_age, 2, 9);
  return 0;
}
