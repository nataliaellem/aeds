#include "listas.h"

//Funções para listas duplamente encadeadas circulares

Lista* cria_lista(){
	return NULL;
}

//Função que insere novo elemento no início da lista circular

Lista* lista_circular_insere(Lista *lista, char *dado){

	Lista *novo = (Lista*) malloc(sizeof(Lista));
	novo->info = (char*) malloc(30 * sizeof(char));
    strcpy(novo->info, dado);
    
    //Se a lista for nula:
    if (lista == NULL) {
        novo->prox = NULL;
        novo->ant = NULL;
    }

    //Se a lista já tiver elementos
    //se tiver apenas um elemento
    else if(lista->prox == NULL){
        novo->prox = lista;
        novo->ant = lista;
        lista->ant = novo;
        lista->prox = novo;
    } 
    
    //mais de um elemento
    else if (lista != NULL && lista->prox != NULL){
	    novo->prox = lista; //inserindo o novo bloco da lista como primeiro elemento
        novo->ant = lista->ant;
        lista->ant->prox = novo;
        lista->ant = novo;
    }
 

	return novo;
}

//Função que retira um bloco da lista

Lista *lista_circular_retira(Lista *inicio_lista, Lista *bloco_a_retirar){
    if (bloco_a_retirar == inicio_lista){
        inicio_lista->ant->prox = inicio_lista->prox;
        inicio_lista->prox->ant = inicio_lista->ant;
        inicio_lista = inicio_lista->prox;
        return inicio_lista;
    }
    for (Lista *aux = inicio_lista->prox; aux != inicio_lista; aux = aux->prox){
        if (aux == bloco_a_retirar){
            bloco_a_retirar->ant->prox = bloco_a_retirar->prox;
            bloco_a_retirar->prox->ant = bloco_a_retirar->ant;
            return inicio_lista;
        }
    }
}

void imprime_lista(Lista *lista){
    printf("%s ", lista->info);
    //Se a lista tiver só um elemento:
    if (lista->prox == NULL){
	    printf("\n");
        return;
    }
	Lista *p = lista->prox;
	if(p){
		do{
			printf("-> %s ", p->info);
			p = p->prox;
		} while(p != lista);
	}
	printf("\n");
}
