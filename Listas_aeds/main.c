#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"

int main(){
    //Declarando duas listas que terão os mesmos valores
    Lista *lista = cria_lista();
    Lista *lista2 = cria_lista();

    //inserindo 10 números nas listas
    for (int i = 1; i <= 10; i++){
        lista = lista_insere(lista, i);
        lista2 = lista_insere(lista2, i);
    }

    //Imprimindo a primeira lista:
    printf("Primeira lista: \n");
    imprime_lista(lista);
    //Imprimindo a segunda lista
    printf("\nSegunda lista: \n");
    imprime_lista(lista2);

    //Chamando a função que compara as listas e imprimindo se são iguais ou diferentes
    int compara = compara_listas(lista, lista2);
    if (compara == 1){
        printf("As listas são iguais.\n");
    } else {
        printf("As listas são diferentes\n");
    }

    printf("\nAgora o teste será feito com outras duas listas que têm valores diferentes.\n");

    //Declarando duas listas com valores diferentes
    Lista *list = cria_lista();
    Lista *list2 = cria_lista();

    for (int i = 1; i <= 10; i++){
        list = lista_insere(list, i);
        list2 = lista_insere(list2, 10-i);
    }

    //Imprimindo os valores das listas

    //Imprimindo a primeira lista:
    printf("Primeira lista: \n");
    imprime_lista(list);
    //Imprimindo a segunda lista
    printf("\nSegunda lista: \n");
    imprime_lista(list2);

    //Chamando a função que compara as listas e imprimindo se são iguais ou diferentes
    int compara2 = compara_listas(list, list2);
    if (compara2 == 1){
        printf("As listas são iguais.\n");
    } else {
        printf("As listas são diferentes\n");
    }

    // Liberando as listas
    lista_libera(lista);
    lista_libera(lista2);
    lista_libera(list);
    lista_libera(list2);
    
    return 0;
}