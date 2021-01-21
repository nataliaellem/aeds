#include <stdio.h>
#include <math.h>

void main(){
    //Vetor com os números inteiros
    int lista_numeros[5] = {0, 1, 2, 3, 4}, quadrado[5];
    for (int i = 0; i < 5; i++){
        quadrado[i] = pow(lista_numeros[i], 2);
        printf("Número: %d -> Quadrado: %d\n", lista_numeros[i], quadrado[i]);
    }

}