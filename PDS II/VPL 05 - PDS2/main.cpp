// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_bst.hpp"
#include "BST.hpp"


using namespace std;


int main() {

  
    // NÃO ALTERE ESSA LINHA
    avaliacao_basica();


    BST tree;

    for(int i = 0; i < 10; i++){
        Aluno a;
        cin >> a.matricula;
        cin >> a.nome;
        tree.inserir_aluno(a);
    }

    tree.imprimir_arvore();

    return 0;
}