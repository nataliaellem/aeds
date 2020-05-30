#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "includes/linked_list.h"
#include "includes/user.h"

int main() {
  User users[3];

  for (size_t i = 0; i < 3; i++) {
    users[i].name = (char*) malloc(50 * sizeof(char));
    users[i].email = (char*) malloc(50 * sizeof(char));
    users[i].password = (char*) malloc(50 * sizeof(char));
  }

  strcpy(users[0].name, "Natalia");
  strcpy(users[1].name, "Alan");
  strcpy(users[2].name, "Pedro");
  strcpy(users[0].email, "natalia@gmail.com");
  strcpy(users[1].email, "alan@gmail.com");
  strcpy(users[2].email, "pedro@gmail.com");
  strcpy(users[0].password, "123");
  strcpy(users[1].password, "123");
  strcpy(users[2].password, "123");

  each_user(users, printf_email, 3);
  each_user(users, printf_name, 3);

  List *users_names = map_users(users, get_user_name, 3);

  print_list(users_names);
  return 0;
}
