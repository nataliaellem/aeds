#include "estacionamento.h"

Fila* cria_fila(){
    Fila *nova_fila = (Fila*) malloc(sizeof(Fila));
    nova_fila->inicio = NULL;
    nova_fila->fim = NULL;
    return nova_fila;
}


void insere_fila(Fila *fila, char *info, int idade_motorista){
    Carro *novo_carro = (Carro*) malloc(sizeof(Carro));
    strcpy(novo_carro->placa, info);
    novo_carro->idade_motorista = idade_motorista;
    novo_carro->prox = NULL;

    Carro *ant = fila->inicio;
    if (ant == NULL){
        fila->inicio = novo_carro;
        novo_carro->prox = NULL;
    }
    else if (novo_carro->idade_motorista >= 60 && ant != NULL) {
        if (novo_carro->idade_motorista > ant->idade_motorista) {
            fila->inicio = novo_carro;
            novo_carro->prox = ant;
        } else {
            for (Carro *aux = ant->prox; aux != NULL; aux = aux->prox) {
                if (novo_carro->idade_motorista > aux->idade_motorista) {
                    novo_carro->prox = aux;
                    ant->prox = novo_carro;
                }
                ant = aux;
            }
        }
    } else if (fila->fim != NULL){
        fila->fim->prox = novo_carro;
        fila->fim = novo_carro;
    } else if (fila->fim == NULL){
        fila->inicio->prox = novo_carro;
        fila->fim = novo_carro;
    }
}


char* retira_da_fila(Fila *fila){
    if (fila->inicio == NULL){
        return NULL;
    }
    Carro *auxiliar = fila->inicio;
    char *info = (char*) malloc(10 * sizeof(char));
    strcpy(info, auxiliar->placa);
    fila->inicio = auxiliar->prox;
    if (fila->inicio == NULL){
        fila->fim = NULL;
    }
    free(auxiliar);
    return (info);
}

void imprime_fila(Fila *fila){
    Carro *aux;
    printf("\n");
    for(aux = fila->inicio; aux != NULL; aux = aux->prox){
        printf("%s\t", aux->placa);
    }
    printf("\n\n");
}

void libera_fila(Fila *fila){
    Carro *c = fila->inicio;
    while(c != NULL){
        Carro *aux = c->prox;
        free(c);
        c = aux;
    }
    free(fila);
}


void arquivo_estacionamento(Fila *fila, char *nome_arquivo){
    FILE *arquivo = fopen(nome_arquivo, "w");
    Carro *aux;
    for (aux = fila->inicio; aux != NULL; aux = aux->prox){
        fprintf(arquivo, "Placa: %s, idade: %d\n", aux->placa, aux->idade_motorista);
    }
    fclose(arquivo);
}