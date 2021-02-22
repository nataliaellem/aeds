#include "estacionamento.h"

Fila* cria_fila(){
    Fila *nova_fila = (Fila*) malloc(sizeof(Fila));
    nova_fila->inicio = NULL;
    nova_fila->fim = NULL;
    return nova_fila;
}


void insere_fila(Fila *fila, char *info){
    Carro *novo_carro = (Carro*) malloc(sizeof(Carro));
    strcpy(novo_carro->placa, info);
    novo_carro->prox = NULL;
    if (fila->fim != NULL){
        fila->fim->prox = novo_carro;
    } else{
        fila->inicio = novo_carro;
    }
    fila->fim = novo_carro;
}


char* retira_da_fila(Fila *fila){
    if (fila->inicio == NULL){
        return NULL;
    }
    Carro *auxiliar = fila->inicio;
    char *info = (char*) malloc(10 * sizeof(char));
    strcpy(info, auxiliar->placa);
    fila->inicio = auxiliar->prox;
    if (fila->inicio == NULL){
        fila->fim = NULL;
    }
    free(auxiliar);
    return (info);
}

void imprime_fila(Fila *fila){
    Carro *aux;
    printf("\n");
    for(aux = fila->inicio; aux != NULL; aux = aux->prox){
        printf("%s\t", aux->placa);
    }
    printf("\n\n");
}

void libera_fila(Fila *fila){
    Carro *c = fila->inicio;
    while(c != NULL){
        Carro *aux = c->prox;
        free(c);
        c = aux;
    }
    free(fila);
}