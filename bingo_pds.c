#include <stdio.h>
#include <stdlib.h>

typedef struct jogador {
    int id;
    int pontos;
    int **cartela;
} Jogador;

// ______________________________________//_______________________________________________//

Jogador* new_vetor_jogadores(int numero_jogadores, int tamanho_cartela) {

    // Configurando a função rand para gerar números aleatórios para as cartelas
    srand(123);

    // Alocando memória para o vetor de jogadores
    Jogador *jogadores = (Jogador*) malloc(numero_jogadores * sizeof(Jogador));
    for (int i = 0; i < numero_jogadores; i++) {
        int quantidade_numeros = tamanho_cartela * tamanho_cartela;
        // vetor que guarda os números já presentes na cartela
        int *vetor_auxiliar = (int *) malloc((quantidade_numeros) * sizeof(int));
        int posicao_vet_auxiliar = 0;
        
        jogadores[i].id = i+1;
        jogadores[i].pontos = 0;
        // Alocando memória para a matriz cartela que é um atributo da
        // estrutura Jogador
        jogadores[i].cartela = (int**) malloc(tamanho_cartela * sizeof(int*));
        for (int j = 0; j < tamanho_cartela; j++) {
            jogadores[i].cartela[j] = (int *) malloc(tamanho_cartela * sizeof(int));
            // Colocando números aleatórios nas cartelas
            for (int k = 0; k < tamanho_cartela; k++) {
                int aux = 1;
                while (aux) {
                    jogadores[i].cartela[j][k] = 1 + rand() % (10 * tamanho_cartela);
                    for (int l = 0; l < quantidade_numeros; l++) {
                        if (jogadores[i].cartela[j][k] == vetor_auxiliar[l]) {
                            break;
                        } else if (jogadores[i].cartela[j][k] != vetor_auxiliar[l] && l == quantidade_numeros - 1) {
                            vetor_auxiliar[posicao_vet_auxiliar] = jogadores[i].cartela[j][k];
                            posicao_vet_auxiliar++;
                            aux = 0;
                        }
                    }
                }
                
            }
        }
    }
    return jogadores;
}

// ______________________________________//_______________________________________________//

// Função que sorteia um número e coloca os pontos para os jogadores
Jogador* sortear_numero(Jogador *jogadores, int numero_jogadores, int tamanho_cartela, int *numeros_sorteados, int *bingo) {
    // Definindo o número a ser sorteado x
    int x;
    // Sorteando x aleatoriamente com a função rand
    x = 1 + rand() % (10 * tamanho_cartela);


    // Como o vetor de números sorteados foi alocado com a função calloc,
    // então todas as posições recebem o valor zero inicialmente
    // Desse modo, vou verificar qual a próxima posição que ainda não foi 
    // substituída por um número sorteado e colocar nessa posição o número sorteado x
    int aux = 0;
    while (numeros_sorteados[aux] != 0) {
        aux++;
    }
    // Imprimindo o número aleatório sorteado
    printf("%d° numero sorteado: %d\n", aux+1, x);
    
    numeros_sorteados[aux] = x;

    // Marcando o número sorteado nas cartelas
    // se o número sorteado estiver na cartela,
    // então o jogador receberá um ponto a mais
    for (int i = 0; i < numero_jogadores; i++) {
        for (int j = 0; j < tamanho_cartela; j++) {
            for (int k = 0; k < tamanho_cartela; k++) {
                if (jogadores[i].cartela[j][k] == x) {
                    jogadores[i].pontos = jogadores[i].pontos + 1;
                    if (jogadores[i].pontos == (tamanho_cartela * tamanho_cartela)) {
                        *bingo = 1;
                        printf("Jogador %d fez bingo!\n", jogadores[i].id);
                    }
                }
            }
        }
    }
    
    
    return jogadores;
}

// ______________________________________//_______________________________________________//
// Função que imprime todas as cartelas de todos os jogadores
void exibir_cartelas(Jogador *jogadores, int numero_jogadores, int tamanho_cartela) {
    for (int i = 0; i < numero_jogadores; i++) {
        printf("Cartela do jogador %d:\n", i+1);
        for (int j = 0; j < tamanho_cartela; j++) {
            for (int k = 0; k < tamanho_cartela; k++) {
                printf("%d\t", jogadores[i].cartela[j][k]);
            }
            printf("\n");
        }
    }
}
// ______________________________________//_______________________________________________//

void situacao_atual_jogo(Jogador *jogadores, int numero_jogadores, int *numeros_sorteados) {
    // Imprimindo números sorteados
    printf("Numeros sorteados:\n");
    for (int i = 0; numeros_sorteados[i] != 0; i++) {
        printf("%d, ", numeros_sorteados[i]);    
    }
    // Imprimindo pontos por jogador
    printf("\nPontos por jogador:\n");
    for (int j = 0; j < numero_jogadores; j++) {
        printf("Jogador %d: %d\n", jogadores[j].id, jogadores[j].pontos);
    }
}
// ______________________________________//_______________________________________________//
void relatorio_final(Jogador *jogadores, int numero_jogadores, int tamanho_cartela, int *numeros_sorteados) {
    printf("\nRelatorio final\n");

    printf("Numeros sorteados:\n");
    for (int i = 0; numeros_sorteados[i] != 0; i++) {
        printf("%d, ", numeros_sorteados[i]);    
    }
    printf("\n");
    // Chamando função que imprime as cartelas de cada jogador
    exibir_cartelas(jogadores, numero_jogadores, tamanho_cartela);

    printf("\nPontos por jogador:\n");
    for (int j = 0; j < numero_jogadores; j++) {
        printf("Jogador %d: %d\n", jogadores[j].id, jogadores[j].pontos);
    }
}

// ______________________________________//_______________________________________________//
void menu(){
    //printf("\n\t\tMENU\n");
    srand(123);

    // Escaneando o número de jogadores e a dimensão da cartela
    int numero_jogadores, tamanho_cartela;
    //printf("\nInforme o número de jogadores: ");
    scanf("%d", &numero_jogadores);
    while (numero_jogadores < 2 || numero_jogadores > 10){
        printf("\n");
        scanf("%d", &numero_jogadores);
    }
    printf("\n");
    scanf("%d", &tamanho_cartela);
    while (tamanho_cartela < 2 || tamanho_cartela > 9){
        //printf("\nInforme o tamanho da cartela: ");
        printf("\n");
        scanf("%d", &tamanho_cartela);
    }
    printf("\nJogadores: %d\n", numero_jogadores);
    printf("Tamanho da cartela: %d\n", tamanho_cartela);

    // Criando um vetor com os jogadores
    Jogador *jogadores = new_vetor_jogadores(numero_jogadores, tamanho_cartela);

    // Podem ser sorteados no máximo 99 números
    int *numeros_sorteados = (int *) calloc(100, sizeof(int));
    
    int k = 1;

    // Variável chamada 'bingo' que irá armazenar zero caso ninguém tenha feito bingo ainda
    // ou irá armazenar 1 caso alguém já tenha feito bingo
    // Essa variável bingo será alterada dentro da função sortear_numero caso alguém faça bingo 
    // para isso, será passado o endereço de memória dessa variável para dentro da função
    int bingo = 0;

    // Loop while que vai rodar até o usuário digitar 0
    // O loop tem um switch case com as opções que o usuário pode escolher
    while (k != 0){
        int valor;
        //printf("\t\tMENU\n\n");
        //printf("Digite uma opção:\n\t(1) sortear um novo número\n\t(2) Exibir as cartelas\n\t(3) Exibir a situação atual do jogo\n\t(0) sair do jogo e exibir relatório final\n");
        scanf("%d", &valor);
        switch (valor){
            case 1:
                jogadores = sortear_numero(jogadores, numero_jogadores, tamanho_cartela, numeros_sorteados, &bingo);
                // Caso alguém já tenha feito bingo o programa encerra e mostra o relatório final 
                if (bingo == 1) {
                    relatorio_final(jogadores, numero_jogadores, tamanho_cartela, numeros_sorteados);
                    return;
                }
                break;
            case 2:
                exibir_cartelas(jogadores, numero_jogadores, tamanho_cartela);
                break;
            case 3:
                situacao_atual_jogo(jogadores, numero_jogadores, numeros_sorteados);
                break;
            case 0:
                relatorio_final(jogadores, numero_jogadores, tamanho_cartela, numeros_sorteados);
                k = 0;
                break;
            default:
                break;
        }
    }
}


void main(){
    menu();
}