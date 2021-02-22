#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estacionamento.h"


// Função que retira os carros do início da fila e 
// caso o carro não seja o carro a ser retirado do estacionamento,
// o carro é realocado no fim da fila, mas caso seja o carro certo,
// o carro não é realocado no fim da fila e o programa para.

void retira_carro(Fila *fila, char *placa, Carro *primeiro_fila){

    char *placa_retirada = (char*) malloc(10 * sizeof(char));
    strcpy(placa_retirada, retira_da_fila(fila));

    if (strcmp(placa_retirada, placa) == 0){
        printf("Estado do estacionamento: \n");
        imprime_fila(fila);
        return;
    }
    insere_fila(fila, placa_retirada);

    // Condicional que verifica se o primeiro_fila é o primeiro carro
    // da fila atual, pois se for, significa que já foi percorrida
    // toda a fila e a placa não foi encontrada
    if (primeiro_fila == fila->inicio){
        printf("Placa inválida.\n");
        return;
    }
    retira_carro(fila, placa, primeiro_fila);
}

int main(){
    Fila *fila = cria_fila();
    int k = 1;

    // Loop que escaneia do usuário as placas a serem colocadas no estacionamento
    while(k){
        char placa[10];
        printf("Para sair desse loop digite 's', ou para imprimir o estado do estacionamento digite 'i'.\n");
        printf("Ou informe a placa do novo carro que chegou ao estacionamento: ");
        scanf("%s", placa);
        printf("\n");
        if (strcmp(placa, "s") == 0){
            k = 0;
            break;
        }
        else if (strcmp(placa, "i") == 0){
            printf("Estado do estacionamento:\n");
            imprime_fila(fila);
        }
        else {
            insere_fila(fila, placa);
            printf("Estado do estacionamento:\n");
            imprime_fila(fila);

        }
    }

    // Segundo loop que escaneia as placas a serem retiradas da fila
    k = 1;
    while(k){
        printf("Para sair desse loop digite 's' ou para imprimir o estado do estacionamento digite 'i'.\n");
        printf("Ou informe o carro a ser retirado: ");
        char placa[10];
        scanf("%s", placa);
        printf("\n");

        if (strcmp(placa, "s") == 0){
            libera_fila(fila);
            k = 0;
            break;
        }
        else if (strcmp(placa, "i") == 0){
            printf("Estado do estacionamento:\n");
            imprime_fila(fila);
        }
        else {
            retira_carro(fila, placa, fila->inicio);
    
        }
    }

    return 0;
}