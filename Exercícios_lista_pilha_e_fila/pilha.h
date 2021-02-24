#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct lista_p {
    char info;
    int int_info;
    struct lista_p *prox;
} Lista_p;


typedef struct pilha {
    Lista_p *topo;
} Pilha;


Pilha *pilha_cria();

void pilha_push(Pilha *pilha, char valor);

void pilha_push_int(Pilha *pilha, int valor);

char pilha_pop(Pilha *pilha);

int pilha_pop_int(Pilha *pilha);

int pilha_vazia(Pilha *pilha);

void pilha_libera(Pilha *pilha);

void pilha_imprime(Pilha *pilha);

void pilha_imprime_int(Pilha *pilha);