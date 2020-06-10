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
      fprintf(file, "%d,leu a tabela de usuarios,%d/%d/%d,%d:%d:%d,\n", id, day, month, year, hour, minutes, seconds);
      break;
    case 2:
      fprintf(file, "%d,leu a lista de e-mails,%d/%d/%d,%d:%d:%d,\n", id, day, month, year, hour, minutes, seconds);
      break;
    case 3:
      fprintf(file, "%d,criou um novo usuario,%d/%d/%d,%d:%d:%d,\n", id, day, month, year, hour, minutes, seconds);
      break;
    case 4:
      fprintf(file, "%d,leu a tabela de logs,%d/%d/%d,%d:%d:%d,\n", id, day, month, year, hour, minutes, seconds);
      break;
    case 5:
      fprintf(file, "%d,fez logout,%d/%d/%d,%d:%d:%d,\n", id, day, month, year, hour, minutes, seconds);
      break;
    default:
      fprintf(file, "%d,saiu do sistema,%d/%d/%d,%d:%d:%d,\n", id, day, month, year, hour, minutes, seconds);
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


char*** list_logs(FILE *file) {
    int count_file_lines = 0;
    if (file == NULL) {
      printf("Arquivo não pode ser aberto\n");
      return 0;
    }

    for (char c = getc(file); c != EOF; c = getc(file))
      if (c == '\n')
        count_file_lines ++;
    char ***logs = (char***) malloc(count_file_lines * sizeof(char**));
    for (int j =0; j < count_file_lines; j++){
      logs[j] = (char**) malloc(4 * sizeof(char*));
      for (int k = 0; k < 4; k++){
        logs[j][k] = (char*) malloc(50 * sizeof(char));
      }
    }
    int i = 0;
    rewind(file);
    char first_column[50], second_column[50], third_column[50], fourth_column[50];
    while(!feof(file)) {
      fscanf(file, "%[^,],%[^,],%[^,],%[^,],\n", first_column, second_column, third_column, fourth_column);
      strcpy(logs[i][0], first_column);
      strcpy(logs[i][1], second_column);
      strcpy(logs[i][2], third_column);
      strcpy(logs[i][3], fourth_column);
      i++;
    }
    // for (int m = 0; m < count_file_lines; m++){
    //   for (int n = 0; n < 4; n++){
    //     printf("%s,", logs[m][n]);
    //   }
    //   printf("\n");
    // }
    //printf("LOGs NA POSICAO 00: %s\n", logs[0][0]);
    return logs;
}

int get_id_log(char** log){
  int id = atoi(log[0]);
  return id;
}

char** get_action_log(char **log){
  char **action = (char**) malloc(50 * sizeof(char*));
  for (int i = 0; i < 50; i++){
    action[i] = (char*) malloc(50 *sizeof(char));
    strcpy(action[i], log[1]);
  }
  return action;
}

char* get_date_log(char** log){
  char* date = (char*) malloc(20 * sizeof(char));
  strcpy(date, log[2]);
  return date;
}

char* get_time_log(char** log){
  char* time = (char*) malloc(20 * sizeof(char));
  strcpy(time, log[3]);
  return time;
}

char*** filter_logs_id(char ***logs, int(*block)(char**), int filter_attribute){
  FILE *file = fopen("storage/production.log", "r");
  int number_of_lines = 0;
  for (char c = getc(file); c != EOF; c = getc(file)){
    if (c == '\n'){
      number_of_lines ++;
    }
  }
  rewind(file);
  fclose(file);
  char ***filtered_logs = (char***) malloc(1 * sizeof(char**));
  filtered_logs[0] = (char**) malloc(4 * sizeof(char*));
  for (int k = 0; k < 4; k++){
    filtered_logs[0][k] = (char*) malloc(50 * sizeof(char));
  }
  int count = 1;
  for (int i = 0; i < number_of_lines; i++){
    int attribute = (*block)(logs[i]);
    if (attribute == filter_attribute){
      filtered_logs = (char***) realloc(filtered_logs, count * sizeof(char**));
      filtered_logs[count-1] = (char**) malloc(4 * sizeof(char*));
      for (int k = 0; k < 4; k++){
        filtered_logs[count-1][k] = (char*) malloc(50 * sizeof(char));
      }
      for (int l = 0; l < 4; l++){
        strcpy(filtered_logs[count-1][l], logs[i][l]);
      }
      count++;
    }
  }
  for (int m = 0; m < count-1; m++){
    for (int n = 0; n < 4; n++){
      printf("%s,", filtered_logs[m][n]);
    }
    printf("\n");
  }
  return filtered_logs;
}
