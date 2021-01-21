#ifndef LISTAS_H
#define LISTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
	int info;
	struct lista *prox;
} Lista;


/*Funcoes de lista encadeada*/

Lista* cria_lista();

Lista* lista_insere(Lista *l, int i);

void imprime_lista(Lista *l);

Lista* lista_busca(Lista *l, int v);

Lista *lista_retira(Lista *l, int v);

void lista_libera(Lista *l);

Lista *lista_insere_ordenado(Lista *l, int v);

int compara_listas(Lista *l1, Lista *l2);


#endif
