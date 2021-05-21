#include <stdio.h>
#include <stdlib.h>

int* le_vetor(int *vetor, int n){
    for (int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    return vetor;
}

int main(){

    int n;
    scanf("%d", &n);
    int *vetor = (int*) malloc(n * sizeof(int));
    vetor = le_vetor(vetor, n);
    for (int i = 0; i < n; i++){
        printf("%d\n", vetor[i]);
    }
    free(vetor);
    return 0;
}