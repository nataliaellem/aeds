#include <stdio.h>
#include <stdlib.h>

    typedef struct {
        char *nome;
        char *sobrenome;
        char *data_nascimento;
        char *cpf;
        char *data_admissao;
        float salario;
    } Dados;

void main(){
    int numero_empregados;
    printf("Informe o número de empregados: ");
    scanf("%d", &numero_empregados);
    Dados *vetor_empregados = (Dados*) malloc(numero_empregados * sizeof(Dados));
    for(int i = 0; i < numero_empregados; i++){
        vetor_empregados[i].nome = (char*) malloc(20* sizeof(char));
        vetor_empregados[i].sobrenome = (char*) malloc(30* sizeof(char));
        vetor_empregados[i].data_nascimento = (char*) malloc(20* sizeof(char));
        vetor_empregados[i].data_admissao = (char*) malloc(20* sizeof(char));
        vetor_empregados[i].cpf = (char*) malloc(20* sizeof(char));
        
    }
}