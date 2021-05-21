#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cifra_de_cesar.h"
#include "fila.h"


// O código contém alguns comandos para o linux, como "system(clear)" e "__fpurge(stdin)"



Fila* add_senha(Fila *fila){
    system("clear");
    printf("======= Adicionar nova senha à lista =======\n\n");
    char *senha = (char*) malloc(10 * sizeof(char));
    printf("Digite a senha: ");
    scanf("%s", senha);
    printf("\n");
    fila = insere_senha_na_lista(fila, senha);
    printf("Senha adicionada.\nSenha criptografada: %s\n", criptografa_senha(senha));
    return fila;
}


void descrip_senha(Fila *fila){
    system("clear");
    printf("======== Descriptografar senha ========\n\n");
    printf("Informe o id da senha que será descriptografada: ");
    int id;
    scanf("%d", &id);
    printf("\n");
    Lista *aux;
    for(aux = fila->inicio; aux != NULL; aux = aux->prox){
        if (aux->id == id){
            printf("\nSenha criptografada: %s\n", aux->senha);
            char *s = descriptografa_senha(aux->senha);
            printf("Senha descriptografada: %s\n", s);
            return;
        }
    }
    printf("Não existe senha com o id informado.\n");
}


int main(){

    // Criando uma fila; 
    Fila *fila = cria_fila();


    // Interação com o usuário
    int k = 1;
    while(k){
        __fpurge(stdin); // para limpar o buffer do teclado no linux
        system("clear");
        printf("===================================== Menu =====================================\n");
        printf("Escolha uma das opções abaixo:\n\n");
        printf("\t(a) Adicionar nova senha à lista;\n");
        printf("\t(b) Listar senhas armazenadas (criptografadas)\n");
        printf("\t(c) Descriptografar uma senha;\n");
        printf("\t(s) Sair do menu;\n\n");
        char opcao;
        printf("Digite a letra referente à opção desejada: ");
        scanf("%c", &opcao);
        printf("\n");

        switch (opcao) {

            case 'a':
                fila = add_senha(fila);
                __fpurge(stdin);
                char a;
                printf("\n\nPressione qualquer tecla para voltar ao menu.\n");
                scanf("%c", &a);
                printf("a: %c\n", a);
                break;
            case 'b':
                system("clear");
                printf("======= Senhas criptografadas armazenadas =======\n\n");
                imprime_fila(fila);
                __fpurge(stdin);
                char b;
                printf("\n\nPressione qualquer tecla para voltar ao menu.\n");
                scanf("%c", &b);
                break;
            case 'c':
                descrip_senha(fila);
                __fpurge(stdin);
                char c;
                printf("\n\nPressione qualquer tecla para voltar ao menu.\n");
                scanf("%c", &c);
                break;
            case 's':
                printf("\n\nEncerrando...\n");
                k = 0;
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

    return 0;
}