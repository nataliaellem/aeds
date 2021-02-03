#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"


//Pilhas com vetor

Pilha_vetor *pilha_vetor_cria() {
    Pilha_vetor *pilha = (Pilha_vetor *) malloc(sizeof(Pilha_vetor));
    pilha->ultima_posicao = 0;

    return pilha;
}

void pilha_vetor_push(Pilha_vetor *pilha, char valor) {
    if (pilha->ultima_posicao == N) {
        printf("Acapacidade da pilha estourou.\n");
        exit(1);
    }

    pilha->vetor[pilha->ultima_posicao++] = valor;
}

char pilha_vetor_pop(Pilha_vetor *pilha) {
    if (pilha_vetor_vazia(pilha)) {
        printf("Pilha vazia\n");
        exit(1);
    }
    return pilha->vetor[--pilha->ultima_posicao];
}

int pilha_vetor_vazia(Pilha_vetor *pilha){
    return (pilha->ultima_posicao == 0);
}


void pilha_vetor_libera(Pilha_vetor *pilha){
    free(pilha);
}


void pilha_vetor_imprime(Pilha_vetor *pilha){
    for (int i = pilha->ultima_posicao - 1; i >= 0; i--){
        printf("%c\n", pilha->vetor[i]);
    }
}



//Pilhas com listas

Pilha_lista *pilha_lista_cria(){
    Pilha_lista *pilha = (Pilha_lista*) malloc(sizeof(Pilha_lista));
    pilha->topo = NULL;
    return pilha;
}

void pilha_lista_push(Pilha_lista *pilha, char valor){
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    lista->info = valor;
    lista->prox = pilha->topo;
    pilha->topo = lista;
}


char pilha_lista_pop(Pilha_lista *pilha){
    Lista *lista;
    char c;
    if (pilha_lista_vazia(pilha)) {
        printf("Pilha vazia\n");
        exit(1);
    }
    lista = pilha->topo;
    c = lista->info;
    pilha->topo = lista->prox;
    free(lista);
    return c;
}

int pilha_lista_vazia(Pilha_lista *pilha){
    return (pilha->topo == NULL);
}


void pilha_lista_libera(Pilha_lista *pilha){
    Lista *lista = pilha->topo;
    while(lista != NULL){
        Lista *aux = lista->prox;
        free(lista);
        lista = aux;
    }
    free(pilha);
}


void pilha_lista_imprime(Pilha_lista *pilha){
    Lista *lista;
    for(lista = pilha->topo; lista != NULL; lista = lista->prox){
        printf("%c\n", lista->info);
    }
}






















