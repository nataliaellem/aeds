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

void each_user(User *users, void (*block)(User), int users_length) {
  for (size_t i = 0; i < users_length; i++) {
    (*block)(users[i]);
  }
}
// Lists functions
//////////////////////////////////////////////////////////////////
typedef struct list{
	char *data;
	struct list *next;
	struct list *prev;
} List;

List* create_list(){
	return NULL;
}



List* insert(List *list, char* data){
	if (list==NULL){
		List *new_block = (List*) malloc(sizeof(List));
    new_block->data = (char*) malloc(50 * sizeof(char));
		strcpy(new_block->data, data);
		new_block->prev = (List*) NULL; //o ponteiro do novo bloco esta apontando para o NULL que estava
		new_block->next = (List*) NULL; //na lista
		list = new_block;
	} else {
		List *aux;
		List *new_block = (List*) malloc(sizeof(List));
    new_block->data = (char*) malloc(50 * sizeof(char));
    strcpy(new_block->data, data);
		for (aux=list; aux->next!=NULL; aux=aux->next);
		new_block->prev = aux;
		new_block->next = (List*) NULL;
		aux->next = new_block;
	}

	return list;
}

void print_list(List *list){
	List *aux;
	List *aux2;
	for (aux=list; aux!=NULL; aux=aux->next){
		printf(" %s -> ", aux->data);
		aux2=aux;
	}
	printf("\n");
}

void print_list_reverse(List *list){
	List *aux;
	for (aux=aux; aux!=NULL; aux=aux->prev){
		printf(" %s -> ", aux->data);
	}
	printf("\n");
}

//Return 0 if element not exists in list
//Return 1 if element does exist in list
int exists(List* list, int n){
	List *aux;
	for (aux=list; aux->next!=NULL; aux=aux->next){
		if (aux->data == n){
			return 1;
		}
	}
	return 0;
}

List* remove_from_list(List *list, int n){
	List *aux;
	for (aux=list; aux!=NULL; aux=aux->next){
		if (aux->data==n){
			if (aux->prev==NULL){
				aux->next->prev = NULL; //o aux->prev e igual a NULL
				list=aux->next;
				return list;
			} else if (aux->next==NULL){
				aux->prev->next = NULL;
				return list;
			} else {
				aux->prev->next=aux->next;
				aux->next->prev=aux->prev;
				return list;
			}
		}
	}
	return list;
}

List* insert_in_position(List *list, char *info, int position){
	List *aux;
	int contador=0;
	for (aux=list; aux->next!=NULL; aux = aux->next){
		contador++;
		if (contador == position){
			printf("DEBUG\n");
			List *new_block = (List*) malloc(sizeof(List));
			if (aux->prev==NULL){
				new_block->prev=NULL;
				new_block->next=aux;
				aux->prev=new_block;
				new_block->data=info;
				list=new_block;
				return list;
			} else {
				new_block->data = info;
				aux->prev->next=new_block;
				new_block->prev=aux->prev;
				aux->prev=new_block;
				new_block->next=aux;
				return list;
			}
		}
	}
	contador++;
	if (position==contador+1){
		list=insert(list, info);
		return list;
	} else if(position>contador+1){
		return NULL;
	}
	return list;
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
