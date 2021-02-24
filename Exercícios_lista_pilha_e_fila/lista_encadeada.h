#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct lista {
    float info;
    struct lista *prox;
    struct lista *ant;
} Lista;


Lista* cria_lista();


Lista* insere_lista(Lista *lista, float valor);

Lista* imprime_lista_recursiva(Lista *lista, Lista *inicio_lista);

void lista_retira_recursiva(Lista *lista, float valor);

void lista_libera_recursiva(Lista *lista);

Lista* lista_intercala(Lista *l1, Lista *l2);


