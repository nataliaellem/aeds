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
    
    
    imprime_pos_ordem(tree2.raiz);


    printf("tree2 nos com um filho: %d\n", conta_nos_um_filho(tree2.raiz));
    printf("tree2 nos com dois filho: %d\n", conta_nos_dois_filhos(tree2.raiz));

    Arvore tree = cria_arvore_com_raiz('a');
    arvore_insere(tree.raiz, 'i');
    arvore_insere(tree.raiz, 't');
    arvore_insere(tree.raiz, 'l');
    arvore_insere(tree.raiz, 'n');
    arvore_insere(tree.raiz, 'n');

    Histograma *histograma = ocorrencia_caracteres(tree.raiz);
    for (int i = 0; i < 7; i++){
        printf("%c: %d   ", histograma[i].caracter, histograma[i].ocorrencias);
    }

    return 0;
}