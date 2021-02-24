#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct carro {
    char placa[10];
    int idade_motorista;
    struct carro *prox;
} Carro;


typedef struct fila{
    Carro *inicio;
    Carro *fim;
} Fila;


Fila* cria_fila();

void insere_fila(Fila *fila, char *info, int idade_motorista);

char* retira_da_fila(Fila *fila);

void imprime_fila(Fila *fila);

void libera_fila(Fila *fila);

void arquivo_estacionamento(Fila *fila, char *nome_arquivo);




