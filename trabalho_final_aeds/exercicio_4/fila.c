#include "fila.h"

Fila* cria_fila(){
    Fila *nova_fila = (Fila*) malloc(sizeof(Fila));
    nova_fila->inicio = NULL;
    nova_fila->fim = NULL;
    return nova_fila;
}


void insere_fila(Fila *fila, char *info){
    Lista *novo_no = (Lista*) malloc(sizeof(Lista));
    novo_no->senha = (char*) malloc(6 * sizeof(char));
    strcpy(novo_no->senha, info);
    novo_no->prox = NULL;

    if (fila->inicio == NULL && fila->fim == NULL) {
        fila->inicio = novo_no;
    } 

    else if (fila->inicio != NULL && fila->fim == NULL){
        fila->inicio->prox = novo_no;
        fila->fim = novo_no;
    }
    else if (fila->fim != NULL){
        fila->fim->prox = novo_no;
        fila->fim = novo_no;
    }
    novo_no->prox = NULL;
}


void imprime_fila(Fila *fila){
    Lista *aux;
    printf("\n");
    for(aux = fila->inicio; aux != NULL; aux = aux->prox){
        printf("%s - n° %d\t", aux->senha, aux->id);
    }
    printf("\n\n");
}

void libera_fila(Fila *fila){
    Lista *t = fila->inicio;
    while(t != NULL){
        Lista *aux = t->prox;
        free(t);
        t = aux;
    }
    free(fila);
}