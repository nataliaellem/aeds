#include "fila_de_prioridade.h"


typedef struct No {
    string nome;
    int idade;
    struct No *next;
} No;


FilaDePrioridade::FilaDePrioridade(){
    tamanho_ = 0;
    primeiro_ = nullptr;
}

string FilaDePrioridade::primeiro() const {

    if (this->primeiro_ != nullptr){
        return this->primeiro_->nome;
   /*     int maior = primeiro_->idade;
        string first = primeiro_->nome;
        for (No *aux = primeiro_; aux != nullptr; aux = aux->next){
            if (aux->idade > maior){
                maior = aux->idade;
                first = aux->nome;
            }
        }
        return first; */
    } 
    else {
        return "\nFila vazia\n";
    }
}


int FilaDePrioridade::tamanho() const {

    return this->tamanho_;
}


bool FilaDePrioridade::vazia() const {
    if (this->primeiro_ == nullptr){
        return true;
    }
    else {
        return false;
    }
}


void FilaDePrioridade::RemoverPrimeiro(){
    if (this->primeiro_ != nullptr){
        No *aux = this->primeiro_;
        this->primeiro_ = aux->next;
        delete(aux);
    }
}


void FilaDePrioridade::Limpar(){
    for (int i = 0; i <= this->tamanho_; i++){
        this->RemoverPrimeiro();
    }
}



void FilaDePrioridade::Inserir(int p, string s){

    if(this->primeiro_ == nullptr){
        this->primeiro_ = new No();
        this->primeiro_->nome = s;
        this->primeiro_->idade = p;
        this->primeiro_->next = nullptr;
    }
    else {
        No *aux;
        for (aux = this->primeiro_; aux != nullptr; aux = aux->next){
            No *new_no = new No();
            new_no->nome = s;
            new_no->idade = p;
            if (p > aux->idade){
                new_no->next = aux;
                if (aux == this->primeiro_){
                    this->primeiro_ = new_no;
                }
                return;
            }
            else if (aux->next == nullptr && p <= aux->idade){
                aux->next = new_no;
                new_no->next = nullptr;
            }
        }
    }
    this->tamanho_++;
}