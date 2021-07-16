#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <string>
#include "Aluno.hpp"

using namespace std;


struct Node {
    Aluno aluno;
    Node *left;
    Node *right;

    void cria_node(Aluno aluno);
};

struct BST {

    Node *root;

    BST();
    
    void inserir_aluno_helper(Node* root, Aluno aluno);
    void inserir_aluno(Aluno aluno);
    void imprimir_arvore();
    Aluno* procurar_aluno(int matricula);

};

#endif