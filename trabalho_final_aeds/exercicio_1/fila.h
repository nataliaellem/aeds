#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char *nome_piloto;
    int id;
    struct no *prox;
} No;


typedef struct fila{
    No *inicio;
    No *fim;
} Fila;


Fila* cria_fila();

void insere_fila(Fila *fila, char *info, int id);

char* retira_da_fila(Fila *fila, int *id);

void imprime_fila(Fila *fila);

void libera_fila(Fila *fila);