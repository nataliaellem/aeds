#include <stdio.h>
#include <stdlib.h>


void soma_vetores(int *vetor1, int *vetor2, int *vetor_resultado, int tamanho){
    for (int n = 0; n < tamanho; i++){
        vetor_resultado[n] = vetor1[n] + vetor2[n];
    }
}

int main(){
    int tamanho;
    scanf("%d", &tamanho);
    int *vetor1 = (int*) malloc(tamanho * sizeof(int));
    int *vetor1 = (int*) malloc(tamanho * sizeof(int));
    int *vetor2 = (int*) malloc(tamanho * sizeof(int));
    int *vetor_resultado = (int*) malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++){
        scanf("%d", &vetor1[i]);
    }

    for (int i = 0; i < tamanho; i++){
       scanf("%d", &vetor2[i]);
    }

    soma_vetores(vetor1, vetor2, vetor_resultado);
    for (int i = 0; i < tamanho; i++){
        printf("%d\n", vetor_resultado[i]);
    }

    free(vetor1);
    free(vetor2);
    free(vetor_resultado);
    return 0;
}