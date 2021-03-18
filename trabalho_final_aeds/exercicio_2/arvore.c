#include "arvore.h"
#include "fila.h"


Arvore* cria_arvore(){
    return NULL;
}


int arvore_vazia(Arvore *arvore){
    return (arvore == NULL);
}

int no_vazio(No *no){
    return (no == NULL);
}

No* novo_no(char dado){
    No *no = (No*) malloc(sizeof(No));
    no->dir = NULL;
    no->esq = NULL;
    no->info = dado;
    return no;
}

void imprime_arvore_infixa(No *raiz){
    if (!no_vazio(raiz)){
        imprime_arvore_infixa(raiz->esq);
        printf("%c\t", raiz->info);
        imprime_arvore_infixa(raiz->dir);
    }
}


void imprime_arvore_posordem(No *raiz){
    if (!no_vazio(raiz)){
        imprime_arvore_posordem(raiz->esq);
        imprime_arvore_posordem(raiz->dir);
        printf("%c\t", raiz->info);
    }
}


int max2(int a,int b){
	return (a>b) ? a : b ;
}


int arvore_altura(No *raiz){
	if(no_vazio(raiz))
		return -1; 
	else 
		return 1 + max2(arvore_altura(raiz->esq),arvore_altura(raiz->dir));
}


// Função que imprime a estrutura da árvore

void imprime_arvore(No *r){
	/*Função desenvolvida por RaulFM
	  Esta função usa de uma fila de impressão
	  Para imprimir uma árvore binária
	  De forma em que seus espaços são calculados
	  de forma logarítmica de acordo com a linha
	  a ser impressa;
	*/

	Fila *fila = cria_fila(); //FILA DE IMPRESSÃO
	int h = arvore_altura(r); // h == altura
	int linha = h-1;
    int i;

	//PRIMEIRA IMPRESSAO
	if(r==NULL){
		printf("Arvoreore vazia!\n");
		return;
	}
	// A IMPRESÃO FUNCIONA DE FORMA LOGARÍTIMICA
	// A QUANTIDADE DE ESPAÇOS É CALCULADA COMO:
	// ESPAÇOS EM UMA LINHA L É DEFINIDO POR:
	// Nlinha = log base 2 dos espaços
	// ENTÃO:---espaços = 2 ** n_linha---
	
	for(i=0;i<pow(2,h);i++) putchar(' ');
	printf("%c\n",r->info);

	// INSERE OS PRIMEIROS FILHOS NA FILA DE IMPRESSÃO
    insere_fila(fila, r->esq);
    insere_fila(fila, r->dir);

   	No *no_lido; // NÓ QUE SERÁ LIDO DA FILA;
    int pot_atual=1;
    int epl=0; // elemento p/ linha

    while(linha>=0){
		no_lido = retira_da_fila(fila);

		if(no_lido != NULL){
			for(i=0;i<pow(2,linha);i++) putchar(' ');
			printf("%c",no_lido->info);			
	
			if(linha!=0){ // ALINHAMENTO
				for(i=0;i<((pow(2,linha+1)-1)-pow(2,linha));i++)putchar(' '); 
			}

			insere_fila(fila,no_lido->esq);
			insere_fila(fila,no_lido->dir);
		}
		else{
			for(i=0;i<pow(2,linha);i++) putchar(' ');
			putchar(' ');

			if(linha!=0){ // ALINHAMENTO
				for(i=0;i<((pow(2,linha+1)-1)-pow(2,linha));i++)putchar(' '); 
			}

			insere_fila(fila,NULL);
			insere_fila(fila,NULL);
		}
		epl++;	// APÓS QUALQUER UM DOS CASOS, UM ELEMENTO FOI IMPRESSO
		
		// VERIFICAÇÃO DA QUANTIDADE DE ELEMENTOS NA LINHA
		if(epl==pow(2,pot_atual)){
			pot_atual++;
			linha--;
			epl=0;
			putchar('\n');
		}
	}
	putchar('\n');
	libera_fila(fila);
}