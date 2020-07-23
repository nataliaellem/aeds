#include "../includes/linked_list.h"

List* create_list(){
	return NULL;
}

List* insert(List *list, char* data){
	if (list==NULL){
		List *new_block = (List*) malloc(sizeof(List));
    new_block->data = (char*) malloc(50 * sizeof(char));
		strcpy(new_block->data, data);
		new_block->prev = (List*) NULL;
		new_block->next = (List*) NULL;
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
	for (aux; aux!=NULL; aux=aux->prev){
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
	for (aux = list; aux != NULL; aux = aux->next){
		if (aux->data == n){
			if (aux->prev == NULL){
				aux->next->prev = NULL; //o aux->prev e igual a NULL
				list = aux->next;
				return list;
			} else if (aux->next == NULL){
				aux->prev->next = NULL;
				return list;
			} else {
				aux->prev->next = aux->next;
				aux->next->prev = aux->prev;
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
