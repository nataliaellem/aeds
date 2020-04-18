#include <stdio.h>
#include <stdlib.h>

struct lista {
	int info;
	struct lista *prox;
}; 
typedef struct lista Lista;

Lista* lst_cria () {
    return NULL;
}

Lista* lst_insere (Lista *l, int i){
	Lista *novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}

void imprime_lista(Lista *list){
	Lista *aux=list;
	//while(aux!=NULL){
	//	if (aux->prox == NULL){
	//		for (aux->prox = NULL; aux=list; aux->prox=aux){
	//			printf("%d -> ", aux->info);
	//		}
	//	}
	//	else{
	//		aux=aux->prox;
	//		imprime_lista(aux);
	//	}
	//}
	for (aux=list; aux!=NULL; aux=aux->prox){
		printf("%d -> ", aux->info);

	}
	printf("NULL\n");
}

int main() {
	Lista *l;
	l = lst_cria();
	l = lst_insere(l, 1);
	l = lst_insere(l, 2);
	l = lst_insere(l, 3);
	l = lst_insere(l, 4);
	imprime_lista(l);
	return 0;
}

//Estrtura FILO: First In Last Out, o primeiro a entrar é o último a sair

