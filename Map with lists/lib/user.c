#include "../includes/user.h"

void printf_email(User user){
  printf("%s\n", user.email);
}

void printf_name(User user){
  printf("%s\n", user.name);
}

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

char* get_user_name(User user){
  char *aux = user.name;
  return aux;
}
