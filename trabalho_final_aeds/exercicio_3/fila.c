#include "fila.h"

Fila* cria_fila(){
    Fila *nova_fila = (Fila*) malloc(sizeof(Fila));
    nova_fila->inicio = NULL;
    nova_fila->fim = NULL;
    return nova_fila;
}


void insere_fila(Fila *fila, char *info, int id){
    Processo *novo_processo = (Processo*) malloc(sizeof(Processo));
    novo_processo->descricao = (char*) malloc(50 * sizeof(char));
    strcpy(novo_processo->descricao, info);
    novo_processo->id = id;
    novo_processo->prox = NULL;

    if (fila->inicio == NULL && fila->fim == NULL) {
        fila->inicio = novo_processo;
    } 

    else if (fila->inicio != NULL && fila->fim == NULL){
        fila->inicio->prox = novo_processo;
        fila->fim = novo_processo;
    }
    else if (fila->fim != NULL){
        fila->fim->prox = novo_processo;
        fila->fim = novo_processo;
    }
    novo_processo->prox = NULL;
}

// Função que retira o primeiro elemento da fila

char* retira_da_fila(Fila *fila, int *id){
    if (fila->inicio == NULL){
        return NULL;
    }
    Processo *auxiliar = fila->inicio;
    char *info = (char*) malloc(50 * sizeof(char));
    strcpy(info, auxiliar->descricao);
    *id = auxiliar->id;
    fila->inicio = auxiliar->prox;
    if (fila->inicio == NULL){
        fila->fim = NULL;
    }
    free(auxiliar);
    return (info);
}

void imprime_fila(Fila *fila){
    Processo *aux;
    printf("\n");
    for(aux = fila->inicio; aux != NULL; aux = aux->prox){
        printf("%s - n° %d\t", aux->descricao, aux->id);
    }
    printf("\n\n");
}

void libera_fila(Fila *fila){
    Processo *t = fila->inicio;
    while(t != NULL){
        Processo *aux = t->prox;
        free(t);
        t = aux;
    }
    free(fila);
}