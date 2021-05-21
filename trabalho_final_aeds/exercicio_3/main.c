#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

// O código contém alguns comandos para o linux, como "system(clear)" e "__fpurge(stdin)"


// Função auxiliar para ler a descrição do processo

char* le_info(){
    __fpurge(stdin); // para limpar o buffer do teclado no linux
    int i = 0;
    char *info = (char*) malloc(2 * sizeof(char));
    char c;
    do {
        scanf("%c", &c);
        if (c != '\n'){
            info[i] = c;
            i++;
            info = (char*) realloc(info, (i+2) * sizeof(char));

        }
    } while (c != '\n');

    info[i+1] = '\0';
  
  return info;
}


Fila* inclui_processo(Fila* fila){
    system("clear");
    printf("===== Incluir novo processo =====\n\n");
    int id;
    printf("Informe a descrição do processo: ");
    char *des = le_info();
    printf("\nInforme o número identificador: ");
    scanf("%d", &id);
    printf("\n");
    insere_fila(fila, des, id);
    printf("Processo adicionado à fila: ");
    printf("%s, %d\n", des, id);
    return fila;
}


Fila* retira_processo(Fila *fila){
    system("clear");
    printf("===== Retirar da fila o processo com maior tempo =====\n\n");
    if (fila->inicio == NULL){
        printf("Não há processo na fila.\n");
        return fila;
    }
    int id;
    char *des = retira_da_fila(fila, &id);
    printf("Processo retirado.\n");
    printf("Informações do processo retirado: id %d, descrição: %s\n", id, des);
    return fila;
}



void conteudo_fila(Fila *fila){
    system("clear");
    printf("===== Conteúdo da fila de processos =====\n\n");
    Processo *aux = fila->inicio;
    if (aux == NULL){
        printf("Não há processo na fila.\n");
        return;
    }
    int c = 1;
    while(aux != NULL){
        printf("\t%d°) Descrição: %s, identificador: %d\n", c, aux->descricao, aux->id);
        aux = aux->prox;
        c++;
    }
    printf("\n");
}

void menu(){
    // Criando uma fila; 
    Fila *fila = cria_fila();

    // Interação com o usuário
    int n = 1;
    while(n){
        __fpurge(stdin); // para limpar o buffer do teclado no linux
        system("clear");
        printf("===================================== Menu =====================================\n");
        printf("Escolha uma das opções abaixo:\n\n");
        printf("\t(a) Incluir novo processo na fila de processo;\n");
        printf("\t(b) Retirar da fila o processo com o maior tempo de espera\n");
        printf("\t(c) Imprimir o conteúdo da fila de processos atualmente;\n");
        printf("\t(s) Sair do menu;\n\n");
        char opcao;
        printf("Digite a letra referente à opção desejada: ");
        scanf("%c", &opcao);
        printf("\n");

        switch (opcao) {

            case 'a':
                fila = inclui_processo(fila);
                __fpurge(stdin);
                char a;
                printf("\n\nPressione qualquer tecla para voltar ao menu.\n");
                scanf("%c", &a);
                printf("a: %c\n", a);
                break;
            case 'b':
                retira_processo(fila);
                __fpurge(stdin);
                char b;
                printf("\n\nPressione qualquer tecla para voltar ao menu.\n");
                scanf("%c", &b);
                break;
            case 'c':
                conteudo_fila(fila);
                __fpurge(stdin);
                char c;
                printf("\n\nPressione qualquer tecla para voltar ao menu.\n");
                scanf("%c", &c);
                break;
            case 's':
                printf("\n\nEncerrando...\n");
                n = 0;
                break;
            default:
                printf("Opção inválida, tente novamente.\n");
                __fpurge(stdin);
                char q;
                printf("\n\nPressione qualquer tecla para voltar ao menu.\n");
                scanf("%c", &q);
                break;

        }
    }
    libera_fila(fila);
}



int main(){
    menu();
    return 0;
}