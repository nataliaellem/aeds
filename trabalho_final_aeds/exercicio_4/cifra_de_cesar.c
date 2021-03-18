#include "cifra_de_cesar.h"

char *criptografa_senha(char senha[6]){
    char senha_crip[6];
    for (int i = 0; i < 6; i++){
        senha_crip[i] = (char) (senha[i] + 3);
    }
    return senha_crip;
}

char *descriptografa_senha(char senha_crip[6]){
    char senha[6];
    for (int i = 0; i < 6; i++){
        senha[i] = (char) (senha_crip[i] - 3);
    }
    return senha;
}


Fila* insere_senha_na_lista(Fila *fila, char *senha){
    Lista *novo_no = (Lista*) malloc(sizeof(Lista));
    novo_no->senha = criptografa_senha(senha); 
    novo_no->prox = NULL;

    if (fila->inicio == NULL && fila->fim == NULL) {
        fila->inicio = novo_no;
    } 

    else if (fila->inicio != NULL && fila->fim == NULL){
        fila->inicio->prox = novo_no;
        fila->fim = novo_no;
    }
    else if (fila->fim != NULL){
        fila->fim->prox = novo_no;
        fila->fim = novo_no;
    }
    novo_no->prox = NULL;

}