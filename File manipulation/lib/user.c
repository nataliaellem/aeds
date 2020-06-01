#include "../includes/user.h"

// Enumerable
void each_user(User *users, void (*block)(User), int users_length) {
  for (size_t i = 0; i < users_length; i++) {
    (*block)(users[i]);
  }
}

List* map_users(User *users, char* (*block)(), int length){
  List *new_list = create_list();
  for (size_t i = 0; i < length; i++) {
    new_list = insert(new_list, (*block)(users[i]));
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

// Getters
char* get_user_name(User user){
  char *name = user.name;
  return name;
}

char* get_user_email(User user){
  char *email = user.email;
  return email;
}

char* get_user_password(User user){
  char *password = user.password;
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
