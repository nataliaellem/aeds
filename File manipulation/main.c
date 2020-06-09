#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "includes/user.h"
#include "includes/login.h"
#include "includes/logger.h"

int main() {
  int k = 1, option;
  int l = 1;
  system("clear");
  printf("BEM VINDO!\n\n");
  while (k) {
    User *authenticated_user = login();
    if (authenticated_user){
      while (l){
        printf("ESCOLHA UMA OPCAO:\n");
        printf("\t(1): Listar usuarios do sistema\n");
        printf("\t(2): Listar apenas emails\n");
        printf("\t(3): Criar novo usuario\n");
        printf("\t(4): Ler a tabela de log\n");
        printf("\t(5): Fazer logout\n");
        printf("\t(N/D): Sair do sistema\n");
        printf("Digite e pressione enter: ");
        scanf("%d", &option);
        logger(option, authenticated_user);
        system("clear");
        switch (option) {
          case 1:
            print_list_users();
            break;
          case 2:
            print_list_emails();
            break;
          case 3:
            create_user();
            break;
          case 4:
            read_log_table();
            break;
          case 5:
            l=0;
            break;
          default:
            k=0;
            printf("Opcao invalida, escolha novamente\n");
        }

      }
    }
  }
  return 0;
}
