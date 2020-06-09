#include "../includes/logger.h"

void logger(int option, User *authenticated_user){
  FILE *file = fopen("storage/production.log", "a");
  int id = get_user_id(*authenticated_user);
  switch (option) {
    case 1:
      fprintf(file, "%d,leu a tabela de usuarios,\n", id);
      break;
    case 2:
      fprintf(file, "%d,leu a lista de e-mails,\n", id);
      break;
    case 3:
      fprintf(file, "%d,criou um novo usuario,\n", id);
      break;
    case 4:
      fprintf(file, "%d,leu a tabela de logs,\n", id);
      break;
    case 5:
      fprintf(file, "%d,fez logout,\n", id);
      break;
    default:
      fprintf(file, "%d,saiu do sistema,\n", id);
  }

  fclose(file);
}

int read_log_table(){
  FILE *file = fopen("storage/production.log", "r");
  if (file == NULL) {
    printf("Arquivo não pode ser aberto\n");
    return 0;
  }
  char first_column[50], second_column[50];
  while(!feof(file)) {
    fscanf(file, "%[^,],%[^,],\n", first_column, second_column);
    printf("%s,", first_column);
    printf("%s,\n", second_column);
  }
  rewind(file);
  fclose(file);
  printf("\n\n");
  return 0;
}
