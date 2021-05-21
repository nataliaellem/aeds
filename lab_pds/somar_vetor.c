#include <stdio.h>
#include <stdlib.h>

// Programa que soma os elementos de um vetor de forma recursiva

void main(){
    int soma(int vetor[], int tamanho_vetor){
        if (tamanho_vetor == 0){
            return 0;
        }
        return vetor[tamanho_vetor - 1] + soma(vetor, tamanho_vetor-1);
    }

    int tam;
    scanf("%d", &tam);
    int *vetor = (int *) malloc(tam * sizeof(int));
    for (int i = 0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }
    printf("%d\n", soma(vetor, tam));
}