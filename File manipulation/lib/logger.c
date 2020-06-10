#include "../includes/logger.h"

void logger(int option, User *authenticated_user){
  FILE *file = fopen("storage/production.log", "a");
  int id = get_user_id(*authenticated_user);
  int day = date_day();
  int month = date_month();
  int year = date_year();
  int hour = time_hour();
  int minutes = time_minutes();
  int seconds = time_seconds();
  switch (option) {
    case 1:
      fprintf(file, "%d,leu a tabela de usuarios,data %d/%d/%d,hora %d:%d:%d,\n", id, day, month, year, hour, minutes, seconds);
      break;
    case 2:
      fprintf(file, "%d,leu a lista de e-mails,data %d/%d/%d,hora %d:%d:%d,\n", id, day, month, year, hour, minutes, seconds);
      break;
    case 3:
      fprintf(file, "%d,criou um novo usuario,data %d/%d/%d,hora %d:%d:%d,\n", id, day, month, year, hour, minutes, seconds);
      break;
    case 4:
      fprintf(file, "%d,leu a tabela de logs,data %d/%d/%d,hora %d:%d:%d,\n", id, day, month, year, hour, minutes, seconds);
      break;
    case 5:
      fprintf(file, "%d,fez logout,data %d/%d/%d,hora %d:%d:%d,\n", id, day, month, year, hour, minutes, seconds);
      break;
    default:
      fprintf(file, "%d,saiu do sistema,data %d/%d/%d,hora %d:%d:%d,\n", id, day, month, year, hour, minutes, seconds);
  }

  fclose(file);
}

int read_log_table(){
  FILE *file = fopen("storage/production.log", "r");
  if (file == NULL) {
    printf("Arquivo não pode ser aberto\n");
    return 0;
  }
  char first_column[50], second_column[50], third_column[50], fourth_column[50];
  while(!feof(file)) {
    fscanf(file, "%[^,],%[^,],%[^,],%[^,],\n", first_column, second_column, third_column, fourth_column);
    printf("%s,", first_column);
    printf("%s,", second_column);
    printf("%s,", third_column);
    printf("%s,\n", fourth_column);
  }
  rewind(file);
  fclose(file);
  printf("\n\n");
  return 0;
}
