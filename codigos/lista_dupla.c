#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	int data;
	struct list *next;
	struct list *prev;
} List;

List* create_list(){
	return NULL;
}

List* insert(List *list, int data){
	if (list==NULL){
		List *new_block = (List*) malloc(sizeof(List));
		new_block->data = data;
		new_block->prev = (List*) NULL; //o ponteiro do novo bloco esta apontando para o NULL que estava na lista
		new_block->next = (List*) NULL;
		list = new_block;
	} else {
		List *aux;
		List *new_block = (List*) malloc(sizeof(List));
		new_block->data = data;
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
		printf(" %d -> ", aux->data);
		aux2=aux;
	}
	printf("\n");
	// for (aux2=list; aux2->next!=NULL; aux2=aux2->next);

	for (aux2=aux2; aux2!=NULL; aux2=aux2->prev){
		printf(" %d -> ", aux2->data);
	}
	printf("\n");
} 

int exists(List* list, int n){
//Return 0 if element not exists in list
//Return 1 if element does exist in list
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

int main(){
	List *list = create_list();	
	list = insert(list, 1);
	list = insert(list, 2);
	list = insert(list, 3);
	list = insert(list, 4);
	list = insert(list, 5);
	print_list(list);
	list = remove_from_list(list, 3);
	list = remove_from_list(list, 1);
	list = remove_from_list(list, 5);
	print_list(list);

	return 0;
}
