#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list{
	char *data;
	struct list *next;
	struct list *prev;
} List;

List* create_list();
List* insert(List *list, char* data);
void print_list(List *list);
void print_list_reverse(List *list);
int exists(List* list, int n);
List* remove_from_list(List *list, int n);
List* insert_in_position(List *list, char *info, int position);

#endif
