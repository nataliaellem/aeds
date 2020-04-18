#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	int data;
	struct list *next;
} List;

List* create_list(){
	return NULL;
}

List* insert(List *list, int data){
	if (list==NULL){
		List *new = (List*) malloc(sizeof(List));
		new->data = data;
		new->next = NULL;
		list=new;
	} else {
		List *aux;
		List *new = (List*) malloc(sizeof(List));
		//i dont need to repeat the aux=aux->next, because my for alredy give me this information
		for (aux=list; aux->next!=NULL; aux=aux->next);
		new->data = data;
		new->next = (List*) NULL;
		aux->next = new;
	}
	return list;
}

void print_list(List *list){
	List *aux;
	for (aux=list; aux!=NULL; aux=aux->next){
		printf(" %d -> ", aux->data);
	}
	printf(' NULL');
}

int main(){
	List *list = create_list();	
	list = insert(list, 1);
	list = insert(list, 2);
	list = insert(list, 3);
	list = insert(list, 4);
	list = insert(list, 5);
	print_list(list);
	return 0;
}