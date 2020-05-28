#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct user {
  char *name;
  char *email;
  char *password;
} User;

void printf_email(User user){
  printf("%s\n", user.email);
}

void printf_name(User user){
  printf("%s\n", user.name);
}

void each_user(User *users, void (*block)(User)) {
  for (size_t i = 0; i < 3; i++) {
    (*block)(users[i]);
  }
}

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

  each_user(users, printf_email);
  each_user(users, printf_name);
  return 0;
}
