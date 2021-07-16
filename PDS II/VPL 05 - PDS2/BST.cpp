#include "BST.hpp"



Node* cria_node(Aluno a){

    Node *aux = new Node;
    aux->aluno.set_nome(a.get_nome());
    aux->aluno.set_matricula(a.get_matricula());
    aux->left = nullptr;
    aux->right = nullptr;
    return aux;
}

BST::BST(){
    this->root = nullptr;
}

void BST::inserir_aluno_helper(Node *node, Aluno a){
    if (a.get_matricula() < node->aluno.get_matricula()) {
        if (node->left == nullptr) {
            node->left = cria_node(a);
        } else {
            inserir_aluno_helper(node->left, a);
        }
    } else if (a.get_matricula() > node->aluno.get_matricula()) {
        if (node->right == nullptr) {
            node->right = cria_node(a);
        } else {
            inserir_aluno_helper(node->right, a);
        }
    }
}


void BST::inserir_aluno(Aluno aluno){

    if (this->root != nullptr){
        inserir_aluno_helper(this->root, aluno);
    }
    else {
        this->root = cria_node(aluno);
    }
}

// Imprime árvore caminhamento central

void imprime_central(Node *node){
    if (node == nullptr)
        return;   
    imprime_central(node->left);
    node->aluno.imprimir_dados();
    imprime_central(node->right);
}

void BST::imprimir_arvore(){
    imprime_central(this->root);
}

Aluno* procurar_aluno_helper(int mat, Node *node){
    if (node == nullptr){
        return nullptr;
    }
    else if (node->aluno.get_matricula() == mat){
        return &node->aluno;
    }
    else if (node->aluno.get_matricula() > mat){
        return procurar_aluno_helper(mat, node->left);
    }
    else if (node->aluno.get_matricula() < mat){
        return procurar_aluno_helper(mat,node->right);
    }

    return nullptr;


}

Aluno* BST::procurar_aluno(int mat){
    Aluno *a = procurar_aluno_helper(mat, this->root);
    return a;
}
