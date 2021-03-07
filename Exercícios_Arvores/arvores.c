#include "arvores.h"

// Criando uma árvore vazia
Arvore cria_arvore_vazia(){
    Arvore arvore;
    arvore.raiz = NULL; 
    return arvore;
}

// Criando uma árvore não vazia com dois nos
Arvore cria_arvore(char info, No *sae, No *sad){
    Arvore arvore;
    arvore.raiz = (No*) malloc(sizeof(No));
    arvore.raiz->info = info;
    arvore.raiz->esq = sae;
    arvore.raiz->dir = sad;
    return arvore;
}

Arvore cria_arvore_com_raiz(char info){
    Arvore arvore;
    arvore.raiz = (No*) malloc(sizeof(No));
    arvore.raiz->info = info;
    arvore.raiz->esq = NULL;
    arvore.raiz->dir = NULL;
    return arvore;
}

No* cria_no(char info){
    No *nova_no = (No*) malloc(sizeof(No));
    nova_no->info = info;
    nova_no->esq = NULL;
    nova_no->dir = NULL;
    return nova_no;
}

// Função que verifica se uma árvore está vazia
int arvore_vazia(Arvore arvore){
    return arvore.raiz == NULL;
    // se vazia retorna 1, se não retorna 0
}

int no_vazio(No *no){
    return no == NULL;
}

/////////////// Exercício 1 ////////////////
// Implementando os três tipos de percurso em árvores

// Pré-ordem imprime 
void imprime_pre_ordem(No *raiz){
    if (no_vazio(raiz) != 1){
        printf("%c  ", raiz->info);
        imprime_pre_ordem(raiz->esq);
        imprime_pre_ordem(raiz->dir);
    }
}


// Ordem simétrica imprime
void imprime_in_order(No *raiz){
    if (no_vazio(raiz) != 1){
        imprime_pre_ordem(raiz->esq);
        printf("%c  ", raiz->info);
        imprime_pre_ordem(raiz->dir);
    }
}


// Pós-ordem imprime
void imprime_pos_ordem(No *raiz){
    if (no_vazio(raiz) != 1){
        imprime_pre_ordem(raiz->esq);
        imprime_pre_ordem(raiz->dir);
        printf("%c  ", raiz->info);
    }
}


////////////// Exercício 2 ///////////////

No *arvore_insere(No *raiz, char info){
    if (raiz == NULL){
        // Chama a função que cria um nó e insere a informação
        raiz = cria_no(info);
    } 
    else if (info < raiz->info){
        raiz->esq = arvore_insere(raiz->esq, info);
    } 
    else if (info >= raiz->info){
        raiz->dir = arvore_insere(raiz->dir, info);
    }
    return raiz;
}


//////////// Exercício 3 ////////////////

// Função que conta o número de nos de uma árvore binária
int conta_nos(No *no){
    if(no == NULL){
        return 0;
    }
    else {
        return 1 + conta_nos(no->esq) + conta_nos(no->dir);
  
    } 

}

// Função que retorna quantos filhos cada nó da árvore tem
int conta_filhos_por_no(No *no){
    int cont = 0;
    if (no->dir != NULL){
      cont++;
    }
    if (no->esq != NULL){
      cont++;
    }
    return cont;
}

// Função que conta quantos nós da árvore tem um filho
int conta_nos_um_filho(No *no){
    if(no == NULL){
        return 0;
    }
    else if (conta_filhos_por_no(no) == 1){
        return 1 + conta_nos_um_filho(no->esq) + conta_nos_um_filho(no->dir);
  
    } 
    else {
      return 0 + conta_nos_um_filho(no->esq) + conta_nos_um_filho(no->dir);
    }
}

// Função que retorna quantos nós da árvore tem dois filhos
int conta_nos_dois_filhos(No *no){
    if(no == NULL){
        return 0;
    }
    else if (conta_filhos_por_no(no) == 2){
        return 1 + conta_nos_dois_filhos(no->esq) + conta_nos_dois_filhos(no->dir);
  
    } 
    else {
      return 0 + conta_nos_dois_filhos(no->esq) + conta_nos_dois_filhos(no->dir);
    }
}



/////////////// Exercício 4 /////////////////

// Função que é chamada na main em que o usuário passa como argumento somenete a raiz da árvore

Histograma* ocorrencia_caracteres(No *raiz){
    int tam_arvore = conta_nos(raiz);

    // tam_arvore é o tamanho máximo que o vetor histograma pode ter
    Histograma *histograma = (Histograma*) malloc(tam_arvore * sizeof(Histograma));

    for (int i = 0; i < tam_arvore; i++){
        histograma[i].ocorrencias = 0;
    }
    conta_caracteres(raiz, histograma, tam_arvore);

    return histograma;
}

// Função auxiliar que precisa de mais argumentos (pois é recursiva) e que não será chamada na main,
// será chamada pela função anterior, para que o código fique mais limpo na main

void conta_caracteres(No *no, Histograma *hist, int tam_hist){
    if (no == NULL){
      return;
    }

    // Percorrendo o vetor histograma para verificar se a informação do nó já está no histograma

    for (int i = 0; i < tam_hist; i++){
        // Se o caracter do nó já tiver no histograma, vou só incrementar no número de ocorrências e sair do for
        if (no->info == hist[i].caracter){
            hist[i].ocorrencias++;
            break;
        // Se eu tiver na última posição do vetor histograma e no->info não estiver lá, significa que esse caracter não
        // foi colocado ainda no vetor, e então será colocado na próxima posição vazia
        } else if (i == tam_hist-1 && no->info != hist[i].caracter){
            // Esse for irá encontrar a próxima posição vazia do vetor, ou seja, a posição onde o atributo ocorrencias
            // tem valor zero
            for (int j = 0; j < tam_hist; j++){
                if (hist[j].ocorrencias == 0){
                    hist[j].caracter = no->info;
                    hist[j].ocorrencias = 1;
                    break;
                }
            }
        }
    }
    conta_caracteres(no->esq, hist, tam_hist);
    conta_caracteres(no->dir, hist, tam_hist);
}