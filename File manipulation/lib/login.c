#include "../includes/login.h"

User* login(){
  printf("Digite seu e-mail: ");
  char *email_login = (char*) malloc(50 * sizeof(char));
  scanf("%s", email_login);
  printf("\n");
  //printf("EMAIL LOGIN: %s\n", email_login);
  //Getting list of users and number of lines of the file
  FILE *file = fopen("storage/users.csv", "r");
  int count_file_lines = 0;

  if (file == NULL) {
    printf("Arquivo não pode ser aberto\n");
    return NULL;
  }

  for (char c = getc(file); c != EOF; c = getc(file)){
    if (c == '\n')
      count_file_lines ++;
  }
  rewind(file);
  User *users = list_users(file);
  fclose(file);
  int aux = 0;
  char *authenticated_email = NULL;
  int index_user;
  while(aux < count_file_lines){
    char *email = get_user_email(users[aux]);
    //printf("email: %s\n", email);
    if (strcmp(email, email_login) == 0){
      authenticated_email = (char*) malloc(50 * sizeof(char));
      strcpy(authenticated_email, email);
      index_user = aux;
      aux = count_file_lines;
    } else{
      aux++;
    }
  }
  //printf("Authenticated email: %s\n", authenticated_email);
  if (authenticated_email == NULL){
    printf("E-mail invalido, digite novamente\n");
    return NULL;
  }
  else {
    printf("Digite sua senha: ");
    char *pass = (char*) malloc(50 * sizeof(char));
    scanf("%s", pass);
    char *login_pass = get_user_password(users[index_user]);
    if (strcmp(login_pass, pass) == 0){
      User *authenticated_user = &users[index_user];
      printf("\n");
      printf("\n");
      return authenticated_user;
    }
    else{
      printf("Senha incorreta.\n");
      printf("\n");
      printf("\n");
      return NULL;
    }
  }
}
