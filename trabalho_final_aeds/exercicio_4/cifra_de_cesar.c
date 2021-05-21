#include "cifra_de_cesar.h"

char *criptografa_senha(char *senha){
    char *new_senha = (char*) malloc(10 * sizeof(char));
    for (int i = 0; i < 6; i++){
        new_senha[i] = (char) (senha[i] + 3);
    }
    return new_senha;
}

char *descriptografa_senha(char *senha){
    char *new_senha = (char*) malloc(10 * sizeof(char));
    for (int i = 0; i < 6; i++){
        new_senha[i] = (char) (senha[i] - 3);
    }
    return new_senha;
}


Fila* insere_senha_na_lista(Fila *fila, char *senha){
    Lista *novo_no = (Lista*) malloc(sizeof(Lista));
    novo_no->senha = criptografa_senha(senha); 
    novo_no->prox = NULL;

    if (fila->inicio == NULL && fila->fim == NULL) {
        fila->inicio = novo_no;
        novo_no->id = 1;
    } 

    else if (fila->inicio != NULL && fila->fim == NULL){
        fila->inicio->prox = novo_no;
        fila->fim = novo_no;
        novo_no->id = 2;
    }
    else if (fila->fim != NULL){
        novo_no->id = fila->fim->id + 1;
        fila->fim->prox = novo_no;
        fila->fim = novo_no;
    }
    novo_no->prox = NULL;
    return fila;

}