#define N 500

typedef struct pilha_vetor {
    int ultima_posicao;
    char vetor[N];
} Pilha_vetor;


typedef struct lista {
    char info;
    struct lista *prox;
} Lista;


typedef struct pilha_lista {
    Lista *topo;
} Pilha_lista;


//Pilhas com vetor

Pilha_vetor *pilha_vetor_cria();

void pilha_vetor_push(Pilha_vetor *pilha, char valor);

char pilha_vetor_pop(Pilha_vetor *pilha);

int pilha_vetor_vazia(Pilha_vetor *pilha);

void pilha_vetor_libera(Pilha_vetor *pilha);

void pilha_vetor_imprime(Pilha_vetor *pilha);


//Pilhas com listas

Pilha_lista *pilha_lista_cria();

void pilha_lista_push(Pilha_lista *pilha, char valor);

char pilha_lista_pop(Pilha_lista *pilha);

int pilha_lista_vazia(Pilha_lista *pilha);

void pilha_lista_libera(Pilha_lista *pilha);

void pilha_lista_imprime(Pilha_lista *pilha);