#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
    char *senha;
    struct lista *prox;
} Lista;


typedef struct fila{
    Lista *inicio;
    Lista *fim;
} Fila;


Fila* cria_fila();

void insere_fila(Fila *fila, char *info);

void imprime_fila(Fila *fila);

void libera_fila(Fila *fila);