#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_encadeada.h"
#include "lista_circular.h"
#include "pilha.h"
#include "estacionamento.h"

// Função para o exercício 4

void parenteses_colchetes(){
    Pilha *pilha = pilha_cria();
    char caracter;
    printf("Informe a expressão matemática. (digite '.' para sair do loop)\n");

    //O programa sai do while quando o usuário digita um ponto final '.'
    while(caracter != '.'){
        scanf("%c", &caracter);
        switch (caracter){
            case ')':
                if (pilha_vazia(pilha)){
                    printf("Expressão mal formada.\n");
                    return;
                }
                else {
                    pilha_pop(pilha);
                }
                break;
            case '(':
                pilha_push(pilha, caracter);
                break;

            case '}':
                if (pilha_vazia(pilha)){
                    printf("Expressão mal formada.\n");
                    return;
                }
                else {
                    pilha_pop(pilha);
                }
                break;
            case '{':
                pilha_push(pilha, caracter);
                break;
            default:
                continue;
        }
    }
    if (pilha_vazia(pilha)){
        printf("Expressão bem formada.\n");
    } else {
        pilha_libera(pilha);
        printf("Expressão mal formada.\n");
    }

}


// Funções para o exercício 5

char *limpa_frase(char *frase){
    int tam = strlen(frase), cont = 0;

    // Deixando tudo minúsculo
    for(int i = 0; i < tam; i++){
        frase[i] = tolower(frase[i]);
    }

    char *nova_frase = (char*) malloc(tam * sizeof(char));
    for(int i = 0; i < tam; i++){
        if (frase[i] != ' ' && frase[i] != ',' && frase[i] != '!' && frase[i] != '.'){
            nova_frase[cont] = frase[i];
            cont++;
        }
    }
    nova_frase = (char*) realloc(nova_frase, (cont) * sizeof(char));
    return nova_frase;
}

int verifica_palindromo(char *f){
    char frase[50];
    strcpy(frase, limpa_frase(f));
    Pilha *pilha = pilha_cria();
    for (size_t i = 0; i < strlen(frase); i++){
        pilha_push(pilha, frase[i]);
    }
    for (size_t j = 0; j < strlen(frase); j++){
        char pop = pilha_pop(pilha);
        if (frase[j] != pop){
            printf("Não é palíndromo.\n");
            return 0;
        }
    }
    printf("É palíndromo.\n");
    pilha_libera(pilha);
    return 1;
}


// Funções para o exercício 6

int TTT(int x[], int n){
    if (n == 0)
        return 0;
    if (x[n] > 0)
        return x[n] + TTT(x, n - 1);
    else
        return TTT(x, n - 1);
}

int TTT_iterativa(int x[], int n){
    Pilha *p = pilha_cria();

    for (int i = n; i >= 0; i--) {
        if (n == 0) {
            pilha_push_int(p, 0);
        }
        if (x[i] > 0) {
            pilha_push_int(p, pilha_pop_int(p) + x[i]);
        }
    }
    return pilha_pop_int(p);
}


int main(){

    // Testando funções do exercício 1

    printf("\n===== Exercício 1 =====\n");
    Lista *lista = cria_lista();
    lista = insere_lista(lista, 10.0);
    lista = insere_lista(lista, 6.0);
    lista = insere_lista(lista, 8);

    lista_retira_recursiva(lista, 6.0);
    imprime_lista_recursiva(lista, lista);

    Lista *l2 = cria_lista();
    l2 = insere_lista(l2, 15.0);
    l2 = insere_lista(l2, 8.0);
    l2 = insere_lista(l2, 10.0);
    
    imprime_lista_recursiva(l2, l2);

    ///////////////////////////////////////////////////////////////

    // Testando função do exercício 2

    printf("\n===== Exercício 2 =====\n");
    Lista *intercalacao = lista_intercala(lista, l2);
    imprime_lista_recursiva(intercalacao, intercalacao);
    lista_libera_recursiva(intercalacao);
    lista_libera_recursiva(l2);
    lista_libera_recursiva(lista);

    ///////////////////////////////////////////////////////////////

    // Testando funções de lista dupla e circular do exercício 3
    printf("\n===== Exercício 3 =====\n");
    Lista_c *lc = cria_lista_circular();

    lc = lista_circular_insere(lc, 5);    
    lc = lista_circular_insere(lc, 15);    
    imprime_lista_circular(lc);    
    lista_circular_libera(lc);
    ///////////////////////////////////////////////////////////////

    // Testando a função do exercício 4
    printf("\n===== Exercício 4 =====\n");

    parenteses_colchetes();
    // usando o fpurge pois no próximo scanf estava dando problema para ler a string frase
    __fpurge(stdin);

    ///////////////////////////////////////////////////////////////

    // Testando a função do exercício 5
    printf("\n===== Exercício 5 =====\n");
    printf("Digite uma frase.\n");
    char frase[50];
    scanf("%[^\n]", frase);
    verifica_palindromo(frase);
    ///////////////////////////////////////////////////////////////
    
    // Testando a função do exercício 6 
    printf("\n===== Exercício 6 =====\n");
    int n = 10;
    int x[15] = {
        0, 1, -20, 2, 3,
        4, -3, -6, 5, 6,
        7, 8, 9, 0, 0
    };
    printf("%d\n", TTT(x, n));
    printf("%d\n", TTT_iterativa(x, n));
    ///////////////////////////////////////////////////////////////

    // Exercício 7

    printf("\n===== Exercício 7 =====\n");

    Fila *fila = cria_fila();
    int k = 1;
    char *nome_arquivo = (char*) malloc(100 * sizeof(char));
    printf("Digite o nome do arquivo que será armazenado os estados do estacionamento.\n");
    scanf("%s", nome_arquivo);
    __fpurge(stdin);

    // Loop que escaneia do usuário as placas a serem colocadas no estacionamento e a idade dos motoristas
    while(k){
        char placa[10];
        printf("Para sair desse loop digite 's', para imprimir o estado do estacionamento digite 'i' e para retirar um carro da fila digite 'r.\n");
        printf("Ou informe a placa do novo carro que chegou ao estacionamento: ");
        scanf("%s", placa);
        __fpurge(stdin);
        int idade;
        
        if (strcmp(placa, "s") == 0){
            k = 0;
            break;
        }
        else if (strcmp(placa, "i") == 0){
            printf("Estado do estacionamento:\n");
            imprime_fila(fila);
        }
        else if (strcmp(placa, "r") == 0){
            char carro_retirado[50];
            strcpy(carro_retirado, retira_da_fila(fila));
            printf("Carro retirado: %s\n", carro_retirado);
            arquivo_estacionamento(fila, nome_arquivo);
        }
        else {
            printf("\nInforme a idade do motorista\n");
            scanf("%d", &idade);
            insere_fila(fila, placa, idade);
            printf("Estado do estacionamento:\n");
            imprime_fila(fila);
            arquivo_estacionamento(fila, nome_arquivo);
        }
    }

   libera_fila(fila);

    return 0;
}