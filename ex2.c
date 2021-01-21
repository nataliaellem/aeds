#include <stdio.h>
#include <stdlib.h>

void main(){
    int n;
    float maior = 0.0, menor = 100.0;
    printf("Informe o número de alunos da turma: ");
    scanf("%d", &n);
    printf("\n");
    float *notas = (float*) malloc(n * sizeof(float));
    int i = 0;
    while (i < n){
        printf("Digite a nota do %dº aluno: ", i+1);
        scanf("%f", &notas[i]);
        if (notas[i] < 0 || notas[i] > 100){
            printf("Nota inválida, tente novamente.\n");
            continue;        
        } 
        printf("\n");
        if (notas[i] > maior){
            maior = notas[i];
        }
        if (notas[i] < menor){
            menor = notas[i];
        }
        i++;
    }
    printf("A maior nota é %.2f.\nA menor nota é %.2f.\n", maior, menor);
}