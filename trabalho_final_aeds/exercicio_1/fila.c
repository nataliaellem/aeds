#include "fila.h"

Fila* cria_fila(){
    Fila *nova_fila = (Fila*) malloc(sizeof(Fila));
    nova_fila->inicio = NULL;
    nova_fila->fim = NULL;
    return nova_fila;
}


void insere_fila(Fila *fila, char *info, int id){
    No *novo_no = (No*) malloc(sizeof(No));
    novo_no->nome_piloto = (char*) malloc(50 * sizeof(char));
    strcpy(novo_no->nome_piloto, info);
    novo_no->id = id;
    novo_no->prox = NULL;
    // Se o início e o fim da fila tiverem nulos, então no início 
    // será colocado o novo nó e o fim vai continuar como NULL
    if (fila->inicio == NULL && fila->fim == NULL) {
        fila->inicio = novo_no;
    } 
    // Se o início da fila já estiver preenchido e o final da fila estiver nulo, significa 
    // que só tem um elemento na fila e então o novo nó ficará no final da fila
    else if (fila->inicio != NULL && fila->fim == NULL){
        fila->inicio->prox = novo_no;
        fila->fim = novo_no;
    }
    // Por último, se o fim da fila está preenchido, então o fim da fila 
    // atual deve apontar para o novo nó e o fim da fila será agora o novo nó
    else if (fila->fim != NULL){
        fila->fim->prox = novo_no;
        fila->fim = novo_no;
    }
    novo_no->prox = NULL;
}

// Função que retira o primeiro elemento da fila

char* retira_da_fila(Fila *fila, int *id){
    if (fila->inicio == NULL){
        return NULL;
    }
    No *auxiliar = fila->inicio;
    char *info = (char*) malloc(50 * sizeof(char));
    strcpy(info, auxiliar->nome_piloto);
    *id = auxiliar->id;
    fila->inicio = auxiliar->prox;
    if (fila->inicio == NULL){
        fila->fim = NULL;
    }
    free(auxiliar);
    return (info);
}

void imprime_fila(Fila *fila){
    No *aux;
    printf("\n");
    for(aux = fila->inicio; aux != NULL; aux = aux->prox){
        printf("%s - n° %d\t", aux->nome_piloto, aux->id);
    }
    printf("\n\n");
}

void libera_fila(Fila *fila){
    No *t = fila->inicio;
    while(t != NULL){
        No *aux = t->prox;
        free(t);
        t = aux;
    }
    free(fila);
}