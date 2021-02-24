#include "pilha.h"

Pilha *pilha_cria(){
    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void pilha_push(Pilha *pilha, char valor){
    Lista_p *lista = (Lista_p*) malloc(sizeof(Lista_p));
    lista->info = valor;
    lista->prox = pilha->topo;
    pilha->topo = lista;
}

void pilha_push_int(Pilha *pilha, int valor){
    Lista_p *lista = (Lista_p*) malloc(sizeof(Lista_p));
    lista->int_info = valor;
    lista->prox = pilha->topo;
    pilha->topo = lista;
}

char pilha_pop(Pilha *pilha){
    Lista_p *lista;
    char c = '0';
    if (pilha_vazia(pilha)) {
        printf("Pilha vazia\n");
        return c;
    }
    lista = pilha->topo;
    c = lista->info;
    pilha->topo = lista->prox;
    free(lista);
    return c;
}

int pilha_pop_int(Pilha *pilha){
    Lista_p *lista;
    int i;
    if (pilha_vazia(pilha)) {
        return 0;
    }
    lista = pilha->topo;
    i = lista->int_info;
    pilha->topo = lista->prox;
    free(lista);
    return i;
}

int pilha_vazia(Pilha *pilha){
    return (pilha->topo == NULL);
}


void pilha_libera(Pilha *pilha){
    Lista_p *lista = pilha->topo;
    while(lista != NULL){
        Lista_p *aux = lista->prox;
        free(lista);
        lista = aux;
    }
    free(pilha);
}


void pilha_imprime(Pilha *pilha){
    Lista_p *lista;
    for(lista = pilha->topo; lista != NULL; lista = lista->prox){
        printf("-> %c ", lista->info);
    }
    printf("\n");
}

void pilha_imprime_int(Pilha *pilha){
    Lista_p *lista;
    for(lista = pilha->topo; lista != NULL; lista = lista->prox){
        printf("-> %d ", lista->int_info);
    }
    printf("\n");
}
