#include <stdio.h>
#include <stdlib.h>



int main(){

    int linhas, colunas;
    scanf("%d", &linhas);
    scanf("%d", &colunas);
    int **matriz = (int**) malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++){
        matriz[i] = (int*) malloc(colunas * sizeof(int));
        for (int j = 0; j < colunas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("%d  ", matriz[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < linhas; i++){

        free (matriz[i]);
    } 

    free (matriz); 
    return 0;
}  