#include "lista.h"

Lista* cria_lista(){
    Lista *lista = NULL;
    return lista;
}

Fila* cria_fila(){
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    fila->ini = fila->fim = NULL;
    return fila;
}

// Função que insere um elemento e retorna a lista encadeada
// na posição desse novo elemento
Lista* insere_lista(Lista *lista, float valor){
    if (lista == NULL){
        lista = (Lista*) malloc(sizeof(Lista));
        lista->info = valor;
        lista->prox = NULL;

        return lista;
    }
    Lista *novo_no = (Lista*) malloc(sizeof(Lista));
    novo_no->info = valor;
    novo_no->prox = lista;
    return novo_no;
}



// Funções recursivas do exercício 1

void imprime_lista_recursiva(Lista *lista){
    if (lista == NULL){
        printf("\n");
        exit(1);
    }
    printf("%.2f -> ", lista->info);
    Lista *aux = lista;
    return imprime_lista_recursiva(aux->prox);

}

void retira_aux(Lista *lista, float valor, Lista *ant){
    if (lista == NULL) {
        printf("O valor %.2f não está na lista.\n", valor);
        return;
    }
    if(lista->info == valor){
        Lista *retirado = lista;

        if (ant == NULL){
        lista = lista->prox; 
    } else {
        ant->prox = lista->prox;
    }

    free(retirado);
    printf("Valor %.2f retirado da lista.\n", valor);
    return;
    }

    retira_aux(lista->prox, valor, lista);
}

void lista_retira_recursiva(Lista *lista, float valor){
retira_aux(lista, valor, NULL);
}



void lista_libera_recursiva(Lista *lista){
    if (lista == NULL){
        exit(1);
    }
    Lista *aux = lista->prox;
    free(lista);
    return lista_libera_recursiva(aux);
}

/////////////////////////////////////////////////////////////

// Exercício 2 

Lista* lista_intercala(Lista *l1, Lista *l2){
    Lista *lista_intercala = (Lista*) malloc(sizeof(Lista));
    Lista *aux1 = l1, *aux2 = l2, *aux3 = lista_intercala;
    while(aux1 != NULL || aux2 != NULL){
        if (aux1->info == aux2->info){
            aux3->info = aux1->info;
            aux3 = aux3->prox;
            aux3->prox = (Lista*) malloc(sizeof(Lista));
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
    return lista_intercala;
}

/////////////////////////////////////////////////////////////

// Exercício 3