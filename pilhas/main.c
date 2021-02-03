#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"


//Função que usa pilha com lista encadeada
void parenteses_lista(){
    Pilha_lista *pilha = pilha_lista_cria();
    char caracter;
    printf("Informe a expressão matemática.\n");

    //O programa sai do while quando o usuário digita um ponto final '.'
    while(caracter != '.'){
        scanf("%c", &caracter);
        switch (caracter){
            case ')':
                if (pilha_lista_vazia(pilha)){
                    printf("Expressão mal formada.\n");
                    exit(1);
                }
                else {
                    pilha_lista_pop(pilha);
                }
                break;
            case '(':
                pilha_lista_push(pilha, caracter);
                break;
            default:
                continue;
        }
    }
    if (pilha_lista_vazia(pilha)){
        printf("Expressão bem formada.\n");
    } else {
        printf("Expressão mal formada.\n");
    }

}


//Função que usa pilhas com vetores de tamanho máximo 500
void parenteses_vetor(){
    Pilha_vetor *pilha = pilha_vetor_cria();
    char caracter;
    printf("Informe a expressão matemática.\n");
    while(caracter != '.'){
        scanf("%c", &caracter);
        switch (caracter){
            case ')':
                if (pilha_vetor_vazia(pilha)){
                    printf("Expressão mal formada.\n");
                    exit(1);
                }
                else {
                    pilha_vetor_pop(pilha);
                }
                break;
            case '(':
                pilha_vetor_push(pilha, caracter);
                break;
            default:
                continue;
        }
    }
    if (pilha_vetor_vazia(pilha)){
        printf("Expressão bem formada.\n");
    } else {
        printf("Expressão mal formada.\n");
    }

}


int main(){

    parenteses_lista();
    getchar();
    parenteses_vetor();

    return 0;
}