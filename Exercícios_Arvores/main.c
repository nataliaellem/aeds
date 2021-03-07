#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvores.h"


int main(){

    Arvore tree2 = cria_arvore_com_raiz('1');
    arvore_insere(tree2.raiz, '5');
    arvore_insere(tree2.raiz, '4');
    arvore_insere(tree2.raiz, '2');
    arvore_insere(tree2.raiz, '3');
    arvore_insere(tree2.raiz, '6');
    arvore_insere(tree2.raiz, '7');
    arvore_insere(tree2.raiz, '8');
    arvore_insere(tree2.raiz, '9');
    
    printf("===== Impressão pós-ordem =====\n");
    imprime_pos_ordem(tree2.raiz);
    printf("\n\n===== Impressão in-order =====\n");
    imprime_in_order(tree2.raiz);
    printf("\n\n===== Impressão pré-ordem =====\n");
    imprime_pre_ordem(tree2.raiz);

    printf("\n\nNúmero de folhas da árvore: %d\n", conta_nos(tree2.raiz));
    printf("\nÁrvore tree2: nós com um filho: %d\n", conta_nos_um_filho(tree2.raiz));
    printf("\nÁrvore tree2: nós com dois filho: %d\n", conta_nos_dois_filhos(tree2.raiz));

    Arvore tree = cria_arvore_com_raiz('a');
    arvore_insere(tree.raiz, 'i');
    arvore_insere(tree.raiz, 't');
    arvore_insere(tree.raiz, 'l');
    arvore_insere(tree.raiz, 'n');
    arvore_insere(tree.raiz, 'n');

    Histograma *hist = ocorrencia_caracteres(tree.raiz);
    printf("\n ====== Histograma ======\nCaracter / Ocorrências\n");
    for (int i = 0; i < 7; i++){
        if (hist[i].ocorrencias != 0){
            printf("%c: ", hist[i].caracter);
            
            // Cada estrelinha (*) representa uma ocorrência do referente caracter
            for (int j = 0; j < hist[i].ocorrencias; j++){
                printf("* ");
            }
            printf("\n");
        }
    }
    printf("\n");

    return 0;
}