#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

// Nessa pasta estão inclusos alguns arquivos contendo expressões para testes para serem 
// executados com o comando "./exec.out < test1.txt" ou "./exec.out < test2.txt", etc.

char* le_expressao() {
    char *expressao = (char*) malloc(100 * sizeof(char));
    scanf("%s", expressao);
    return expressao;
}

int tem_precedencia(char char_arvore, char char_expr) {
    switch (char_expr) {
        case '*':
        case '/':
        case '+':
        case '-':
            if (char_arvore == '+' || char_arvore == '-')
                return 0;
            return 1;
        default:
            return 0;
    }
}

No* insere_char(No *no, char char_expr) {
    if (no == NULL){
        no = (No*) malloc(sizeof(No));
        no->info = char_expr;
        return no;
    } else {
        if (tem_precedencia(no->info, char_expr)) {
            No *novo_no = (No*) malloc(sizeof(No));
            novo_no->esq = no;
            novo_no->info = char_expr;
            return novo_no;
        } else {
            no->dir = insere_char(no->dir, char_expr);
            return no;
        }
    }
}

Arvore* monta_arvore(char* expressao) {
    Arvore *arvore = cria_arvore();

    for (size_t i = 0; expressao[i] != '\0'; i++) {
        arvore->raiz = insere_char(arvore->raiz, expressao[i]);
    }

    return arvore;
}

int main(){
    char *expressao = le_expressao();
    Arvore *arvore = monta_arvore(expressao);
    imprime_arvore(arvore->raiz);
    imprime_arvore_infixa(arvore->raiz);
    printf("\n");
    imprime_arvore_posordem(arvore->raiz);
    printf("\n");

    // Imprimindo as leituras das árvores em um arquivo
    // o arquivo será aberto no modo write
    FILE *file = fopen("saida_arvore.txt", "w");
    imprime_arvore_arquivo(file, arvore->raiz);
    fprintf(file, "\n\n===== Expressão infixa =====\n");
    imprime_arvore_infixa_arquivo(arvore->raiz, file);
    fprintf(file, "\n\n===== Expressão pós-fixa =====\n");
    imprime_arvore_posordem_arquivo(arvore->raiz, file);

    rewind(file);
    fclose(file);
    return 0;
}
