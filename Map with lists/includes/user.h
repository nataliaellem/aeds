#ifndef USER_H
#define USER_H

#include <stdio.h>
#include "linked_list.h"

typedef struct user {
  char *name;
  char *email;
  char *password;
} User;

void printf_email(User user);

void printf_name(User user);

void each_user(User *users, void (*block)(User), int users_length);

List* map_users(User *users, char* (*block)(), int length);

char* get_user_name(User user);
#endif
