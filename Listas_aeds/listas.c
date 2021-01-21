#include "listas.h"

/*Funcoes de lista encadeada*/

Lista* cria_lista(){
	return NULL;
}

Lista* lista_insere(Lista *l, int i){
	Lista *novo = (Lista *)malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}

void imprime_lista(Lista *l){
	Lista *p;
	for(p = l; p != NULL; p = p->prox){
		printf("Valor: %d\n", p->info);
	}
}


Lista* lista_busca(Lista *l, int v){
	Lista *p;
	for(p=l;p!=NULL;p=p->prox){
		if(p->info==v){
			return p;
		}
	}
	if(p==NULL){
		printf("Elemento não encontrado\n");
		return NULL;
	}
}


void lista_libera(Lista *l){
	Lista *p=l;
	while(p!=NULL){
		Lista *t=p->prox;
		free(p);
		p=t;
	}
}

Lista *lista_insere_ordenado(Lista *l, int v){
	Lista *novo;
	novo=(Lista *)malloc(sizeof(Lista));
	novo->info=v;
	Lista *ant=NULL;
	Lista *p=l;
	while(p!=NULL && p->info<v){
		ant=p;
		p=p->prox;
	}
	if(ant==NULL){
		novo->prox=l;
		return novo;
	}
	else{
		ant->prox=novo;
		novo->prox=p;
		return l;
	}
}


int compara_listas(Lista *l1, Lista *l2){
	Lista *aux1 = l1, *aux2 = l2;
	while (aux1 != NULL && aux2 != NULL){
		if (aux1->prox == NULL && aux2->prox != NULL){
			return 0; //as listas são diferentes pois têm tamanhos diferentes
		}
		else if (aux1->prox != NULL && aux2->prox == NULL){
			return 0; //as listas são diferentes pois têm tamanhos diferentes
		} else {
			if (aux1->info != aux2->info){
				return 0; //as listas têm alguma informação diferente nesse caso
			} 
		}
		aux1 = aux1->prox; 
		aux2 = aux2->prox;
	}
	return 1; //são iguais
}
