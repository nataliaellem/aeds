#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"
#include "user.h"

void logger(int option, User *authenticated_user);
int read_log_table();

#endif
