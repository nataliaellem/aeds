#include "fila.h"
#include "arvore.h"


Fila* cria_fila(){
    Fila *nova_fila = (Fila*) malloc(sizeof(Fila));
    nova_fila->inicio = NULL;
    nova_fila->fim = NULL;
    return nova_fila;
}

int fila_vazia(Fila *f){
	return (f->inicio == NULL);
}


void insere_fila(Fila *fila, No *raiz){

	Lista *n = (Lista *) malloc(sizeof(Lista));

	n->no = raiz;
	n->prox = NULL;
	if(fila->fim != NULL) fila->fim->prox = n;
	else fila->inicio = n;
	fila->fim = n;
}


No* retira_da_fila(Fila *fila){
	Lista *t;
	No *n;
	if(fila_vazia(fila)){
		printf("Fila vazia!");
		return NULL;
	}
	t = fila->inicio;
	n = t->no;
	fila->inicio = t->prox;
	if(fila->inicio==NULL) fila->fim = NULL;
	free(t);
	return n;
}

void imprime_fila(Fila *fila){
    Lista *aux;
    printf("\n");
    for(aux = fila->inicio; aux != NULL; aux = aux->prox){
        printf("%c\t", aux->no->info);
    }
    printf("\n\n");
}

void libera_fila(Fila *fila){
    Lista *c = fila->inicio;
    while(c != NULL){
        Lista *aux = c->prox;
        free(c);
        c = aux;
    }
    free(fila);
}