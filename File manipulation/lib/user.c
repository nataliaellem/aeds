#include "../includes/user.h"

// Enumerable
void each_user(User *users, void (*block)(User), int users_length){
  for (int i = 0; i < users_length; i++) {
    (*block)(users[i]);
    printf("\n");
  }
}

List* map_list(User *users, char* (*block)(User), int length){
  List *new_list = create_list();
  for (int i = 0; i < length; i++) {
    new_list = insert(new_list, (*block)(users[i]));
  }
  return new_list;
}

char** map_users(User *users, char* (*block)(User), int length){
  char **new_list = alocar_matriz(length, 50);

  for (int i = 0; i < length; i++) {
    char *aux = (*block)(users[i]);
    //printf("aux: %s\n", aux);
    strcpy(&new_list[i], aux);
    //printf("new list [i]: %s\n", new_list[i]);
  }
  return new_list;
}

// Inspect
void printf_email(User user){
  printf("%s\n", user.email);
}

void printf_name(User user){
  printf("%s\n", user.name);
}

void printf_password(User user){
  printf("%s\n", user.password);
}

void printf_age(User user){
  printf("%d\n", user.age);
}

void printf_user_attributes(User user){
  printf("%s,", user.name);
  printf(" %s,", user.email);
  printf(" %s,", user.password);
  printf(" %d.", user.age);
}

// Getters
char* get_user_name(User user){
  char *name = (char*) malloc(50*sizeof(char));
  strcpy(name, user.name);
  return name;
}

char* get_user_email(User user){
  char *email = (char*) malloc(50*sizeof(char));
  strcpy(email, user.email);
  return email;
}

char* get_user_password(User user){
  char *password = (char*) malloc(50*sizeof(char));
  strcpy(password, user.password);
  return password;
}

int get_user_age(User user){
  int age = user.age;
  return age;
}

// Setters
void set_user_name(User *user, char* name){
  if (user->name == NULL) user->name = (char*) malloc(50 * sizeof(char));
  strcpy(user->name, name);
}

void set_user_email(User *user, char* email){
  if (user->email == NULL) user->email = (char*) malloc(50 * sizeof(char));
  strcpy(user->email, email);
}

void set_user_password(User *user, char* password){
  if (user->password == NULL) user->password = (char*) malloc(50 * sizeof(char));
  strcpy(user->password, password);
}

void set_user_age(User *user, int age){
  user->age = age;
}


char **alocar_matriz (int m, int n)
{
  char **v;  /* ponteiro para a matriz */
  int   i;    /* variavel auxiliar      */
  if (m < 1 || n < 1) { /* verifica parametros recebidos */
     printf ("** Erro: Parametro invalido **\n");
     return (NULL);
     }
  /* aloca as linhas da matriz */
  v = (char **) calloc (m, sizeof(char *));	/* Um vetor de m ponteiros para char */
  if (v == NULL) {
     printf ("** Erro: Memoria Insuficiente **");
     return (NULL);
     }
  /* aloca as colunas da matriz */
  for ( i = 0; i < m; i++ ) {
      v[i] = (char*) calloc (n, sizeof(char));	/* m vetores de n floats */
      if (v[i] == NULL) {
         printf ("** Erro: Memoria Insuficiente **");
         return (NULL);
         }
      }
  return (v); /* retorna o ponteiro para a matriz */
}
