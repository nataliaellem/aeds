#include "lista_encadeada.h"

Lista* cria_lista(){
    Lista *lista = NULL;
    return lista;
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

Lista* imprime_lista_recursiva(Lista *lista, Lista *inicio_lista){
    if (lista == NULL){
        printf("\n");
        return inicio_lista;
    }
    printf("%.2f -> ", lista->info);
    imprime_lista_recursiva(lista->prox, inicio_lista);
    return inicio_lista;
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
        return;
    }
    Lista *aux = lista->prox;
    free(lista);
    return lista_libera_recursiva(aux);
}

/////////////////////////////////////////////////////////////

// Exercício 2 

Lista* lista_intercala(Lista *l1, Lista *l2){
    Lista *intercalacao = cria_lista();
    Lista *aux1, *aux2;
    for(aux1 = l1; aux1 != NULL; aux1 = aux1->prox){
        for (aux2 = l2; aux2 != NULL; aux2 = aux2->prox){
            if (aux1->info == aux2->info){
                intercalacao = insere_lista(intercalacao, aux1->info);
            }
        }
        aux2 = l2;

    }
    return intercalacao;
}

/////////////////////////////////////////////////////////////


