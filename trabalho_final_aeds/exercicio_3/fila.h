#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct processo {
    char *descricao;
    int id;
    struct processo *prox;
} Processo;


typedef struct fila{
    Processo *inicio;
    Processo *fim;
} Fila;


Fila* cria_fila();

void insere_fila(Fila *fila, char *info, int id);

char* retira_da_fila(Fila *fila, int *id);

void imprime_fila(Fila *fila);

void libera_fila(Fila *fila);