#include "../includes/user.h"

// Initializer
void new_user(User *user) {
  user->name = (char*) malloc(50 * sizeof(char));
  user->email = (char*) malloc(50 * sizeof(char));
  user->password = (char*) malloc(50 * sizeof(char));
}

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
  char **mapping = (char**) malloc(length * sizeof(char*));

  for (size_t i = 0; i < length; i++)
    mapping[i] = (char*) malloc(50 * sizeof(char));

  for (int i = 0; i < length; i++) {
    char *aux = (*block)(users[i]);
    strcpy(mapping[i], aux);
  }

  return mapping;
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
  strcpy(user->name, name);
}

void set_user_email(User *user, char* email){
  strcpy(user->email, email);
}

void set_user_password(User *user, char* password){
  strcpy(user->password, password);
}

void set_user_age(User *user, int age){
  user->age = age;
}
