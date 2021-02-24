#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista_c {
    int info;
    struct lista_c *prox;
    struct lista_c *ant;
} Lista_c;


Lista_c* cria_lista_circular();
	
Lista_c* lista_circular_insere(Lista_c *lista, int dado);

Lista_c* lista_circular_retira(Lista_c *inicio_lista, Lista_c *bloco_a_retirar);

void imprime_lista_circular(Lista_c *lista);

void lista_circular_libera(Lista_c *inicio_lista);
