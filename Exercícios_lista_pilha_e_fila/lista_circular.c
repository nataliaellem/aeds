// Funções para o exercício 3

#include "lista_circular.h"


Lista_c* cria_lista_circular(){
	return NULL;
}


//Função que insere novo elemento no início da lista circular

Lista_c* lista_circular_insere(Lista_c *inicio_lista, int dado){

	Lista_c *novo = (Lista_c*) malloc(sizeof(Lista_c));
	novo->info = dado;
    
    //Se a lista for nula:
    if (inicio_lista == NULL) {
        novo->prox = NULL;
        novo->ant = NULL;
        return novo;
    }

    //Se a lista já tiver um elemento
    else if(inicio_lista->prox == NULL){

        novo->prox = inicio_lista;
        novo->ant = inicio_lista;
        inicio_lista->ant = novo;
        inicio_lista->prox = novo;

        // Para deixar a lista ordenada
        if (novo->info < inicio_lista->info){
            return novo;
        } else {
            return inicio_lista;
        }
    } 
    
    //mais de um elemento
    else if (inicio_lista != NULL && inicio_lista->prox != NULL){
        Lista_c *aux = inicio_lista;
     
        do {
            if (novo->info < aux->info){
                novo->prox = aux;
                novo->ant = aux->ant;
                aux->ant->prox = novo;
                aux->ant = novo;
                if (aux == inicio_lista){
                    return novo;
                }
                return inicio_lista;

            }
            aux = aux->prox;
        } while(aux != inicio_lista);

        // Caso tenha saido do loop sem adicionar o bloco à lista,
        // significa que a informação do bloco tem o maior valor
        // então será alocado aqui no final da lista circular
        novo->prox = inicio_lista;
        novo->ant = inicio_lista->ant;
        inicio_lista->ant->prox = novo;
        inicio_lista->ant = novo;
        return inicio_lista;
    }
 

	return inicio_lista;
}

//Função que retira um bloco da lista

Lista_c *lista_circular_retira(Lista_c *inicio_lista, Lista_c *bloco_a_retirar){
    if (bloco_a_retirar == inicio_lista){
        inicio_lista->ant->prox = inicio_lista->prox;
        inicio_lista->prox->ant = inicio_lista->ant;
        inicio_lista = inicio_lista->prox;
        return inicio_lista;
    }
    for (Lista_c *aux = inicio_lista->prox; aux != inicio_lista; aux = aux->prox){
        if (aux == bloco_a_retirar){
            bloco_a_retirar->ant->prox = bloco_a_retirar->prox;
            bloco_a_retirar->prox->ant = bloco_a_retirar->ant;
            return inicio_lista;
        }
    }
    return inicio_lista;
}

void imprime_lista_circular(Lista_c *lista){
    if (lista == NULL){
	    printf("\n");
        return;
    }
	Lista_c *p = lista;
	do{
		printf("-> %d ", p->info);
		p = p->prox;
	} while(p != lista);
	printf("\n");
}


void lista_circular_libera(Lista_c *inicio_lista){
	Lista_c *p = inicio_lista;
	do{
		Lista_c *aux = p->prox;
		free(p);
		p = aux;
	} while(p != inicio_lista);
}
