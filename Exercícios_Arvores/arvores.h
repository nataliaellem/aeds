#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// A struct no será o tipo de cada nó da árvore
typedef struct no{
    char info;
    struct no *esq;
    struct no *dir;
} No;


// A struct Arvore irá armazenar a raiz de uma árvore para 
// que a raiz não seja perdida ao longo do programa
typedef struct arvore{
    No *raiz;
} Arvore;


typedef struct histograma{
    char caracter;
    int ocorrencias;
} Histograma;


Arvore cria_arvore_vazia();

Arvore cria_arvore(char info, No *sae, No *sad);

Arvore cria_arvore_com_raiz(char info);

No* cria_no(char info);

int arvore_vazia(Arvore arvore);

int no_vazia(No *no);

void imprime_pre_ordem(No *raiz);

void insere_preordem(No *raiz, char info);

void imprime_in_order(No *raiz);

void insere_inorder(No *raiz, char info);

void imprime_pos_ordem(No *raiz);

void insere_posordem(No *raiz, char info);

No *arvore_insere(No *raiz, char info);

int conta_nos(No *no);

int conta_filhos_por_no(No *no);

int conta_nos_um_filho(No *no);

int conta_nos_dois_filhos(No *no);

Histograma* ocorrencia_caracteres(No *raiz);

void conta_caracteres(No *no, Histograma *hist, int tam_hist);