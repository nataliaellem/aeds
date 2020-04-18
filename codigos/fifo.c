#include <stdio.h>
#include <stdlib.h>

//Estrutura FIFO: First In First Out.
struct lista {
	int info;
	struct lista *prox;
}; 
typedef struct lista Lista;

Lista* lst_cria () {
    return NULL;
}

Lista* lst_insere (Lista *l, int i){
	Lista *novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}

void imprime_fifo(Lista *list){
	Lista *aux=list;
	Lista *aux2=lst_cria(;
	for (aux=list; aux!=NULL; aux=aux->prox){
		aux2 = lst_insere(aux2, aux->info);
	}
	for (aux=aux2; aux!=NULL; aux=aux->prox){
		printf("%d -> ", aux->info);
	}
}



int main() {
	Lista *l;
	l = lst_cria();
	l = lst_insere(l, 1);
	l = lst_insere(l, 2);
	l = lst_insere(l, 3);
	l = lst_insere(l, 4);
	imprime_fifo(l);
	return 0;
}