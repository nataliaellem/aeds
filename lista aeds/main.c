#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main(){
    Lista *lista = cria_lista();
    lista = insere_lista(lista, 10.0);
    lista = insere_lista(lista, 6.0);
    lista = insere_lista(lista, 7.0);
    lista = insere_lista(lista, 8);

    // Função retira não está funcionando
    lista_retira_recursiva(lista, 6.0);
    imprime_lista_recursiva(lista);

    
    return 0;
}