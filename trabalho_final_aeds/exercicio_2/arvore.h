#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



typedef struct no {
    char info;
    struct no *esq;
    struct no *dir;
} No;

typedef struct arvore {
    No *raiz;
} Arvore;



Arvore* cria_arvore();

int arvore_vazia(Arvore *arvore);

int no_vazio(No *no);

No* novo_no(char dado);

void imprime_arvore_infixa(No *raiz);

void imprime_arvore_posordem(No *raiz);

int max2(int a,int b);

int arvore_altura(No *raiz);

void imprime_arvore(No *r);

#endif