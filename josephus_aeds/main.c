#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"

int main(){

    //Função josephus que retorna o nome do vencedor

    char* josephus(Lista *inicio_lista, int n, int passos){
        int conta_blocos_retirados = 1;

        char *vencedor = (char*) malloc(30* sizeof(char));
        Lista *bloco_a_retirar;
        Lista *auxiliar = inicio_lista;
        while(conta_blocos_retirados <= n-1){
            for (int i = 1; i <= passos; i++){
                if (i == passos){
                    inicio_lista = lista_circular_retira(inicio_lista, bloco_a_retirar);
                    conta_blocos_retirados++;
                    auxiliar = bloco_a_retirar->prox;
                    continue;
                }
                bloco_a_retirar = auxiliar->prox;

            }

        }
        strcpy(vencedor, inicio_lista->info);
        printf("O vencedor é %s\n", vencedor);
        return vencedor;
    }

    //Criando uma lista e inserindo dados
    Lista *lista = cria_lista();
    lista = lista_circular_insere(lista, "Marco Aurelio");
    lista = lista_circular_insere(lista, "Julio Cezar");
    lista = lista_circular_insere(lista, "Otavio Augusto");
    lista = lista_circular_insere(lista, "Comodo");
    lista = lista_circular_insere(lista, "Vespasiano");
    lista = lista_circular_insere(lista, "Nero");
    //A lista de nomes vai ser impressa na ordem contrária na qual foram inseridos os elementos
    imprime_lista(lista);

    //Chamando a função josephus com a lista duplamente encadeada e 
    //circular que foi criada acima
    //são 6 elementos na lista e pula de dois em dois elementos
    josephus(lista, 6, 2);

    //Perguntando as informações aos usuários
    int n, p;
    Lista *l;
    printf("Informe o número de pessoas da lista: ");
    scanf("%d", &n);
    printf("\nInforme o número de passos: ");
    scanf("%d", &p);
    printf("\nInforme os nomes das pessoas:\n");
    for (int i = 0; i < n; i++){
        char nome[50];
        scanf("%s", nome);
        l = lista_circular_insere(l, nome);
    }
    printf("\n");
    josephus(l, n, p);
    return 0;
}