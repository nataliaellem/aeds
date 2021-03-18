#include <string.h>
#include "arvore.h"


// Função auxiliar que informa se o caracter é um dos operadores indicados no exercício

int operador(char c){
    return (c == '*' || c == '+' || c == '-' || c == '/');
}


No* insere_expressao_posordem(Arvore *arvore, No *no, char c){
    printf("c: %c\n", c);
    if (no == NULL){
        if (no == arvore->raiz){
            arvore->raiz = novo_no(c);
            return arvore->raiz;
        }
        else {
            no = novo_no(c);
            return no;
        }
    }
    printf("raiz: %c\n", arvore->raiz->info);
    if (operador(c)){
        if (operador(no->info)){
            no->dir = insere_expressao_posordem(arvore, no->dir, c);
        }
        else {
            if (no->esq == NULL){
                char aux = no->info;
                no->info = c;
                no->esq = insere_expressao_posordem(arvore, no->esq, aux);
            }
            // else if (no->esq != NULL){
            //     char aux = no->info;
            //     char aux2 = no->esq->info;
            //     no->info = c;
            //     no->esq->info = aux;
            //     no->esq->esq = insere_expressao_posordem(arvore, no->esq->esq, aux2);
            // }
        }
        return no;
    }
    else if (! operador(c) && operador(no->info)){
        if (no->esq == NULL){
            no->esq = insere_expressao_posordem(arvore, no->esq, c);
            return no->esq;
        }
        else if (no->esq != NULL && no->esq->esq != NULL){
            no->dir = insere_expressao_posordem(arvore, no->dir, c);
            return no->dir;
        }
        else if (no->esq != NULL && no->esq->esq == NULL){
            no->esq->esq = insere_expressao_posordem(arvore, no->esq->esq, c);
            return no->esq->esq;
        }
    }
    return no;
}



No* insere_expressao_infixa(Arvore *arvore, No *no, char c){
    if (no == NULL){
        if (no == arvore->raiz){
            arvore->raiz = novo_no(c);
            return arvore->raiz;
        }
        else {
            no = novo_no(c);
            return no;
        }
    }
    if (operador(c)){
        if (operador(no->info)){
            no->dir = insere_expressao_infixa(arvore, no->dir, c);
        }
        // Se o nó não tem um operador, ou seja, tem um valor
        else {
            if (no->esq == NULL){
                char aux = no->info;
                no->info = c;
                no->esq = insere_expressao_infixa(arvore, no->esq, aux);
            }
            else if (no->esq != NULL){
                char aux = no->info;
                no->info = c;
                no->dir = insere_expressao_infixa(arvore, no->dir, aux);
            }
        }
        return no;
    }
    // Se o carcter c não se trata de um operador então a raiz tem que ser um operador
    else if (! operador(c) && operador(no->info)){
        if (no->esq == NULL){
            printf("Expressão mal formada.\n");
            return NULL;
        }
        else {
            no->dir = insere_expressao_infixa(arvore, no->dir, c);
        }
        return no;
    }
    else {
        return no;
    }
}


Arvore* expressao_matematica(Arvore *arvore, char tipo){
    char *expressao = (char*) malloc(50 * sizeof(char));
    printf("Digite a expressão matemática: ");
    scanf("%s", expressao);
    printf("\n");

    arvore = (Arvore*) malloc(sizeof(Arvore));
    arvore->raiz = NULL;

    int i = 0;
    while(expressao[i] != '\0'){
        if (tipo == 'i'){
            insere_expressao_infixa(arvore, arvore->raiz, expressao[i]);
        }
        else if (tipo == 'p'){
            insere_expressao_posordem(arvore, arvore->raiz, expressao[i]);
        } 
        else {
            break;
        }
        i++;
    }
    return arvore;
}

int main(){
    Arvore *arvore = cria_arvore();
    arvore = expressao_matematica(arvore, 'i');

    printf("\nÁrvore infixa\n");
    imprime_arvore_infixa(arvore->raiz);
    printf("\n");
    printf("\n==== Estrutura da árvore infixa ==== \n");
    imprime_arvore(arvore->raiz);

    // Arvore *arv = cria_arvore();
    // arv = expressao_matematica(arv, 'p');

    // printf("\n\nÁrvore pós-ordem\n");
    // imprime_arvore_posordem(arv->raiz);
    // printf("\n==== Estrutura ====\n");
    // imprime_arvore(arv->raiz);
    return 0;
}