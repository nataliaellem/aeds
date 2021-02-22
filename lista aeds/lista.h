#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct lista {
    float info;
    struct lista *prox;
    struct lista *ant;
} Lista;

typedef struct fila{
    Lista *ini;
    Lista *fim;
} Fila;


Lista* cria_lista();

Fila* cria_fila();

Lista* insere_lista(Lista *lista, float valor);

void imprime_lista_recursiva(Lista *lista);

void lista_retira_recursiva(Lista *lista, float valor);

void lista_libera_recursiva(Lista *lista);

Lista* lista_intercala(Lista *l1, Lista *l2);


