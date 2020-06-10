#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "login.h"
#include "user.h"
#include "date.h"

void logger(int option, User *authenticated_user);
int read_log_table();
char*** list_logs(FILE *file) ;
int get_id_log(char** log);
char** get_action_log(char **log);
char* get_date_log(char** log);
char* get_time_log(char** log);
char*** filter_logs_id(char ***logs, int(*block)(char**), int filter_attribute);

#endif
