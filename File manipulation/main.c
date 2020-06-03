#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "includes/user.h"

User* list_users(){
  FILE *file = fopen("storage/users.csv", "r");
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
    set_user_name(&users[i], first_column);
    set_user_email(&users[i], second_column);
    set_user_password(&users[i], third_column);
    set_user_age(&users[i], atoi(fourth_column));
    i++;
  }
  fclose(file);
  // printf("Primeiro caracter da primeira coluna: %c\n", first_column[0]);
  // printf("First column: %s\n", first_column);
  // printf("Numero de linhas do arquivo: %d\n", count_file_lines);
  each_user(users, printf_user_attributes, count_file_lines);
  return users;
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
  printf("Hello you!\n");
  while (k) {
    printf("Para ver a lista de usuários digite 1, para se cadastrar como novo usuário digite 2 e para sair digite 3.\n");
    scanf("%d", &option);
    switch (option) {
      case 1:
      list_users();
      break;
      case 2:
        create_user();
        break;
      case 3:
        k=0;
        break;
      default:
        printf("Opcao invalida, escolha novamente\n");
    }
  }
  system("clear");
  User *users = list_users();
  char auxi[6] = "teste";
  printf("%s\n", auxi);
  char **emails = map_users(users, get_user_email, 5);
  printf("Email: %s\n", emails[0]);
  return 0;
}
