#ifndef FILA_H
#define FILA_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"


typedef struct lista{
    No* no;
    struct lista *prox;
} Lista;

typedef struct fila{
    Lista *inicio;
    Lista *fim;
} Fila;


Fila* cria_fila();

int fila_vazia(Fila *f);

void insere_fila(Fila *fila, No *raiz);

No* retira_da_fila(Fila *fila);

void imprime_fila(Fila *fila);

void libera_fila(Fila *fila);


#endif