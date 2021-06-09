#ifndef AVALIACAO_H
#define AVALIACAO_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

#include "BST.hpp"
#include "Aluno.hpp"

using namespace std;

void avaliacao_basica() {

    BST bst;

    Aluno a3;
    a3.nome = "Joao";
    a3.matricula = 123456790;
    bst.inserir_aluno(a3);

    Aluno a2;
    a2.nome = "Maria";
    a2.matricula = 123456788;
    bst.inserir_aluno(a2);

    Aluno a1;
    a1.nome = "Douglas";
    a1.matricula = 123456789;
    bst.inserir_aluno(a1);

    cout << "BST" << endl;
    bst.imprimir_arvore();

    int IDs[] = {123456780, 123456789};

    for (int i = 0; i < 2; i++) {
        Aluno* aa = bst.procurar_aluno(IDs[i]);
    
        if (aa == nullptr) {
            cout << "NE" << endl; 
        } else {
            cout << "E: "; 
            aa->imprimir_dados();
        }
    }

    cout << "---------------" << endl;
    
}

#endif