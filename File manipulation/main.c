#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "includes/user.h"

int main() {
  FILE *file = fopen("storage/users.csv", "r");
  int count_file_lines = 0;

  if (file == NULL) {
    printf("Arquivo não pode ser aberto\n");
    return 0;
  }

  for (char c = getc(file); c != EOF; c = getc(file))
    if (c == '\n')
      count_file_lines ++;

  printf("Count: %d\n", count_file_lines);
  User *users = (User*) malloc(count_file_lines * sizeof(User));
  int i = 0;
  rewind(file);
  while(!feof(file)) {
    char first_column[50], second_column[50], third_column[50], fourth_column[50];
    fscanf(file, "%[^,],%[^,],%[^,],%[^,],\n", first_column, second_column, third_column, fourth_column);
    set_user_name(&users[i], first_column);
    set_user_email(&users[i], second_column);
    set_user_password(&users[i], third_column);
    set_user_age(&users[i], atoi(fourth_column));
    i++;
  }

  each_user(&users[0], printf_name, count_file_lines);
  each_user(&users[0], printf_email, count_file_lines);
  each_user(&users[0], printf_password, count_file_lines);
  each_user(&users[0], printf_age, count_file_lines);

  fclose(file);
  return 0;
}
