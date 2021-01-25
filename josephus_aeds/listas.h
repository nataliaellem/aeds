#ifndef LISTAS_H
#define LISTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
    char *info;
    struct lista *prox;
    struct lista *ant;
} Lista;

Lista* cria_lista();
	
Lista* lista_circular_insere(Lista *lista, char *dado);

Lista* lista_circular_retira(Lista *inicio_lista, Lista *bloco_a_retirar);

void imprime_lista(Lista *lista);


#endif