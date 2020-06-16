#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked_list.h"

// Structs
typedef struct user {
  char *name;
  char *email;
  char *password;
  int age;
  int id;
  char *role;
} User;

User* list_users(FILE *file);
void print_list_users();
void print_list_emails();
void create_user(User *authenticated_user);
void update_user(User *authenticated_user);
void change_user_name(User *authenticated_user, int count_file_lines, User *users);
void change_email(User *authenticated_user, int count_file_lines, User *users);
void change_password(User *authenticated_user, int count_file_lines, User *users);
void change_age(User *authenticated_user, int count_file_lines, User *users);

// Initializer
void new_user(User *user);

// Enumerables
void    each_user(User *users, void (*block)(User), int users_length);
List*   map_list(User *users, char* (*block)(User), int length);
char**  map_users(User *users, char* (*block)(User), int length);
User    *filter_char_attributes(User *users, char* (*block)(User), char *filter_attribute, int length);
User    *filter_int_attributes(User *users, int (*block)(User), int filter_attribute, int length);
// Inspects
void    printf_email(User user);
void    printf_name(User user);
void    printf_password(User user);
void    printf_age(User user);
void    printf_user_attributes(User user);
// Getters
char*   get_user_name(User user);
char*   get_user_email(User user);
char*   get_user_password(User user);
int     get_user_age(User user);
int     get_user_id(User user);
char*   get_user_role(User user);
// Setters
void    set_user_name(User *user, char* name);
void    set_user_email(User *user, char* email);
void    set_user_password(User *user, char* password);
void    set_user_age(User *user, int age);
void    set_user_id(User *user, int id);
void    set_user_role(User *user, char* role);

#endif
