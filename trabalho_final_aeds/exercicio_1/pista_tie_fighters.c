#include "pista_tie_fighters.h"

// Função auxiliar para ler o nome do piloto, pois scanf("%s") não lê corretamente quando o nome tem mais de uma palavra

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

// Funções para o exercício 1 

Fila* adicionar_tie_fighters(Fila* fila){
    system("clear");
    printf("********* Adicionar uma Tie Fighters à lista de espera *********\n\n");
    int identificador;
    printf("Informe o nome do piloto: ");
    char *nome_piloto = le_info();
    printf("\nInforme o número identificador: ");
    scanf("%d", &identificador);
    printf("\n");
    insere_fila(fila, nome_piloto, identificador);
    printf("Tie Fighter adicionada à fila: ");
    printf("%s, %d\n", nome_piloto, identificador);
    return fila;
}


Fila* autorizar_decolagem(Fila *fila){
    system("clear");
    printf("********* Autorizar a decolagem da primeira Tie Fighters da fila *********\n\n");
    if (fila->inicio == NULL){
        printf("Não há Tie Fighters para decolagem.\n");
        return fila;
    }
    int id;
    char *nome_piloto = retira_da_fila(fila, &id);
    printf("Decolagem autorizada.\n");
    printf("Informações da Tie Fighter que decolou: id %d, nome do piloto: %s\n", id, nome_piloto);
    return fila;
}


int tie_fighters_aguardando(Fila *fila){
    system("clear");
    printf("********* Listar o número de Tie Fighters aguardando na fila de decolagem *********\n\n");
    No *auxiliar = fila->inicio;
    if (auxiliar == NULL){
        printf("Não há Tie Fighter aguardando na fila.\n");
        return 0;
    }
    int contador = 0;
    printf("Tie Fighters aguardando (por identificadores): ");
    while(auxiliar != NULL){
        if (auxiliar->prox == NULL){
            printf("%d\n", auxiliar->id);
            contador++;
            auxiliar = auxiliar->prox;
            break;
        }
        printf("%d, ", auxiliar->id);
        contador++;
        auxiliar = auxiliar->prox;
    }
    printf("Existem %d Tie Fighters aguardando.\n", contador);
    return contador;
}


void lista_informacoes(Fila *fila){
    system("clear");
    printf("********** Listar todas as informações das Tie Fighters na fila de espera *********\n\n");
    No *aux = fila->inicio;
    if (aux == NULL){
        printf("Não há Tie Fighters na lista de espera.\n");
        return;
    }
    printf("Informações das Tie Fighters na fila de espera:\n");
    int c = 1;
    while(aux != NULL){
        printf("\t\t%d°) Nome do piloto: %s, identificador: %d\n", c, aux->nome_piloto, aux->id);
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
        printf("================================================================================\n");
        printf("===================================== Menu =====================================\n");
        printf("================================================================================\n\n");
        printf("Escolha uma das opções abaixo:\n\n");
        printf("\t(a) Adicionar uma Tie Fighters à lista de espera;\n");
        printf("\t(b) Autorizar a decolagem da primeira Tie Fighters da fila\n");
        printf("\t(c) Listar o número de Tie Fighters aguardando na fila de decolagem;\n");
        printf("\t(d) Listar todas as informações das Tie Fighters na fila de espera;\n");
        printf("\t(s) Sair do menu;\n\n");
        char opcao;
        printf("Digite a letra referente à opção desejada: ");
        scanf("%c", &opcao);
        printf("\n");

        switch (opcao) {

            case 'a':
                fila = adicionar_tie_fighters(fila);
                __fpurge(stdin);
                char a;
                printf("\n\nPressione qualquer tecla para voltar ao menu.\n");
                scanf("%c", &a);
                printf("a: %c\n", a);
                break;
            case 'b':
                autorizar_decolagem(fila);
                __fpurge(stdin);
                char b;
                printf("\n\nPressione qualquer tecla para voltar ao menu.\n");
                scanf("%c", &b);
                break;
            case 'c':
                tie_fighters_aguardando(fila);
                __fpurge(stdin);
                char c;
                printf("\n\nPressione qualquer tecla para voltar ao menu.\n");
                scanf("%c", &c);
                break;
            case 'd':
                lista_informacoes(fila);
                __fpurge(stdin);
                char d;
                printf("\n\nPressione qualquer tecla para voltar ao menu.\n");
                scanf("%c", &d);
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
