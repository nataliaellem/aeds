#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "includes/user.h"

User* list_users(FILE *file) {
  int count_file_lines = 0;

  if (file == NULL) {
    printf("Arquivo não pode ser aberto\n");
    return 0;
  }

  for (char c = getc(file); c != EOF; c = getc(file))
    if (c == '\n')
      count_file_lines ++;

  User *users = (User*) malloc(count_file_lines * sizeof(User));
  int i = 0;
  rewind(file);
  char first_column[50], second_column[50], third_column[50], fourth_column[50];
  while(!feof(file)) {
    fscanf(file, "%[^,],%[^,],%[^,],%[^,],\n", first_column, second_column, third_column, fourth_column);
    // Initializing user object
    new_user(&users[i]);
    set_user_name(&users[i], first_column);
    set_user_email(&users[i], second_column);
    set_user_password(&users[i], third_column);
    set_user_age(&users[i], atoi(fourth_column));
    i++;
  }

  return users;
}

void print_list_users(){
  FILE *file = fopen("storage/users.csv", "r");
  int count_file_lines = 0;

  if (file == NULL) {
    printf("Arquivo não pode ser aberto\n");
    return;
  }

  for (char c = getc(file); c != EOF; c = getc(file))
    if (c == '\n')
      count_file_lines ++;

  rewind(file);
  User *users = list_users(file);
  fclose(file);
  each_user(users, printf_user_attributes, count_file_lines);
}

void print_list_emails() {
  FILE *file = fopen("storage/users.csv", "r");
  int count_file_lines = 0;

  for (char c = getc(file); c != EOF; c = getc(file))
    if (c == '\n')
      count_file_lines ++;
  rewind(file);

  User *users = list_users(file);
  char **emails = map_users(users, get_user_email, count_file_lines);

  for (size_t i = 0; i < count_file_lines; i++) {
    printf("%s\n", emails[i]);
  }
}


void create_user(){
  printf("Digite o nome do usuario: ");
  char *name = (char*) malloc(50*sizeof(char));
  char *email = (char*) malloc(50*sizeof(char));
  char *pass = (char*) malloc(50*sizeof(char));
  int age;
  scanf("%s", name);
  printf("\n");
  printf("Digite o email: ");
  scanf("%s", email);
  printf("\n");
  printf("Digite a senha: ");
  scanf("%s", pass);
  printf("\n");
  printf("Digite a idade: ");
  scanf("%d", &age);
  printf("\n");
  printf("%s, %s, %s, %d, ", name, email, pass, age);
  FILE *file = fopen("storage/users.csv", "a");
  fprintf(file, "%s, %s, %s, %d,\n", name, email, pass, age);
  fclose(file);
}

int main() {
  int k = 1, option;
  system("clear");
  printf("BEM VINDO!\n\n");
  while (k) {
    printf("ESCOLHA UMA OPCAO:\n");
    printf("\t(1): Listar usuarios do sistema\n");
    printf("\t(2): Listar apenas emails\n");
    printf("\t(3): Criar usuarios\n");
    printf("\t(N/D): Sair do sistema\n");
    printf("Digite e pressione enter: ");
    scanf("%d", &option);
    printf("\nOption: %d\n", option);
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
      default:
        k=0;
        printf("Opcao invalida, escolha novamente\n");
    }
  }
  printf("Adeus!\n");
  return 0;
}
