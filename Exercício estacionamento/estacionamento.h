#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct carro {
    char placa[10];
    struct carro *prox;
} Carro;


typedef struct fila{
    Carro *inicio;
    Carro *fim;
} Fila;


Fila* cria_fila();

void insere_fila(Fila *fila, char *info);

char* retira_da_fila(Fila *fila);

void imprime_fila(Fila *fila);

void libera_fila(Fila *fila);






